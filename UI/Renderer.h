#pragma once

#include "../common/Metadata.h"
#include "MetadataRenderer.h"
#include <memory>

class Renderer{
public:
    Renderer(std::unique_ptr<MetadataRenderer>);

    void render(const Metadata&);

private:
    std::unique_ptr<MetadataRenderer> pImpl;
};