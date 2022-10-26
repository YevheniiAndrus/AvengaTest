#include "ExternalDrive.h"
#include <iostream>

void ExternalDrive::flushData(const Metadata& metadata){
    std::cout << "Metadata with id " << metadata.id << " is stored" << std::endl;
}