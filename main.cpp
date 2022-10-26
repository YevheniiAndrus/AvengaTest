#include <iostream>
#include "Interactor.h"
#include "FrameLoader/FrameLoaderFactory.h"
#include "UI/BoxRenderer.h"

int main(){
    // create frame loader instance
    const std::string filePath("/Users/yevheniiandrus/avenga_test/test_video.mp4");
    std::unique_ptr<IFrameLoader> loader = FrameLoaderFactory::get()->makeFrameLoader(filePath);

    // create black box object which represents algorithm of franme handling
    // and generating metadata from it
    std::unique_ptr<BlackBox> blackBox = std::make_unique<BlackBox>();

    // create UI renderer to visualize metadata info
    std::unique_ptr<MetadataRenderer> box_renderer(new BoxRenderer());
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(std::move(box_renderer));

    // create external device instance to flush metadata
    std::unique_ptr<ExternalDrive> drive = std::make_unique<ExternalDrive>();

    // create Interactor instance to orchestrate all stuff abocve
    Interactor interactor(std::move(loader),
                          std::move(blackBox),
                          std::move(renderer),
                          std::move(drive));
    interactor.run();

    return 0;
}