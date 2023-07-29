#include "common.h"

typedef struct ISpyNotification {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ char unk_10[8];
    /* 0x18 */ s32 time;
    /* 0x1C */ char unk_1C[4];
    /* 0x20 */ s32 flashCount;
    /* 0x24 */ s32 state;
    /* 0x28 */ s32 alpha;
} ISpyNotification;

enum {
    I_SPY_DELAY         = 0, // icon waits to appear when entering map under certain conditions
    I_SPY_APPEAR        = 1, // icon appears
    I_SPY_OVERSHOOT     = 2, // icon scale overshoots before it begins animating
    I_SPY_ANIMATE       = 3, // icon blinks for a second and a half and then vanishes
};

#include "ispy_icon.png.h"
#include "ispy_icon.png.inc.c"
#include "ispy_icon.pal.inc.c"
#include "ispy_icon.2.pal.inc.c"
#include "ispy_icon.3.pal.inc.c"
#include "ispy_icon.gfx.inc.c"

BSS ISpyNotification ISpyData;
ISpyNotification* ISpyPtr = &ISpyData;

void ispy_notification_update(void);

void appendGfx_ispy_icon(void) {
    Matrix4f matrix1;
    Matrix4f matrix2;
    ImgFXTexture ifxImg;
    s32 flashPhase;

    if (gPlayerStatus.animFlags & PA_FLAG_ISPY_VISIBLE) {
        guScaleF(matrix1, ISpyPtr->scale, ISpyPtr->scale, ISpyPtr->scale);
        guRotateF(matrix2, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(matrix1, matrix2, matrix1);
        guTranslateF(matrix2, ISpyPtr->pos.x, ISpyPtr->pos.y, ISpyPtr->pos.z);
        guMtxCatF(matrix1, matrix2, matrix2);
        guMtxF2L(matrix2, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], 3);
        gSPDisplayList(gMainGfxPos++, ispy_icon_gfx);

        if (ISpyPtr->time < 47) {
            ISpyPtr->flashCount++;
        }

        flashPhase = ISpyPtr->flashCount;
        flashPhase = flashPhase % 12;
        switch (flashPhase) {
            case 0:
            case 1:
            case 2:
            case 3:
                ifxImg.palette = ispy_icon_1_pal;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
                ifxImg.palette = ispy_icon_2_pal;
                break;
            case 8:
            case 9:
            case 10:
            case 11:
                ifxImg.palette = ispy_icon_3_pal;
                break;
        }
        imgfx_update(0, IMGFX_SET_ALPHA, 255, 255, 255, ISpyPtr->alpha, 0);

        ifxImg.raster = ispy_icon_img;
        ifxImg.width  = ispy_icon_img_width;
        ifxImg.height = ispy_icon_img_height;
        ifxImg.xOffset = -28;
        ifxImg.yOffset = 46;
        ifxImg.alpha = 255;

        imgfx_appendGfx_component(0, &ifxImg, 0, matrix2);
        gSPPopMatrix(gMainGfxPos++, 0);
    }
}

void ispy_notification_setup(void) {
    mem_clear(ISpyPtr, sizeof(*ISpyPtr));

    ISpyPtr->pos.x = gPlayerStatus.pos.x;
    ISpyPtr->pos.y = gPlayerStatus.pos.y + gPlayerStatus.colliderHeight + 8.0f;
    ISpyPtr->pos.z = gPlayerStatus.pos.z;

    ISpyPtr->alpha = 255;

    gPlayerStatus.animFlags |= PA_FLAG_ISPY_VISIBLE;
    ISpyNotificationCallback = &ispy_notification_update;
}

void ispy_notification_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    s32 cond;

    ISpyPtr->pos.y +=
        (playerStatus->pos.y + playerStatus->colliderHeight + 10.0f - ISpyPtr->pos.y) / 1.5f;
    ISpyPtr->pos.x = playerStatus->pos.x;
    ISpyPtr->pos.z = playerStatus->pos.z;

    switch (ISpyPtr->state) {
        case I_SPY_DELAY:
            if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE
             && partnerStatus->actingPartner == PARTNER_LAKILESTER
            ) {
                cond = gGameStatusPtr->keepUsingPartnerOnMapChange;
            } else {
                cond = playerStatus->flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION);
            }

            if (!cond) {
                ISpyPtr->state++;
            }
            break;
        case I_SPY_APPEAR:
            if (playerStatus->flags & PS_FLAG_PAUSED) {
                ISpyPtr->state = I_SPY_ANIMATE;
                return;
            }

            if (ISpyPtr->time++ >= 16) {
                ISpyPtr->scale = 0.36f;
                ISpyPtr->state++;
            }
            break;
        case I_SPY_OVERSHOOT:
            ISpyPtr->scale = 0.57f;
            ISpyPtr->state++;
            sfx_play_sound_at_player(SOUND_17B, SOUND_SPACE_MODE_0);
            break;
        case I_SPY_ANIMATE:
            ISpyPtr->scale = 0.53f;
            if (ISpyPtr->time >= 47 || playerStatus->flags & PS_FLAG_PAUSED) {
                ISpyPtr->alpha -= 64;
                if (ISpyPtr->alpha < 0) {
                    ISpyPtr->alpha = 0;
                    ISpyPtr->time = 51;
                }
            }

            if (ISpyPtr->time++ > 50) {
                gCurrentHiddenPanels.activateISpy = FALSE;
                ISpyNotificationCallback = NULL;
                playerStatus->animFlags &= ~PA_FLAG_ISPY_VISIBLE;
            }
            break;
    }
}


