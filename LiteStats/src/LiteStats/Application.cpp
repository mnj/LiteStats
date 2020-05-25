#include "lspch.h"

#include "Application.h"

#include "LiteStats/Log.h"

namespace LiteStats {

    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        using namespace std::chrono_literals;

        while (true)
        {
            std::this_thread::sleep_for(250ms);
        }
    }
}
