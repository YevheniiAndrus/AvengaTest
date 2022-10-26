#pragma once

#include "../common/Metadata.h"

class ExternalDrive{
public:
    ExternalDrive() = default;

    void flushData(const Metadata&);
};