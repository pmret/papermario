#include "common.h"

#define NAMESPACE E20110

typedef struct TempE20110 {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x4];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s8 unk_20;
    /* 0x21 */ s8 unk_21;
    /* 0x22 */ s8 unk_22;
    /* 0x23 */ s8 unk_23;
    /* 0x24 */ s32 unk_24;
} TempE20110; // size = 0x28

BSS TempE20110 D_802B7DA0;

#include "inspect_icon.png.h"
#include "inspect_icon.png.inc.c"
#include "inspect_icon.pal.inc.c"
#include "inspect_icon_dlist.gfx.inc.c"

TempE20110* D_802B7CB8_E20DC8 = &D_802B7DA0;

#include "common/UnkAngleFunc1.inc.c"

void func_802B7728_E20838(void);

// floatz
#ifdef NON_MATCHING
void func_802B70B4_E201C4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 new_var;

    if (playerStatus->animFlags & 0x10) {
        mem_clear(D_802B7CB8_E20DC8, sizeof(*D_802B7CB8_E20DC8));
        D_8010C950 = -1;
        D_802B7CB8_E20DC8->unk_00.x = playerStatus->position.x;
        new_var = playerStatus->position.y + playerStatus->colliderHeight;
        if (!(playerStatus->animFlags & 0x1000)) {
            D_802B7CB8_E20DC8->unk_00.y = new_var + 8.0f;
        } else {
            D_802B7CB8_E20DC8->unk_00.y = new_var + 2.0f;
        }
        D_802B7CB8_E20DC8->unk_00.z = playerStatus->position.z;
        D_802B7CB8_E20DC8->unk_10 = 0.4f;
        D_802B7CB8_E20DC8->unk_23 = 0;
        D_802B7CB8_E20DC8->unk_0C = -gCameras[gCurrentCameraID].currentYaw;
        D_8010C958 = func_802B7728_E20838;
        D_802B7CB8_E20DC8->unk_24 = 0xFF;
        D_802B7CB8_E20DC8->unk_1C = 0xFF;
    }
}
#else
INCLUDE_ASM(s32, "E20110", func_802B70B4_E201C4);
#endif

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

    delta = (playerStatus->position.x - D_802B7CB8_E20DC8->pos.x) * 0.666f;
    D_802B7CB8_E20DC8->pos.x += delta;
    delta = (playerStatus->position.z - D_802B7CB8_E20DC8->pos.z) * 0.666f;
    D_802B7CB8_E20DC8->pos.z += delta;

    yTemp = playerStatus->position.y + playerStatus->colliderHeight;
    unk_21 = D_802B7CB8_E20DC8->unk_21;
    y = D_802B7CB8_E20DC8->pos.y;
    if (!(playerStatus->animFlags & 0x1000)) {
        delta = (yTemp + 8.0f + unk_21 - y) * 0.25f;
    } else {
        delta = (yTemp + 2.0f + unk_21 - y) * 0.25f;
    }
    D_802B7CB8_E20DC8->pos.y += delta;
}

INCLUDE_ASM(s32, "E20110", func_802B7728_E20838);

void func_802B79C8_E20AD8(void) {
    func_802B75E8_E206F8();
    gPlayerStatusPtr->interactingWithID = -1;
    D_8010C958 = 0;
    gPlayerStatusPtr->encounteredNPC = NULL;
    gPlayerStatusPtr->animFlags &= ~0x10;
    func_800EF3D4(0);
    repartner_set_tether_distance();
}
