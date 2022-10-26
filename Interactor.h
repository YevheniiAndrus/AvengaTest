#pragma once

#include <memory>
#include <mutex>
#include "FrameLoader/IFrameLoader.h"
#include "BlackBox/BlackBox.h"
#include "UI/Renderer.h"
#include "ExternalDrive/ExternalDrive.h"


class Interactor{
public:
    explicit Interactor(std::unique_ptr<IFrameLoader>,
                        std::unique_ptr<BlackBox>,
                        std::unique_ptr<Renderer>,
                        std::unique_ptr<ExternalDrive>);

    void run();

private:
    std::unique_ptr<IFrameLoader> m_frameLoader;
    std::unique_ptr<BlackBox> m_blackBox;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<ExternalDrive> m_externalDrive;

    mutable std::mutex m_mutex;
};