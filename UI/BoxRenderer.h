#pragma once

#include "MetadataRenderer.h"

class BoxRenderer : public MetadataRenderer{
public:
    BoxRenderer() = default;
    ~BoxRenderer() {}
    void render(const Metadata&) override;
};