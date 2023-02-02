#include "common.h"

#define NAMESPACE speech_bubble

#include "common/UnkAngleFunc1.inc.c"

#include "speech_bubble.png.h"

typedef struct SpeechBubbleData {
    /* 0x00 */ Npc* unk_00;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 scale;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk_24[6];
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ u8 unk_2B;
} SpeechBubbleData; /* size = 0x2C */

BSS SpeechBubbleData D_802B79C0_E21870;

#include "speech_bubble.png.inc.c"
#include "speech_bubble.pal.inc.c"
#include "speech_bubble_dlist.gfx.inc.c"

SpeechBubbleData* D_802B79A8_E21858 = &D_802B79C0_E21870;

void func_802B742C(void);

void func_802B70B4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SpeechBubbleData* temp;
    Npc* npc;

    mem_clear(D_802B79A8_E21858, sizeof(*D_802B79A8_E21858));
    npc = playerStatus->encounteredNPC;
    D_802B79A8_E21858->unk_00 = npc;
    D_802B79A8_E21858->unk_1C = npc->pos.y + npc->collisionHeight + 8.0f;
    D_802B79A8_E21858->pos.y = D_802B79A8_E21858->unk_1C;
    D_802B79A8_E21858->pos.x = npc->pos.x;
    D_802B79A8_E21858->pos.z = npc->pos.z;
    D_802B79A8_E21858->unk_18 = 0;
    D_802B79A8_E21858->unk_2A = 0;
    D_802B79A8_E21858->scale = 0.1f;
    TalkNotificationCallback = func_802B742C;
    playerStatus->animFlags |= PA_FLAG_SPEECH_PROMPT_AVAILABLE;
    temp = D_802B79A8_E21858;
    temp->unk_2A = 0;
    temp->scale = 0.4f;
    D_802B79A8_E21858->unk_10 = -gCameras[gCurrentCameraID].currentYaw;
    D_802B79A8_E21858->unk_2B = 255;
}

void func_802B71C8(void) {
    FoldImageRecPart sp20;
    Matrix4f sp38, sp78;

    if (gPlayerStatus.animFlags & PA_FLAG_SPEECH_PROMPT_AVAILABLE) {
        guScaleF(sp38, D_802B79A8_E21858->scale, D_802B79A8_E21858->scale, D_802B79A8_E21858->scale);
        guRotateF(sp78, D_802B79A8_E21858->unk_10 - gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp38, sp78, sp38);
        guTranslateF(sp78, D_802B79A8_E21858->pos.x, D_802B79A8_E21858->pos.y, D_802B79A8_E21858->pos.z);
        guMtxCatF(sp38, sp78, sp78);
        guMtxF2L(sp78, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, &D_802B7930_E217E0);

        sp20.raster = D_802B7710_E215C0;
        sp20.palette = D_802B7910_E217C0;
        sp20.width = D_802B7710_E215C0_width;
        sp20.height = D_802B7710_E215C0_height;
        sp20.xOffset = -16;
        sp20.yOffset = 26;
        sp20.opacity = 255;
        fold_update(0, FOLD_TYPE_NONE, 0, 0, 0, 0, 0x440);
        fold_update(0, FOLD_TYPE_6,
                    D_802B79A8_E21858->unk_2B, D_802B79A8_E21858->unk_2B, D_802B79A8_E21858->unk_2B, 0xFF, 0x440);
        fold_appendGfx_component(0, &sp20, 0x40, sp78);

        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
}

void func_802B742C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 var_a2 = 255;
    f32 unk10;
    Npc* npc;

    if (((playerStatus->flags & (PS_FLAG_HAS_CONVERSATION_NPC | PS_FLAG_ENTERING_BATTLE | PS_FLAG_PAUSED))
            != PS_FLAG_HAS_CONVERSATION_NPC) ||
        (gEncounterState == ENCOUNTER_STATE_CONVERSATION) ||
        (playerStatus->animFlags & PA_FLAG_USING_WATT) ||
        (playerStatus->inputEnabledCounter != 0) ||
        (playerStatus->animFlags & PA_FLAG_SPINNING))
    {
        D_802B79A8_E21858->unk_2A = 3;
    }

    switch (D_802B79A8_E21858->unk_2A) {
        case 0:
            D_802B79A8_E21858->unk_10 = 0.0f;
            D_802B79A8_E21858->scale += 0.05;
            if (D_802B79A8_E21858->scale >= 0.55) {
                D_802B79A8_E21858->scale = 0.55f;
                D_802B79A8_E21858->unk_2A++;
                D_802B79A8_E21858->unk_20 = 12;
            }
            break;
        case 1:
            D_802B79A8_E21858->unk_10 = 0.0f;
            D_802B79A8_E21858->unk_20--;
            if (D_802B79A8_E21858->unk_20 <= 0) {
                D_802B79A8_E21858->unk_2A++;
            }
            break;
        case 2:
            unk10 = D_802B79A8_E21858->unk_10;
            unk10 += 10.0f;
            if (unk10 >= 360.0f) {
                unk10 -= 360.0f;
            }
            D_802B79A8_E21858->unk_10 = unk10;
            var_a2 = N(UnkAngleFunc1)(unk10);
            break;
        case 3:
            unk10 = D_802B79A8_E21858->unk_10;
            unk10 += 25.0f;
            if (unk10 >= 360.0f) {
                unk10 -= 360.0f;
            }
            D_802B79A8_E21858->unk_10 = unk10;
            if ((unk10 >= 70.0f && unk10 <= 110.0f) || (unk10 >= 250.0f && unk10 <= 290.0f)) {
                TalkNotificationCallback = NULL;
                playerStatus->encounteredNPC = NULL;
                playerStatus->animFlags &= ~PA_FLAG_SPEECH_PROMPT_AVAILABLE;
                return;
            }
            var_a2 = N(UnkAngleFunc1)(unk10);
            break;
    }

    D_802B79A8_E21858->unk_2B = var_a2;
    if (playerStatus->encounteredNPC != NULL) {
        if (playerStatus->encounteredNPC != D_802B79A8_E21858->unk_00) {
            D_802B79A8_E21858->unk_00 = playerStatus->encounteredNPC;
        }
    }

    npc = D_802B79A8_E21858->unk_00;
    D_802B79A8_E21858->unk_1C = npc->pos.y + npc->collisionHeight + 8.0f;
    D_802B79A8_E21858->pos.y = D_802B79A8_E21858->unk_1C;
    D_802B79A8_E21858->pos.x = npc->pos.x;
    D_802B79A8_E21858->pos.z = npc->pos.z;
}
