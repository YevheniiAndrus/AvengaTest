#include "FrameLoader.h"

FrameLoader::FrameLoader(const std::string& fileName) : 
    IFrameLoader(fileName) {}

std::optional<cv::Mat> FrameLoader::getNextFrame(){
    static cv::VideoCapture cap(m_fileName);
    cv::Mat nextFrame;
    bool result = cap.read(nextFrame);
    if(result){
        return std::optional<cv::Mat>(nextFrame);
    }

    return std::nullopt;
}