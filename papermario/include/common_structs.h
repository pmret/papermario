#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "ultra64.h"

typedef struct {
    /* 0x00 */ char unk_00[0x68];
    /* 0x68 */ u16 demoButtonInput;
    /* 0x6A */ s8 demoStickX;
    /* 0x6B */ s8 demoStickY;
    /* 0x6C */ char unk_6C[0x5];
    /* 0x71 */ s8 demoState;
    /* 0x72 */ char unk_72[8];
    /* 0x7A */ s8 audio_unk;
} game_status;

typedef struct {
    /* 0x0C */ char unk_00[0xC];
    /* 0x0C */ s32* ptrReadPos;
} ScriptContext;

#endif
