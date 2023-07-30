#include "common.h"

#define NAMESPACE speech_bubble

enum {
    SPEECH_BUBBLE_APPEAR    = 0,
    SPEECH_BUBBLE_HOLD      = 1,
    SPEECH_BUBBLE_IDLE      = 2,
    SPEECH_BUBBLE_VANISH    = 3,
};

#include "speech_bubble.png.h"
#include "speech_bubble.png.inc.c"
#include "speech_bubble.pal.inc.c"
#include "speech_bubble.gfx.inc.c"

BSS SpeechBubbleData SpeechBubble;
SpeechBubbleData* SpeechBubblePtr = &SpeechBubble;

#include "common/GetIconBrightnessForAngle.inc.c"

void interact_speech_update(void);

void interact_speech_setup(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SpeechBubbleData* temp;
    Npc* npc;

    mem_clear(SpeechBubblePtr, sizeof(*SpeechBubblePtr));
    npc = playerStatus->encounteredNPC;
    SpeechBubblePtr->encounteredNPC = npc;
    SpeechBubblePtr->pos.y = SpeechBubblePtr->unk_1C = npc->pos.y + npc->collisionHeight + 8.0f;
    SpeechBubblePtr->pos.x = npc->pos.x;
    SpeechBubblePtr->pos.z = npc->pos.z;
    SpeechBubblePtr->unk_18 = 0;
    SpeechBubblePtr->state = 0;
    SpeechBubblePtr->scale = 0.1f;
    TalkNotificationCallback = interact_speech_update;
    playerStatus->animFlags |= PA_FLAG_SPEECH_PROMPT_AVAILABLE;
    temp = SpeechBubblePtr;
    temp->state = 0;
    temp->scale = 0.4f;
    SpeechBubblePtr->yaw = -gCameras[gCurrentCameraID].curYaw;
    SpeechBubblePtr->brightness = 255;
}

void appendGfx_speech_bubble(void) {
    ImgFXTexture ifxImg;
    Matrix4f mtxTemp, mtxTransform;

    if (gPlayerStatus.animFlags & PA_FLAG_SPEECH_PROMPT_AVAILABLE) {
        guScaleF(mtxTemp, SpeechBubblePtr->scale, SpeechBubblePtr->scale, SpeechBubblePtr->scale);
        guRotateF(mtxTransform, SpeechBubblePtr->yaw - gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtxTemp, mtxTransform, mtxTemp);
        guTranslateF(mtxTransform, SpeechBubblePtr->pos.x, SpeechBubblePtr->pos.y, SpeechBubblePtr->pos.z);
        guMtxCatF(mtxTemp, mtxTransform, mtxTransform);
        guMtxF2L(mtxTransform, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, &speech_bubble_gfx);

        ifxImg.raster  = speech_bubble_img;
        ifxImg.palette = speech_bubble_pal;
        ifxImg.width   = speech_bubble_img_width;
        ifxImg.height  = speech_bubble_img_height;
        ifxImg.xOffset = -16;
        ifxImg.yOffset = 26;
        ifxImg.alpha = 255;
        imgfx_update(0, IMGFX_CLEAR, 0, 0, 0, 0, IMGFX_FLAG_400 | IMGFX_FLAG_40);
        imgfx_update(0, IMGFX_SET_COLOR,
                    SpeechBubblePtr->brightness, SpeechBubblePtr->brightness, SpeechBubblePtr->brightness, 255, 0x440);
        imgfx_appendGfx_component(0, &ifxImg, IMGFX_FLAG_40, mtxTransform);

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}

void interact_speech_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 brightness = 255;
    f32 yaw;
    Npc* npc;

    if (((playerStatus->flags & (PS_FLAG_HAS_CONVERSATION_NPC | PS_FLAG_ENTERING_BATTLE | PS_FLAG_PAUSED))
            != PS_FLAG_HAS_CONVERSATION_NPC)
        || gEncounterState == ENCOUNTER_STATE_CONVERSATION
        || playerStatus->animFlags & PA_FLAG_USING_WATT
        || playerStatus->inputDisabledCount != 0
        || playerStatus->animFlags & PA_FLAG_SPINNING
    ) {
        SpeechBubblePtr->state = 3;
    }

    switch (SpeechBubblePtr->state) {
        case SPEECH_BUBBLE_APPEAR:
            SpeechBubblePtr->yaw = 0.0f;
            SpeechBubblePtr->scale += 0.05;
            if (SpeechBubblePtr->scale >= 0.55) {
                SpeechBubblePtr->scale = 0.55f;
                SpeechBubblePtr->state++;
                SpeechBubblePtr->holdTime = 12;
            }
            break;
        case SPEECH_BUBBLE_HOLD:
            SpeechBubblePtr->yaw = 0.0f;
            SpeechBubblePtr->holdTime--;
            if (SpeechBubblePtr->holdTime <= 0) {
                SpeechBubblePtr->state++;
            }
            break;
        case SPEECH_BUBBLE_IDLE:
            yaw = SpeechBubblePtr->yaw;
            yaw += 10.0f;
            if (yaw >= 360.0f) {
                yaw -= 360.0f;
            }
            SpeechBubblePtr->yaw = yaw;
            brightness = N(GetIconBrightnessForAngle)(yaw);
            break;
        case SPEECH_BUBBLE_VANISH:
            yaw = SpeechBubblePtr->yaw;
            yaw += 25.0f;
            if (yaw >= 360.0f) {
                yaw -= 360.0f;
            }
            SpeechBubblePtr->yaw = yaw;
            if ((yaw >= 70.0f && yaw <= 110.0f) || (yaw >= 250.0f && yaw <= 290.0f)) {
                // only dimiss when the icon is rotated away from view
                TalkNotificationCallback = NULL;
                playerStatus->encounteredNPC = NULL;
                playerStatus->animFlags &= ~PA_FLAG_SPEECH_PROMPT_AVAILABLE;
                return;
            }
            brightness = N(GetIconBrightnessForAngle)(yaw);
            break;
    }

    SpeechBubblePtr->brightness = brightness;
    if (playerStatus->encounteredNPC != NULL) {
        if (playerStatus->encounteredNPC != SpeechBubblePtr->encounteredNPC) {
            SpeechBubblePtr->encounteredNPC = playerStatus->encounteredNPC;
        }
    }

    npc = SpeechBubblePtr->encounteredNPC;
    SpeechBubblePtr->pos.y = SpeechBubblePtr->unk_1C = npc->pos.y + npc->collisionHeight + 8.0f;
    SpeechBubblePtr->pos.x = npc->pos.x;
    SpeechBubblePtr->pos.z = npc->pos.z;
}
