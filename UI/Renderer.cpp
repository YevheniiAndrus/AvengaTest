#include "Renderer.h"

Renderer::Renderer(std::unique_ptr<MetadataRenderer> ptr){
    pImpl = std::move(ptr);
}

void Renderer::render(const Metadata& metadata){
    pImpl->render(metadata);
}