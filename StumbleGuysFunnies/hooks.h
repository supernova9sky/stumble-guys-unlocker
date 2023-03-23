#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstdint>
#include <conio.h>
bool User__HasSkinHOOK(DWORD* __this, const char* skinID, DWORD* method) {
    if (LOG)
        printf("unlocking_skinId:                0x%I64X\n", skinID);
    return true;
}
bool User__HasVariantHOOK(DWORD* __this, const char* skinID, const char* variantName, int variantID, DWORD* method) {
    if (LOG)
        printf("unlocking_variantId:             0x%I64X for skinId:            0x%I64X\n", variantID, skinID);
    return true;
}
bool User__HasAnimationHOOK(DWORD* __this, const char* animationID, DWORD* method) {
    if (LOG)
        printf("unlocking_animationId:           0x%I64X\n", animationID);
    return true;
}
bool User__HasFootstepHOOK(DWORD* __this, const char* footstepID, DWORD* method) {
    if (LOG)
        printf("unlocking_footstepId:            0x%I64X\n", footstepID);
    return true;
}
bool User__HasEmoteHOOK(DWORD* __this, const char* emoteID, DWORD* method) {
    if (LOG)
        printf("unlocking_emoteId:               0x%I64X\n", emoteID);
    return true;
}