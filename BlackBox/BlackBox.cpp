#include "BlackBox.h"
#include <random>
#include <iostream>

namespace {
    int generate_metadata_distribution(int range_start, int range_end) {
        std::random_device device;
        std::mt19937 generator(device());
        std::uniform_int_distribution<> distr(range_start, range_end);
        return distr(generator);
    }
}


Metadata BlackBox::generateMetadataFromFrame(const std::optional<cv::Mat>& frame){
    Metadata metadata;
    metadata.id = m_index++;
    metadata.box.center_x = generate_metadata_distribution(0, 1000);
    metadata.box.center_y = generate_metadata_distribution(0, 1000);
    metadata.box.width    = generate_metadata_distribution(0, 1000);
    metadata.box.height   = generate_metadata_distribution(0, 1000);
    std::cout << "Generated metadata with id " << metadata.id << std::endl;
    return metadata;
}