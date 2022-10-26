#pragma once

#include "../common/Metadata.h"

class MetadataRenderer{
public:
    MetadataRenderer() {}
    virtual ~MetadataRenderer() {}
    virtual void render(const Metadata&) = 0;
};