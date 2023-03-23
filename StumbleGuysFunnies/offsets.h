#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstdint>
#include <conio.h>
constexpr uintptr_t HasSkin = 0x15D7390;
constexpr uintptr_t HasVariant = 0x15D7440;
constexpr uintptr_t HasAnimation = 0x15D70C0;
constexpr uintptr_t HasFootstep = 0x15D7300;
constexpr uintptr_t HasEmote = 0x15D71F0;
uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));