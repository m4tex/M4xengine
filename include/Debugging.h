//
// Created by m4tex on 4/17/23.
//

#pragma once

#ifdef _WIN32
#define ASSERT(x) if (!(x)) __debugbreak;
#elif __linux__
#include <csignal>
#define ASSERT(x) if (!(x)) raise(SIGTRAP);
#endif