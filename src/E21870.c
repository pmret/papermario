#include "common.h"

typedef struct TempE21870 {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x4];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
} TempE21870; // size = 0x28

extern u8 D_802B7640_E21EB0[];
extern u16 D_802B7C60_E224D0[];
extern u16 D_802B7C80_E224F0[];
extern Gfx D_802B7CA0_E22510[];
extern TempE21870* D_802B7D18_E22588;

void func_802B74F0(void);

s32 func_802B7000_2(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s8 actionState = playerStatus->actionState;

    if (actionState != ACTION_STATE_USE_TWEESTER) {
        if (partnerActionStatus->partnerActionState != PARTNER_ACTION_USE ||
                (partnerActionStatus->actingPartner != PARTNER_BOW
                && partnerActionStatus->actingPartner != PARTNER_PARAKARRY)) {
            return FALSE;
        }
    }
    return TRUE;
}

s32 func_802B704C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (!is_starting_conversation()) {
        if (!(playerStatus->flags & PS_FLAGS_20)) {
            if (playerStatus->animFlags & PA_FLAGS_USING_PULSE_STONE) {
                if (!has_valid_conversation_npc()) {
                    if (!func_800E06D8()) {
                        s32 dx = abs((gGameStatusPtr->mapID % 7) - 2);
                        s32 dy = gGameStatusPtr->mapID / 7;

                        if ((dx + dy) < 6) {
                            if (!func_802B7000_2()) {
                                dy = TRUE; // TODO required to set dy to 1 and return that

                                return dy;
                            }
                        }
                    }
                }
            }
        }
    }
    return FALSE;
}

void func_802B7140(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    mem_clear(D_802B7D18_E22588, sizeof(*D_802B7D18_E22588));
    D_802B7D18_E22588->pos.x = playerStatus->position.x;
    D_802B7D18_E22588->pos.y = playerStatus->position.y + playerStatus->colliderHeight + 8.0f;
    D_802B7D18_E22588->pos.z = playerStatus->position.z;
    playerStatus->animFlags |= PA_FLAGS_40;
    D_8010C920 = func_802B74F0;
}

void func_802B71D4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f sp18, sp58;
    FoldImageRecPart part;
    s32 var_v1;
    s32 dx, dy;

    if (playerStatus->animFlags & PA_FLAGS_40) {
        guScaleF(sp18, D_802B7D18_E22588->scale, D_802B7D18_E22588->scale, D_802B7D18_E22588->scale);
        guRotateF(sp58, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp18, sp58, sp18);
        guTranslateF(sp58, D_802B7D18_E22588->pos.x, D_802B7D18_E22588->pos.y, D_802B7D18_E22588->pos.z);
        guMtxCatF(sp18, sp58, sp58);
        guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, D_802B7CA0_E22510);

        dx = abs((gGameStatusPtr->mapID % 7) - 2);
        dy = gGameStatusPtr->mapID / 7;

        switch (dx + dy) {
            case 0:
                var_v1 = 4;
                break;
            case 1:
                var_v1 = 8;
                break;
            case 2:
                var_v1 = 16;
                break;
            case 3:
                var_v1 = 32;
                break;
            case 4:
                var_v1 = 64;
                break;
            case 5:
                var_v1 = 128;
                break;
            default:
                var_v1 = -1;
                D_802B7D18_E22588->unk_20 = 0;
                break;
        }

        part.palette = D_802B7C60_E224D0;
        if (var_v1 >= 0) {
            D_802B7D18_E22588->unk_20++;
            if (D_802B7D18_E22588->unk_20 >= var_v1 + 2) {
                D_802B7D18_E22588->unk_20 = 0;
                sfx_play_sound_at_player(SOUND_7D, 0);
            }
            if (D_802B7D18_E22588->unk_20 < 2) {
                part.palette = D_802B7C80_E224F0;
            } else {
                part.palette = D_802B7C60_E224D0;
            }
        }

        part.raster = D_802B7640_E21EB0;
        part.width = 56;
        part.height = 56;
        part.xOffset = -28;
        part.yOffset = 46;
        part.opacity = 255;
        fold_appendGfx_component(0, &part, 0, sp58);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
}

void func_802B74F0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    D_802B7D18_E22588->pos.y +=
        ((playerStatus->position.y + playerStatus->colliderHeight + 10.0f) - D_802B7D18_E22588->pos.y) / 1.5f;
    D_802B7D18_E22588->pos.x = playerStatus->position.x;
    D_802B7D18_E22588->pos.z = playerStatus->position.z;

    if (!func_802B704C()) {
        D_8010C920 = NULL;
        playerStatus->animFlags &= ~PA_FLAGS_40;
        return;
    }

    switch (D_802B7D18_E22588->unk_24) {
        case 0:
            if (D_802B7D18_E22588->unk_18++ < 6) {
                break;
            }
            D_802B7D18_E22588->scale = 0.36f;
            D_802B7D18_E22588->unk_24++;
            break;
        case 1:
            D_802B7D18_E22588->scale = 0.57f;
            D_802B7D18_E22588->unk_24++;
            break;
        case 2:
            D_802B7D18_E22588->scale = 0.53f;
            D_802B7D18_E22588->unk_24++;
            break;
    }
}
