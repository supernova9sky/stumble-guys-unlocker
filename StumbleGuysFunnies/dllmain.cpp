// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#define LOG true
#include <MinHook.h>
#include <Windows.h>
#include <cstdio>
#include <cstdint>
#include <conio.h>
#include "offsets.h"
#include "trampolines.h"
#include "hooks.h"

class Hooker 
{
public:

    Hooker(HMODULE module) {
        mod = module;
        if (LOG) {
            AllocConsole();
            freopen_s(&f, "CONOUT$", "w", stdout);
        }
        MH_Initialize();
        createHooks();
        enableHooks();
    }
    ~Hooker() {
        if (LOG) {
            FreeConsole();
            fclose(f);
        }
        FreeLibraryAndExitThread(mod, 0);
    }
private:
    void createHooks() {
        if (LOG)
            printf("[+] Making hooks! \n");
        // Im not creating a vector for this cause its only 5 hooks
        MH_CreateHook(reinterpret_cast<LPVOID*>(base + HasSkin), &User__HasSkinHOOK, reinterpret_cast<LPVOID*>(User__HasSkinORIG));
        MH_CreateHook(reinterpret_cast<LPVOID*>(base + HasVariant), &User__HasVariantHOOK, reinterpret_cast<LPVOID*>(User__HasVariantORIG));
        MH_CreateHook(reinterpret_cast<LPVOID*>(base + HasAnimation), &User__HasAnimationHOOK, reinterpret_cast<LPVOID*>(User__HasAnimationORIG));
        MH_CreateHook(reinterpret_cast<LPVOID*>(base + HasFootstep), &User__HasFootstepHOOK, reinterpret_cast<LPVOID*>(User__HasFootstepORIG));
        MH_CreateHook(reinterpret_cast<LPVOID*>(base + HasEmote), &User__HasEmoteHOOK, reinterpret_cast<LPVOID*>(User__HasEmoteORIG));
    }

    void enableHooks() {
        if (LOG)
            printf("[+] Enabling hooks. \n");
        MH_EnableHook(MH_ALL_HOOKS);
    }

    void removeHooks() {
        if (LOG)
            printf("[+] Removing hooks. \n");
        MH_RemoveHook(reinterpret_cast<LPVOID*>(base + HasSkin));
        MH_RemoveHook(reinterpret_cast<LPVOID*>(base + HasVariant));
        MH_RemoveHook(reinterpret_cast<LPVOID*>(base + HasAnimation));
        MH_RemoveHook(reinterpret_cast<LPVOID*>(base + HasFootstep));
        MH_RemoveHook(reinterpret_cast<LPVOID*>(base + HasEmote));
    }

    void disableHooks() {
        MH_DisableHook(MH_ALL_HOOKS);
    }
    FILE* f;
    HMODULE mod;
};

void main(HMODULE mod) {
    Hooker* hooker = new Hooker(mod);
    if (LOG) {
        printf("[+] Hooks should be placed. \n");
        printf("[+] Click end to unhook all. \n");
    }
    while (true) {
        if (GetAsyncKeyState(VK_END) & 1) {
            delete hooker;
            break;
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CloseHandle(CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), hModule, 0, 0));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

