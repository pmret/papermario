#include "common.h"

#define NAMESPACE inspect_icon

typedef struct InspectIconData {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 yaw;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s32 holdTime;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ s32 alpha; // unused
    /* 0x20 */ char unk_20[0x1];
    /* 0x21 */ s8 iconBounceVel;
    /* 0x22 */ s8 iconBounceDir;
    /* 0x23 */ u8 state;
    /* 0x24 */ u8 brightness;
    /* 0x25 */ char unk_25[0x3];
} InspectIconData; // size = 0x28

enum {
    INSPECT_ICON_APPEAR     = 0,
    INSPECT_ICON_HOLD       = 1,
    INSPECT_ICON_IDLE       = 2,
    INSPECT_ICON_VANISH     = 3,
};

#include "inspect_icon.png.h"
#include "inspect_icon.png.inc.c"
#include "inspect_icon.pal.inc.c"
#include "inspect_icon.gfx.inc.c"

BSS InspectIconData InspectIcon;
InspectIconData* InspectIconPtr = &InspectIcon;

#include "common/GetIconBrightnessForAngle.inc.c"

void interact_inspect_update(void);
void interact_inspect_dismiss(void);

void interact_inspect_setup(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 new_var;

    if (playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) {
        mem_clear(InspectIconPtr, sizeof(*InspectIconPtr));
        D_8010C950 = -1;
        InspectIconPtr->pos.x = playerStatus->pos.x;
        InspectIconPtr->pos.y = playerStatus->pos.y + playerStatus->colliderHeight +
                                   (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) ? 8.0f : 2.0f);
        InspectIconPtr->pos.z = playerStatus->pos.z;
        InspectIconPtr->scale = 0.4f;
        InspectIconPtr->state = INSPECT_ICON_APPEAR;
        InspectIconPtr->yaw = -gCameras[gCurrentCameraID].curYaw;
        InteractNotificationCallback = interact_inspect_update;
        InspectIconPtr->brightness = 255;
        InspectIconPtr->alpha = 255;
    }
}

void appendGfx_interact_prompt(void) {
    ImgFXTexture ifxImg;
    Matrix4f sp38, sp78;

    if (gPlayerStatus.animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) {
        guScaleF(sp38, InspectIconPtr->scale, InspectIconPtr->scale, InspectIconPtr->scale);
        guRotateF(sp78, InspectIconPtr->yaw - gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp38, sp78, sp38);
        guTranslateF(sp78, InspectIconPtr->pos.x, InspectIconPtr->pos.y, InspectIconPtr->pos.z);
        guMtxCatF(sp38, sp78, sp78);
        guMtxF2L(sp78, &gDisplayContext->matrixStack[gMatrixListPos]);

        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                  G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMainGfxPos++, &inspect_icon_gfx);

        ifxImg.raster  = inspect_icon_img;
        ifxImg.palette = inspect_icon_pal;
        ifxImg.width   = inspect_icon_img_width;
        ifxImg.height  = inspect_icon_img_height;
        ifxImg.xOffset = -16;
        ifxImg.yOffset = 26;
        ifxImg.alpha = 255;
        imgfx_update(0, IMGFX_CLEAR, 0, 0, 0, 0, IMGFX_FLAG_400 | IMGFX_FLAG_40);
        imgfx_update(0, IMGFX_SET_COLOR,
                    InspectIconPtr->brightness, InspectIconPtr->brightness, InspectIconPtr->brightness, 255,
                    IMGFX_FLAG_400 | IMGFX_FLAG_40 | IMGFX_FLAG_8);
        imgfx_appendGfx_component(0, &ifxImg, 0, sp78);

        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }
}

// similar to check_for_interactables
s32 should_continue_inspect(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 curInteraction = collisionStatus->curWall;
    Npc* npc = playerStatus->encounteredNPC;

    if (curInteraction == NO_COLLIDER) {
        s32 floor = gCollisionStatus.curFloor;

        if (floor >= 0 && (floor & COLLISION_WITH_ENTITY_BIT)) {
            curInteraction = floor;
            switch (get_entity_type(floor)) {
                case ENTITY_TYPE_PADLOCK:
                case ENTITY_TYPE_PADLOCK_RED_FRAME:
                case ENTITY_TYPE_PADLOCK_RED_FACE:
                case ENTITY_TYPE_PADLOCK_BLUE_FACE:
                case ENTITY_TYPE_PUSH_BLOCK:
                case ENTITY_TYPE_CHEST:
                case ENTITY_TYPE_SIGNPOST:
                    curInteraction = NO_COLLIDER;
                    break;
            }
        } else if (!(playerStatus->flags & PS_FLAG_INPUT_DISABLED)
            && (playerStatus->flags & PS_FLAG_HAS_CONVERSATION_NPC)
            && (npc != NULL)
            && (npc->flags & NPC_FLAG_10000000)
        ) {
            curInteraction = npc->npcID | COLLISION_WITH_NPC_BIT;
            if (playerStatus->interactingWithID == curInteraction) {
                return TRUE;
            }
        } else {
            playerStatus->interactingWithID = NO_COLLIDER;
            playerStatus->flags &= ~PS_FLAG_INTERACTED;
            return FALSE;
        }
    } else {
        if (!(curInteraction & COLLISION_WITH_ENTITY_BIT)) {
            if (!(curInteraction & COLLISION_WITH_NPC_BIT)) {
                if (!should_collider_allow_interact(curInteraction)) {
                    playerStatus->interactingWithID = NO_COLLIDER;
                    playerStatus->flags &= ~PS_FLAG_INTERACTED;
                    return FALSE;
                }
            }
        } else {
            if (!phys_can_player_interact()) {
                playerStatus->interactingWithID = NO_COLLIDER;
                playerStatus->flags &= ~PS_FLAG_INTERACTED;
                return FALSE;
            }
        }
    }
    if (playerStatus->interactingWithID == curInteraction) {
        if ((playerStatus->flags & PS_FLAG_INTERACTED)) {
            return FALSE;
        }
    } else {
        playerStatus->flags &= ~PS_FLAG_INTERACTED;
    }

    playerStatus->interactingWithID = curInteraction;
    return TRUE;
}

void update_inspect_icon_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 bounceDeltaY;
    f32 playerHeadY;
    f32 lastPosY;
    f32 delta;

    // this bouncing behavior is never seen because dir is never changed from zero
    InspectIconPtr->iconBounceVel += InspectIconPtr->iconBounceDir;

    if (InspectIconPtr->iconBounceVel > 4) {
        InspectIconPtr->iconBounceDir = -1;
        InspectIconPtr->iconBounceVel = 4;
    }
    if (InspectIconPtr->iconBounceVel < -4) {
        InspectIconPtr->iconBounceDir = 1;
        InspectIconPtr->iconBounceVel = -4;
    }

    delta = (playerStatus->pos.x - InspectIconPtr->pos.x) * 0.666f;
    InspectIconPtr->pos.x += delta;
    delta = (playerStatus->pos.z - InspectIconPtr->pos.z) * 0.666f;
    InspectIconPtr->pos.z += delta;

    playerHeadY = playerStatus->pos.y + playerStatus->colliderHeight;
    bounceDeltaY = InspectIconPtr->iconBounceVel;
    lastPosY = InspectIconPtr->pos.y;
    if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
        delta = (playerHeadY + 8.0f + bounceDeltaY - lastPosY) * 0.25f;
    } else {
        delta = (playerHeadY + 2.0f + bounceDeltaY - lastPosY) * 0.25f;
    }
    InspectIconPtr->pos.y += delta;
}

void interact_inspect_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 brightness = 255;
    f32 angle;
    s32 actionState;

    update_inspect_icon_pos();

    switch (InspectIconPtr->state) {
        case INSPECT_ICON_APPEAR:
            InspectIconPtr->yaw = 0.0f;
            InspectIconPtr->scale += 0.05;
            if (InspectIconPtr->scale >= 0.55) {
                InspectIconPtr->scale = 0.55f;
                InspectIconPtr->state++;
                InspectIconPtr->holdTime = 12;
            }
            break;
        case INSPECT_ICON_HOLD:
            InspectIconPtr->yaw = 0.0f;
            InspectIconPtr->holdTime--;
            if (InspectIconPtr->holdTime <= 0) {
                InspectIconPtr->state++;
            }
            break;
        case INSPECT_ICON_IDLE:
            angle = InspectIconPtr->yaw;
            angle += 10.0f;
            if (angle >= 360.0f) {
                angle -= 360.0f;
            }
            InspectIconPtr->yaw = angle;
            brightness = N(GetIconBrightnessForAngle)(angle);
            break;
        case INSPECT_ICON_VANISH:
            angle = InspectIconPtr->yaw;
            angle += 25.0f;
            if (angle >= 360.0f) {
                angle -= 360.0f;
            }
            InspectIconPtr->yaw = angle;
            InspectIconPtr->alpha -= 25;
            if (InspectIconPtr->alpha < 0) {
                InspectIconPtr->alpha = 0;
            }
            if ((angle >= 70.0f && angle <= 110.0f) || (angle >= 250.0f && angle <= 290.0f)) {
                // only dimiss when the icon is rotated away from view
                InteractNotificationCallback = interact_inspect_dismiss;
            }
            brightness = N(GetIconBrightnessForAngle)(angle);
            break;
    }
    InspectIconPtr->brightness = brightness;

    actionState = playerStatus->actionState;
    if (!should_continue_inspect()
        || (playerStatus->inputDisabledCount != 0)
        || (playerStatus->flags & PS_FLAG_PAUSED)
        || !(actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN)
    ) {
        InspectIconPtr->state = INSPECT_ICON_VANISH;
    }

    if ((playerStatus->interactingWithID >= 0)
        && (playerStatus->interactingWithID & COLLISION_WITH_ENTITY_BIT)
        && !(get_entity_by_index(playerStatus->interactingWithID)->flags & ENTITY_FLAG_SHOWS_INSPECT_PROMPT)
    ) {
        InspectIconPtr->state = INSPECT_ICON_VANISH;
    }
}

void interact_inspect_dismiss(void) {
    update_inspect_icon_pos();
    gPlayerStatusPtr->interactingWithID = NO_COLLIDER;
    InteractNotificationCallback = NULL;
    gPlayerStatusPtr->encounteredNPC = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAG_INTERACT_PROMPT_AVAILABLE;
    func_800EF3D4(0);
    partner_reset_tether_distance();
}

MATCHING_BSS(0x30);
