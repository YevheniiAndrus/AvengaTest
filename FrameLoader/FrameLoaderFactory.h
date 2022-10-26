#pragma once

#include "IFrameLoader.h"
#include <memory>
#include <string>

class FrameLoaderFactory{
public:
    FrameLoaderFactory(const FrameLoaderFactory&) = delete;
    FrameLoaderFactory& operator=(const FrameLoaderFactory&) = delete;
    FrameLoaderFactory(FrameLoaderFactory&&) = delete;
    FrameLoaderFactory& operator=(FrameLoaderFactory&&) = delete;
    ~FrameLoaderFactory() {};

    static std::unique_ptr<FrameLoaderFactory> get();
    std::unique_ptr<IFrameLoader> makeFrameLoader(const std::string&);

private:
    FrameLoaderFactory() = default;
    static std::unique_ptr<FrameLoaderFactory> m_instance;
};