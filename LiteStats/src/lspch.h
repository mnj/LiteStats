#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <functional>

#include <chrono>
#include <thread>

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "asio.hpp"

#ifdef LS_PLATFORM_WINDOWS
    #include <Windows.h>
#endif
