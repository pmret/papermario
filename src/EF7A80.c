#include "dead.h"
#include "common.h"

#define NAMESPACE EF7A80

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

#include "common/DeadUnk1.inc.c"

// Copy from flo_18
typedef struct unk_effect {
    char unk_00[0x30];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    char unk_3C[0x4];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
} unk_effect;

typedef struct temp {
    char unk_00[0xC];
    unk_effect* unk_0C;
} temp;

ApiStatus func_80240340_EF7DC0(Evt* script, s32 isInitialCall) {
    temp* ptr = script->varTable[15];

    ptr->unk_0C->unk_30 = 69;
    ptr->unk_0C->unk_34 = 255;
    ptr->unk_0C->unk_38 = 217;
    ptr->unk_0C->unk_40 = 176;
    ptr->unk_0C->unk_44 = 254;
    ptr->unk_0C->unk_48 = 124;
    return ApiStatus_DONE2;
}

#include "common/DeadUnkFloatFunc.inc.c"
