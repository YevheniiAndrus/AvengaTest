#include "BoxRenderer.h"
#include <iostream>

void BoxRenderer::render(const Metadata& metadata){
    std::cout << "Rendering of metadata with id " << metadata.id << std::endl;
}