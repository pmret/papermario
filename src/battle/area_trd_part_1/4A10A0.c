#include "common.h"

#define NAMESPACE b_area_trd_part_1

typedef struct AreaTrdPart1Struct {
    /* 0x00 */ char unk_00[12];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} AreaTrdPart1Struct;

extern AreaTrdPart1Struct D_8021A4E8_4A3588;

ApiStatus func_80218000_4A10A0(Evt* script, s32 isInitialCall) {
    D_8021A4E8_4A3588.unk_0C = 1;
    D_8021A4E8_4A3588.unk_10 = script->owner1.actorID;

    return ApiStatus_DONE2;
}

#include "common/UnkBattleFunc1.inc.c"
