#include "common.h"
#include "../actions.h"

s32 IdlePeachAnims[] = {
    0x000A0001, // none
    0x000A0007, // cream
    0x000A0009, // strawberry
    0x000A000B, // butter
    0x000A000D, // cleanser
    0x000A000F, // water
    0x000A0011, // milk
    0x000A0013, // flour
    0x000A0015, // egg
    0x000A0017, // complete cake
    0x000A0019, // cake bowl
    0x000A001B, // cake mixed
    0x000A001D, // cake pan
    0x000A001F, // cake batter
    0x000A0021, // cake bare
    0x000A0023, // salt
    0x000A0025, // sugar
    0x000A0027, // cake with icing
    0x000A0029, // cake with berries
    0x00000000,
};

void action_idle_update_peach(void);

void action_idle_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 wasMoving = FALSE;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        action_idle_update_peach();
        return;
    }

    playerStatus->currentStateTime++;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 anim;

        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED
            | PLAYER_STATUS_FLAGS_80000 | PLAYER_STATUS_FLAGS_AIRBORNE);
        wasMoving = TRUE;
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            anim = 0x90002;
        } else if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT)) {
            anim = 0x10002;
        } else if ((s8)playerStatus->prevActionState == ACTION_STATE_IDLE) {
            anim = 0x60005;
        } else {
            anim = 0x60007;
        }
        suggest_player_anim_clearUnkFlag(anim);
    }

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_RAISED_ARMS) {
        set_action_state(ACTION_STATE_RAISE_ARMS);
    } else {
        f32 angle;
        f32 magnitude;

        player_input_to_move_vector(&angle, &magnitude);
        phys_update_interact_collider();

        if (check_input_jump()) {
            if (magnitude != 0.0f || playerStatus->targetYaw != angle) {
                playerStatus->targetYaw = angle;
            }
        } else if (wasMoving || !check_input_hammer()) {
            if (magnitude == 0.0f) {
                playerData->idleFrameCounter++;
            } else {
                playerStatus->currentStateTime = 0;
                set_action_state(ACTION_STATE_WALK);
                if (magnitude != 0.0f) {
                    playerStatus->targetYaw = angle;
                    playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_80000000;
                }
            }
        }
    }
}

void action_idle_update_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 angle;
    f32 magnitude;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_AIRBORNE;

        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_IN_DISGUISE)) {
            if (!(gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_HAS_INGREDIENT)) {
                suggest_player_anim_clearUnkFlag(IdlePeachAnims[gGameStatusPtr->peachCookingIngredient]);
            } else {
                suggest_player_anim_clearUnkFlag(ANIM_Peach_C000E);
            }
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].idle);
        }
    }

    if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_IN_DISGUISE)) {
        switch (playerStatus->fallState) {
            case 0:
                if (!(playerStatus->flags & (PLAYER_STATUS_FLAGS_1000 | PLAYER_STATUS_FLAGS_INPUT_DISABLED)) && (playerStatus->unk_C4 == 0)) {
                    if (playerStatus->currentStateTime > 1800) {
                        playerStatus->fallState++;
                        suggest_player_anim_clearUnkFlag(ANIM_Peach_C0003);
                        return;
                    }
                    playerStatus->currentStateTime++;
                }
                break;
            case 1:
                if (playerStatus->unk_BC != 0) {
                    playerStatus->fallState++;
                    playerStatus->currentStateTime = 0;
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_A0001);
                }
                break;
            case 2: {
                playerStatus->currentStateTime++;
                if (playerStatus->currentStateTime > 200) {
                    playerStatus->fallState++;
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0003);
                }
                break;
            }
            case 3:
                if (playerStatus->flags & (PLAYER_STATUS_FLAGS_1000 | PLAYER_STATUS_FLAGS_INPUT_DISABLED)) {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_A0001);
                    playerStatus->fallState = 0;
                } else if (playerStatus->unk_BC != 0) {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0004);
                }
                break;
        }
    }

    player_input_to_move_vector(&angle, &magnitude);
    phys_update_interact_collider();

    if (magnitude != 0.0f) {
        playerStatus->currentStateTime = 0;
        playerStatus->targetYaw = angle;
        set_action_state(ACTION_STATE_WALK);
    }
}
