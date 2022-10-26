#pragma once

#include <opencv2/opencv.hpp>
#include "../common/Metadata.h"
#include <optional>

class BlackBox{
public:
    BlackBox() = default;

    Metadata generateMetadataFromFrame(const std::optional<cv::Mat>&);

private:
    int m_index = 0;
};