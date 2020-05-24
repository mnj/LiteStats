#pragma once

#ifdef LS_PLATFORM_WINDOWS
    #ifdef LS_BUILD_DLL
        #define LS_API __declspec(dllexport)
    #else
        #define LS_API __declspec(dllimport)
    #endif
#elif defined(LS_PLATFORM_LINUX) && defined(__GNUC__)
    #ifdef LS_BUILD_SO
        #define LS_API __attribute__((visibility("default")))
    #else
        #define LS_API
    #endif
#else
    #error LiteStats currently only support one platform (Windows)
#endif