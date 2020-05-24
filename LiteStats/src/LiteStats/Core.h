#pragma once

#ifdef LS_PLATFORM_WINDOWS
    #ifdef LS_BUILD_DLL
        #define LS_API __declspec(dllexport)
    #else
        #define LS_API __declspec(dllimport)
    #endif
#else
    #error LiteStats currently only support one platform (Windows)
#endif
