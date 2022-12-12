#include "common.h"

#define NAMESPACE E20110

typedef struct TempE20110 {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s8 unk_20;
    /* 0x21 */ s8 unk_21;
    /* 0x22 */ s8 unk_22;
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ char unk_25[0x3];
} TempE20110; // size = 0x28

BSS TempE20110 D_802B7DA0;

#include "inspect_icon.png.h"
#include "inspect_icon.png.inc.c"
#include "inspect_icon.pal.inc.c"
#include "inspect_icon_dlist.gfx.inc.c"

TempE20110* D_802B7CB8_E20DC8 = &D_802B7DA0;

#include "common/UnkAngleFunc1.inc.c"

void func_802B7728_E20838(void);
void func_802B79C8_E20AD8(void);

void func_802B70B4_E201C4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 new_var;

    if (playerStatus->animFlags & 0x10) {
        mem_clear(D_802B7CB8_E20DC8, sizeof(*D_802B7CB8_E20DC8));
        D_8010C950 = -1;
        D_802B7CB8_E20DC8->pos.x = playerStatus->position.x;
        D_802B7CB8_E20DC8->pos.y = playerStatus->position.y + playerStatus->colliderHeight +
                                   (!(playerStatus->animFlags & 0x1000) ? 8.0f : 2.0f);
        D_802B7CB8_E20DC8->pos.z = playerStatus->position.z;
        D_802B7CB8_E20DC8->scale = 0.4f;
        D_802B7CB8_E20DC8->unk_23 = 0;
        D_802B7CB8_E20DC8->unk_0C = -gCameras[gCurrentCameraID].currentYaw;
        D_8010C958 = func_802B7728_E20838;
        D_802B7CB8_E20DC8->unk_24 = 0xFF;
        D_802B7CB8_E20DC8->unk_1C = 0xFF;
    }
}

void func_802B71E8_E202F8(void) {
    FoldImageRecPart sp20;
    Matrix4f sp38, sp78;

    if (gPlayerStatus.animFlags & PA_FLAGS_INTERACT_PROMPT_AVAILABLE) {
        guScaleF(sp38, D_802B7CB8_E20DC8->scale, D_802B7CB8_E20DC8->scale, D_802B7CB8_E20DC8->scale);
        guRotateF(sp78, D_802B7CB8_E20DC8->unk_0C - gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp38, sp78, sp38);
        guTranslateF(sp78, D_802B7CB8_E20DC8->pos.x, D_802B7CB8_E20DC8->pos.y, D_802B7CB8_E20DC8->pos.z);
        guMtxCatF(sp38, sp78, sp78);
        guMtxF2L(sp78, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, &D_802B7C40_E20D50);

        sp20.raster = D_802B7A20_E20B30;
        sp20.palette = D_802B7C20_E20D30;
        sp20.width = D_802B7A20_E20B30_width;
        sp20.height = D_802B7A20_E20B30_height;
        sp20.xOffset = -16;
        sp20.yOffset = 26;
        sp20.opacity = 255;
        fold_update(0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0x440);
        fold_update(0, FOLD_TYPE_6,
                    D_802B7CB8_E20DC8->unk_24, D_802B7CB8_E20DC8->unk_24, D_802B7CB8_E20DC8->unk_24, 0xFF, 0x448);
        fold_appendGfx_component(0, &sp20, 0, sp78);

        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
}

s32 func_802B7450_E20560(void);
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
    if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
        delta = (yTemp + 8.0f + unk_21 - y) * 0.25f;
    } else {
        delta = (yTemp + 2.0f + unk_21 - y) * 0.25f;
    }
    D_802B7CB8_E20DC8->pos.y += delta;
}

void func_802B7728_E20838(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 var_s0 = 0xFF;
    f32 scale;
    s32 actionState;

    func_802B75E8_E206F8();

    switch (D_802B7CB8_E20DC8->unk_23) {
        case 0:
            D_802B7CB8_E20DC8->unk_0C = 0.0f;
            D_802B7CB8_E20DC8->scale += 0.05;
            if (D_802B7CB8_E20DC8->scale >= 0.55) {
                D_802B7CB8_E20DC8->scale = 0.55f;
                D_802B7CB8_E20DC8->unk_23++;
                D_802B7CB8_E20DC8->unk_14 = 12;
            }
            break;
        case 1:
            D_802B7CB8_E20DC8->unk_0C = 0.0f;
            D_802B7CB8_E20DC8->unk_14--;
            if (D_802B7CB8_E20DC8->unk_14 <= 0) {
                D_802B7CB8_E20DC8->unk_23++;
            }
            break;
        case 2:
            scale = D_802B7CB8_E20DC8->unk_0C;
            scale += 10.0f;
            if (scale >= 360.0f) {
                scale -= 360.0f;
            }
            D_802B7CB8_E20DC8->unk_0C = scale;
            var_s0 = E20110_UnkAngleFunc1(scale);
            break;
        case 3:
            scale = D_802B7CB8_E20DC8->unk_0C;
            scale += 25.0f;
            if (scale >= 360.0f) {
                scale -= 360.0f;
            }
            D_802B7CB8_E20DC8->unk_0C = scale;
            D_802B7CB8_E20DC8->unk_1C -= 25;
            if (D_802B7CB8_E20DC8->unk_1C < 0) {
                D_802B7CB8_E20DC8->unk_1C = 0;
            }
            if ((scale >= 70.0f && scale <= 110.0f) || (scale >= 250.0f && scale <= 290.0f)) {
                D_8010C958 = func_802B79C8_E20AD8;
            }
            var_s0 = E20110_UnkAngleFunc1(scale);
            break;
    }
    D_802B7CB8_E20DC8->unk_24 = var_s0;

    actionState = playerStatus->actionState;
    if ((func_802B7450_E20560() == 0) ||
        (playerStatus->inputEnabledCounter != 0) ||
        (playerStatus->flags & PS_FLAGS_PAUSED) ||
        !(actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN))
    {
        D_802B7CB8_E20DC8->unk_23 = 3;
    }

    if ((playerStatus->interactingWithID >= 0) &&
        (playerStatus->interactingWithID & 0x4000) &&
        !(get_entity_by_index(playerStatus->interactingWithID)->flags & ENTITY_FLAGS_SHOWS_INSPECT_PROMPT))
    {
        D_802B7CB8_E20DC8->unk_23 = 3;
    }
}

void func_802B79C8_E20AD8(void) {
    func_802B75E8_E206F8();
    gPlayerStatusPtr->interactingWithID = -1;
    D_8010C958 = 0;
    gPlayerStatusPtr->encounteredNPC = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAGS_INTERACT_PROMPT_AVAILABLE;
    func_800EF3D4(0);
    partner_reset_tether_distance();
}
