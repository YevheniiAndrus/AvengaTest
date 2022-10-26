#include "Interactor.h"
#include <iostream>
#include <boost/signals2.hpp>
#include <thread>
#include <vector>

Interactor::Interactor(std::unique_ptr<IFrameLoader> frameLoader,
                       std::unique_ptr<BlackBox> blackBox,
                       std::unique_ptr<Renderer> renderer,
                       std::unique_ptr<ExternalDrive> externalDrive) :
                       m_frameLoader(std::move(frameLoader)),
                       m_blackBox(std::move(blackBox)),
                       m_renderer(std::move(renderer)),
                       m_externalDrive(std::move(externalDrive)) {}

void Interactor::run(){
    std::cout << "Start execution..." << std::endl;

    // pub/sub using boost signals since they are thread safe
    boost::signals2::signal<Metadata(std::optional<cv::Mat>)> s1;
    s1.connect(std::bind(&BlackBox::generateMetadataFromFrame, m_blackBox.get(),
        std::placeholders::_1));

    boost::signals2::signal<void(const Metadata&)> s2;
    s2.connect(std::bind(&Renderer::render, m_renderer.get(),
        std::placeholders::_1));

    s2.connect(std::bind(&ExternalDrive::flushData, m_externalDrive.get(),
        std::placeholders::_1));

    auto worker = [this, &s1, &s2](std::optional<cv::Mat> nextFrame){
        std::lock_guard<std::mutex> lock{this->m_mutex};
        auto gen_metadata = *s1(nextFrame);
        s2(gen_metadata);
    };

    std::optional<cv::Mat> nextFrame;
    std::vector<std::thread> threads; 
    while((nextFrame = m_frameLoader->getNextFrame())){
        std::thread t([&worker, nextFrame]{
            worker(nextFrame);
        });
        threads.push_back(std::move(t));
    }

    for(auto& t : threads) t.join();
}