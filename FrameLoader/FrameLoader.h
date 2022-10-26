#pragma once

#include "IFrameLoader.h"
#include <string>

class FrameLoader : public IFrameLoader{
public:
    FrameLoader(const std::string& fileName);
    std::optional<cv::Mat> getNextFrame() override;

private:
    int m_index{0};
};