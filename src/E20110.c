#include "common.h"

#define NAMESPACE E20110

typedef struct TempE20110 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ char unk_0C[0x14];
    /* 0x20 */ char unk_20[0x1];
    /* 0x21 */ s8 unk_21;
    /* 0x22 */ s8 unk_22;
} TempE20110;

extern TempE20110* D_802B7CB8_E20DC8;

#include "common/UnkAngleFunc1.inc.c"

INCLUDE_ASM(s32, "E20110", func_802B70B4_E201C4);

INCLUDE_ASM(s32, "E20110", func_802B71E8_E202F8);

INCLUDE_ASM(s32, "E20110", func_802B7450_E20560);

void func_802B75E8_E206F8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 unk_21;
    f32 yTemp;
    f32 y;
    f32 delta;

    D_802B7CB8_E20DC8->unk_21 += D_802B7CB8_E20DC8->unk_22;

    if (D_802B7CB8_E20DC8->unk_21 > 4) {
        D_802B7CB8_E20DC8->unk_22 = -1;
        D_802B7CB8_E20DC8->unk_21 = 4;
    }
    if (D_802B7CB8_E20DC8->unk_21 < -4) {
        D_802B7CB8_E20DC8->unk_22 = 1;
        D_802B7CB8_E20DC8->unk_21 = -4;
    }

    delta = (playerStatus->position.x - D_802B7CB8_E20DC8->unk_00.x) * 0.666f;
    D_802B7CB8_E20DC8->unk_00.x += delta;
    delta = (playerStatus->position.z - D_802B7CB8_E20DC8->unk_00.z) * 0.666f;
    D_802B7CB8_E20DC8->unk_00.z += delta;

    yTemp = playerStatus->position.y + playerStatus->colliderHeight;
    unk_21 = D_802B7CB8_E20DC8->unk_21;
    y = D_802B7CB8_E20DC8->unk_00.y;
    if (!(playerStatus->animFlags & 0x1000)) {
        delta = (yTemp + 8.0f + unk_21 - y) * 0.25f;
    } else {
        delta = (yTemp + 2.0f + unk_21 - y) * 0.25f;
    }
    D_802B7CB8_E20DC8->unk_00.y += delta;
}

INCLUDE_ASM(s32, "E20110", func_802B7728_E20838);

void func_802B79C8_E20AD8(void) {
    func_802B75E8_E206F8();
    gPlayerStatusPtr->unk_C6 = -1;
    D_8010C958 = 0;
    gPlayerStatusPtr->unk_C8 = NULL;
    gPlayerStatusPtr->animFlags &= ~0x10;
    func_800EF3D4(0);
    repartner_set_tether_distance();
}
