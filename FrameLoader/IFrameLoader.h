#pragma once

#include <string>
#include <opencv2/opencv.hpp>
#include <optional>

class IFrameLoader{
public:
    IFrameLoader(const std::string& fileName){
        m_fileName = fileName;
    }
    virtual ~IFrameLoader() {}
    virtual std::optional<cv::Mat> getNextFrame() = 0;

protected:
    std::string m_fileName;
};