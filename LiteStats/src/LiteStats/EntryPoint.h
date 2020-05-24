#pragma once

#if defined(LS_PLATFORM_WINDOWS) || defined(LS_PLATFORM_LINUX)

extern LiteStats::Application* LiteStats::CreateApplication();

int main(int argc, char** argv)
{
    auto app = LiteStats::CreateApplication();
    app->Run();
    delete app;
}
#endif
