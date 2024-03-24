#define NO_EXTERN_VARIABLES
#include "common.h"
#include "model.h"
#include "overlay.h"
// DON'T DARE to put include headers here containing extern declarations...
// This will ruin the ordering of bss symbols below if you care about matching.

#ifndef SHIFT

// from audio/ambience.c
typedef struct {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 fadeState;
    /* 0x4 */ s32 fadeTime;
    /* 0x8 */ s32 soundID;
    /* 0xC */ s32 unkC;
} AmbientSoundSettings;

BSS MusicSettings gMusicSettings[2];
BSS IMG_BIN D_80159B50[0x200];
BSS Window gWindows[64];
BSS CollisionStatus gCollisionStatus;
BSS HiddenPanelsData gCurrentHiddenPanels;
BSS s32 _PLS_NAME_ME[2];
BSS TextureHandle TextureHandles[128];
BSS ScreenOverlay ScreenOverlays[2];
BSS AmbientSoundSettings AmbientSoundData;
BSS s32 CreateEntityVarArgBuffer[4];
BSS PAL_BIN D_8015C7E0[0x10];
#if VERSION_IQUE
BSS char D_8015C800[0x3C80];
#elif VERSION_JP
BSS char D_8015C800[0x2880];
#else
BSS char D_8015C800[0x7800];
#endif
BSS DisplayContext D_80164000[2];

#endif
