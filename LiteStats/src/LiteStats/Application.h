#pragma once

#include "Core.h"

namespace LiteStats {
    class LiteStats LS_API Application
    {
        public:
            Application();
            virtual ~Application();

            void Run();

    };

    Application* CreateApplication();
}
