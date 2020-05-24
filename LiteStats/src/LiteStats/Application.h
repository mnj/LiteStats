#pragma once

#include "Core.h"

namespace LiteStats {
    class LS_API Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

    };

    Application* CreateApplication();
}
