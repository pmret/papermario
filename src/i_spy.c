#include "common.h"

typedef struct struct802B7C78 {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} struct802B7C78;

#include "i_spy.png.h"
#include "i_spy.png.inc.c"
#include "i_spy.pal.inc.c"
#include "i_spy.2.pal.inc.c"
#include "i_spy.flash.pal.inc.c"
#include "i_spy_dlist.gfx.inc.c"

BSS struct802B7C78 D_802B7CB0;

struct802B7C78* D_802B7C78_E23228 = &D_802B7CB0;

extern void (*ISpyNotificationCallback)(void);

void func_802B735C_E2290C(void);

void func_802B7000_E225B0(void) {
    Matrix4f matrix1;
    Matrix4f matrix2;
    FoldImageRecPart foldImage;
    s32 temp;

    if (gPlayerStatus.animFlags & PA_FLAG_100) {
        guScaleF(matrix1, D_802B7C78_E23228->scale, D_802B7C78_E23228->scale, D_802B7C78_E23228->scale);
        guRotateF(matrix2, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(matrix1, matrix2, matrix1);
        guTranslateF(matrix2, D_802B7C78_E23228->pos.x, D_802B7C78_E23228->pos.y, D_802B7C78_E23228->pos.z);
        guMtxCatF(matrix1, matrix2, matrix2);
        guMtxF2L(matrix2, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], 3);
        gSPDisplayList(gMasterGfxPos++, D_802B7C00_E231B0);

        if (D_802B7C78_E23228->unk_18 < 47) {
            D_802B7C78_E23228->unk_20 += 1;
        }

        temp = D_802B7C78_E23228->unk_20;
        temp = temp - (temp / 12) * 12;
        switch (temp) {
            case 0:
            case 1:
            case 2:
            case 3:
                foldImage.palette = D_802B7BA0_E23150;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                foldImage.palette = D_802B7BC0_E23170;
                break;
            case 8:
            case 9:
            case 10:
            case 11:
                foldImage.palette = D_802B7BE0_E23190;
                break;
        }
        fold_update(0, FOLD_TYPE_7, 0xFF, 0xFF, 0xFF, D_802B7C78_E23228->unk_28, 0);

        foldImage.raster = D_802B7580_E22B30;
        foldImage.width = 56;
        foldImage.height = 56;
        foldImage.xOffset = -28;
        foldImage.yOffset = 46;
        foldImage.opacity = 255;

        fold_appendGfx_component(0, &foldImage, 0, matrix2);
        gSPPopMatrix(gMasterGfxPos++, 0);
    }
}


void func_802B72C0_E22870(void) {
    mem_clear(D_802B7C78_E23228, sizeof(*D_802B7C78_E23228));

    D_802B7C78_E23228->pos.x = gPlayerStatus.position.x;
    D_802B7C78_E23228->pos.y = gPlayerStatus.position.y + gPlayerStatus.colliderHeight + 8.0f;
    D_802B7C78_E23228->pos.z = gPlayerStatus.position.z;

    D_802B7C78_E23228->unk_28 = 0xFF;

    gPlayerStatus.animFlags |= PA_FLAG_100;
    ISpyNotificationCallback = &func_802B735C_E2290C;
}

void func_802B735C_E2290C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s32 cond;

    D_802B7C78_E23228->pos.y +=
        (playerStatus->position.y + playerStatus->colliderHeight + 10.0f - D_802B7C78_E23228->pos.y) / 1.5f;
    D_802B7C78_E23228->pos.x = playerStatus->position.x;
    D_802B7C78_E23228->pos.z = playerStatus->position.z;

    switch (D_802B7C78_E23228->unk_24) {
        case 0:
            if (partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE &&
                partnerActionStatus->actingPartner == PARTNER_LAKILESTER)
            {
                cond = gGameStatusPtr->keepUsingPartnerOnMapChange;
            } else {
                cond = playerStatus->flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION);
            }

            if (!cond) {
                D_802B7C78_E23228->unk_24++;
            }
            break;
        case 1:
            if (playerStatus->flags & PS_FLAG_PAUSED) {
                D_802B7C78_E23228->unk_24 = 3;
                return;
            }

            if (D_802B7C78_E23228->unk_18++ >= 16) {
                D_802B7C78_E23228->scale = 0.36f;
                D_802B7C78_E23228->unk_24++;
            }
            break;
        case 2:
            D_802B7C78_E23228->scale = 0.57f;
            D_802B7C78_E23228->unk_24++;
            sfx_play_sound_at_player(SOUND_17B, SOUND_SPACE_MODE_0);
            break;
        case 3:
            D_802B7C78_E23228->scale = 0.53f;
            if (D_802B7C78_E23228->unk_18 >= 47 || playerStatus->flags & PS_FLAG_PAUSED) {
                D_802B7C78_E23228->unk_28 -= 64;
                if (D_802B7C78_E23228->unk_28 < 0) {
                    D_802B7C78_E23228->unk_28 = 0;
                    D_802B7C78_E23228->unk_18 = 51;
                }
            }

            if (D_802B7C78_E23228->unk_18++ > 50) {
                gCurrentHiddenPanels.activateISpy = FALSE;
                ISpyNotificationCallback = NULL;
                playerStatus->animFlags &= ~PA_FLAG_100;
            }
            break;
    }
}


