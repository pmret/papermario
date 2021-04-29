#include "flo_07.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

#include "world/common/SpawnSunEffect.inc.c"

typedef struct N(unk_effect) {
    char unk_00[0x38];
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    char unk_44[0x4];
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
} N(unk_effect);

typedef struct N(temp) {
    char unk_00[0xC];
    N(unk_effect)* unk_0C;
} N(temp);

ApiStatus N(func_80240344_CAC534)(ScriptInstance* script, s32 isInitialCall) {
    N(temp)* effect = func_80072350(3, -272.0f, 80.0f, 20.0f, 200.0f, 120.0f, 4.0f, 8, 0);

    effect->unk_0C->unk_38 = 0xF0;
    effect->unk_0C->unk_3C = 0xF0;
    effect->unk_0C->unk_40 = 0xF0;
    effect->unk_0C->unk_48 = 0xE6;
    effect->unk_0C->unk_4C = 0xE6;
    effect->unk_0C->unk_50 = 0xF0;
    return ApiStatus_DONE2;
}
