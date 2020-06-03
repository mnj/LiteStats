workspace "LiteStats"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LiteStats"
    location "LiteStats"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    pchheader "lspch.h"
    pchsource "LiteStats/src/lspch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "3rdparty/spdlog/include",
        "3rdparty/asio/asio/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LS_PLATFORM_WINDOWS",
            "LS_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/LiteStatsSvc" )
        }

        flags
        {
            "MultiProcessorCompile"
        }

    filter "system:linux"

        links
        {
            "pthread"
        }

        defines
        {
            "LS_PLATFORM_LINUX",
            "LS_BUILD_SO"
        }

    filter "configurations:Debug"
        defines "LS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "LS_DIST"
        optimize "On"

project "LiteStatsSvc"
    location "LiteStatsSvc"
    kind "ConsoleApp"

    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "3rdparty/spdlog/include",
        "LiteStats/src"
    }

    links
    {
        "LiteStats"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LS_PLATFORM_WINDOWS"
        }

        flags
        {
            "MultiProcessorCompile"
        }

    filter "system:linux"

        defines
        {
            "LS_PLATFORM_LINUX"
        }

    filter "configurations:Debug"
        defines "LS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "LS_DIST"
        optimize "On"
