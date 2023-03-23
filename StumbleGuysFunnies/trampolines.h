#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstdint>
#include <conio.h>
bool(__fastcall* User__HasSkinORIG)(DWORD*, const char*, DWORD*);
bool(__fastcall* User__HasVariantORIG)(DWORD*, const char*, const char*, int, DWORD*);
bool(__fastcall* User__HasAnimationORIG)(DWORD*, const char*, DWORD*);
bool(__fastcall* User__HasFootstepORIG)(DWORD*, const char*, DWORD*);
bool(__fastcall* User__HasEmoteORIG)(DWORD*, const char*, DWORD*);