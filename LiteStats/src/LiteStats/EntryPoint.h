#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern LiteStats::Application* LiteStats::CreateApplication();

int main(int argc, char** argv)
{
    auto app = LiteStats::CreateApplication();
    app->run();
    delete app;
}

#endif
