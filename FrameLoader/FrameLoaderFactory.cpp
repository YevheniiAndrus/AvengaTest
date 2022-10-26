#include "FrameLoaderFactory.h"
#include "FrameLoader.h"

std::unique_ptr<FrameLoaderFactory> FrameLoaderFactory::m_instance = nullptr;

std::unique_ptr<FrameLoaderFactory> FrameLoaderFactory::get(){
    if(m_instance){
        return std::move(m_instance);
    }

    m_instance.reset(new FrameLoaderFactory());
    return std::move(m_instance);
}

std::unique_ptr<IFrameLoader> FrameLoaderFactory::makeFrameLoader(const std::string& fileName){
    std::unique_ptr<IFrameLoader> ptr;
    ptr.reset(new FrameLoader(fileName));
    return std::move(ptr);
}