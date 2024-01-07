#include "common.h"
#include "include_asset.h"

typedef struct PulseStoneData {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ char unk_10[0x8];
    /* 0x18 */ s32 appearDelay;
    /* 0x1C */ char unk_1C[0x4];
    /* 0x20 */ s32 pingTime;
    /* 0x24 */ s32 state;
} PulseStoneData; // size = 0x28

enum {
    PULSE_STONE_APPEAR     = 0, // icon appears
    PULSE_STONE_OVERSHOOT  = 1, // icon scale overshoots
    PULSE_STONE_HOLD       = 2, // icon reaches final size
};

#include "pulse_stone_icon.png.h"
INCLUDE_IMG("pulse_stone_icon.png", pulse_stone_icon_img);
INCLUDE_PAL("pulse_stone_icon.pal", pulse_stone_icon_1_pal);
INCLUDE_PAL("pulse_stone_icon.flash.pal", pulse_stone_icon_2_pal);
#include "pulse_stone_icon.gfx.inc.c"

BSS PulseStoneData PulseStoneNotification;
PulseStoneData* PulseStonePtr = &PulseStoneNotification;

void pulse_stone_notification_update(void);

s32 should_cancel_pulse_stone(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    s8 actionState = playerStatus->actionState;

    // could be written more clearly if these two condtions were inverted
    if (actionState != ACTION_STATE_USE_TWEESTER) {
        if (!(partnerStatus->partnerActionState == PARTNER_ACTION_USE
            && (partnerStatus->actingPartner == PARTNER_BOW || partnerStatus->actingPartner == PARTNER_PARAKARRY))
        ) {
            return FALSE;
        }
    }
    return TRUE;
}

s32 should_continue_pulse_stone(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (!is_starting_conversation()
        && !(playerStatus->flags & PS_FLAG_PAUSED)
        && playerStatus->animFlags & PA_FLAG_USING_PULSE_STONE
        && !has_valid_conversation_npc()
        && !func_800E06D8()
    ) {
        s32 dx = abs((gGameStatusPtr->mapID % 7) - 2);
        s32 dy = gGameStatusPtr->mapID / 7;

        if ((dx + dy) < 6) {
            if (!should_cancel_pulse_stone()) {
                dy = TRUE; // TODO required to set dy to 1 and return that

                return TRUE;
            }
        }
    }
    return FALSE;
}

void pulse_stone_notification_setup(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    mem_clear(PulseStonePtr, sizeof(*PulseStonePtr));
    PulseStonePtr->pos.x = playerStatus->pos.x;
    PulseStonePtr->pos.y = playerStatus->pos.y + playerStatus->colliderHeight + 8.0f;
    PulseStonePtr->pos.z = playerStatus->pos.z;
    playerStatus->animFlags |= PA_FLAG_PULSE_STONE_VISIBLE;
    PulseStoneNotificationCallback = pulse_stone_notification_update;
}

void appendGfx_pulse_stone_icon(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f sp18, sp58;
    ImgFXTexture ifxImg;
    s32 pingDelay;
    s32 dx, dy;

    if (playerStatus->animFlags & PA_FLAG_PULSE_STONE_VISIBLE) {
        guScaleF(sp18, PulseStonePtr->scale, PulseStonePtr->scale, PulseStonePtr->scale);
        guRotateF(sp58, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp18, sp58, sp18);
        guTranslateF(sp58, PulseStonePtr->pos.x, PulseStonePtr->pos.y, PulseStonePtr->pos.z);
        guMtxCatF(sp18, sp58, sp58);
        guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                    G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, pulse_stone_icon_gfx);

        dx = abs((gGameStatusPtr->mapID % 7) - 2);
        dy = gGameStatusPtr->mapID / 7;

        switch (dx + dy) {
            case 0:
                pingDelay = 4;
                break;
            case 1:
                pingDelay = 8;
                break;
            case 2:
                pingDelay = 16;
                break;
            case 3:
                pingDelay = 32;
                break;
            case 4:
                pingDelay = 64;
                break;
            case 5:
                pingDelay = 128;
                break;
            default:
                pingDelay = -1;
                PulseStonePtr->pingTime = 0;
                break;
        }

        ifxImg.palette = pulse_stone_icon_1_pal;
        if (pingDelay >= 0) {
            PulseStonePtr->pingTime++;
            if (PulseStonePtr->pingTime >= pingDelay + 2) {
                PulseStonePtr->pingTime = 0;
                sfx_play_sound_at_player(SOUND_PULSE_STONE, SOUND_SPACE_DEFAULT);
            }
            if (PulseStonePtr->pingTime < 2) {
                ifxImg.palette = pulse_stone_icon_2_pal;
            } else {
                ifxImg.palette = pulse_stone_icon_1_pal;
            }
        }

        ifxImg.raster  = pulse_stone_icon_img;
        ifxImg.width   = pulse_stone_icon_img_width;
        ifxImg.height  = pulse_stone_icon_img_height;
        ifxImg.xOffset = -28;
        ifxImg.yOffset = 46;
        ifxImg.alpha = 255;
        imgfx_appendGfx_component(0, &ifxImg, 0, sp58);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}

void pulse_stone_notification_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    PulseStonePtr->pos.y +=
        ((playerStatus->pos.y + playerStatus->colliderHeight + 10.0f) - PulseStonePtr->pos.y) / 1.5f;
    PulseStonePtr->pos.x = playerStatus->pos.x;
    PulseStonePtr->pos.z = playerStatus->pos.z;

    if (!should_continue_pulse_stone()) {
        PulseStoneNotificationCallback = NULL;
        playerStatus->animFlags &= ~PA_FLAG_PULSE_STONE_VISIBLE;
        return;
    }

    switch (PulseStonePtr->state) {
        case PULSE_STONE_APPEAR:
            if (PulseStonePtr->appearDelay++ < 6) {
                break;
            }
            PulseStonePtr->scale = 0.36f;
            PulseStonePtr->state++;
            break;
        case PULSE_STONE_OVERSHOOT:
            PulseStonePtr->scale = 0.57f;
            PulseStonePtr->state++;
            break;
        case PULSE_STONE_HOLD:
            PulseStonePtr->scale = 0.53f;
            PulseStonePtr->state++;
            break;
    }
}
