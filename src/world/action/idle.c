#include "common.h"
#include "../actions.h"

AnimID IdlePeachAnims[] = {
    ANIM_Peach_A0001, // none
    ANIM_Peach_A0007, // cream
    ANIM_Peach_A0009, // strawberry
    ANIM_Peach_A000B, // butter
    ANIM_Peach_A000D, // cleanser
    ANIM_Peach_A000F, // water
    ANIM_Peach_A0011, // milk
    ANIM_Peach_A0013, // flour
    ANIM_Peach_A0015, // egg
    ANIM_Peach_A0017, // complete cake
    ANIM_Peach_A0019, // cake bowl
    ANIM_Peach_A001B, // cake mixed
    ANIM_Peach_A001D, // cake pan
    ANIM_Peach_A001F, // cake batter
    ANIM_Peach_A0021, // cake bare
    ANIM_Peach_A0023, // salt
    ANIM_Peach_A0025, // sugar
    ANIM_Peach_A0027, // cake with icing
    ANIM_Peach_A0029, // cake with berries
    0x00000000,
};

void action_update_idle_peach(void);

void action_update_idle(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 wasMoving = FALSE;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        action_update_idle_peach();
        return;
    }

    playerStatus->currentStateTime++;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 anim;

        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED
            | PLAYER_STATUS_FLAGS_80000 | PLAYER_STATUS_FLAGS_AIRBORNE);
        wasMoving = TRUE;
        playerStatus->actionSubstate = 0;
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

void action_update_idle_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 angle;
    f32 magnitude;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = 0;
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
        switch (playerStatus->actionSubstate) {
            case 0:
                if (!(playerStatus->flags & (PLAYER_STATUS_FLAGS_1000 | PLAYER_STATUS_FLAGS_INPUT_DISABLED)) && (playerStatus->unk_C4 == 0)) {
                    if (playerStatus->currentStateTime > 1800) {
                        playerStatus->actionSubstate++;
                        suggest_player_anim_clearUnkFlag(ANIM_Peach_C0003);
                        return;
                    }
                    playerStatus->currentStateTime++;
                }
                break;
            case 1:
                if (playerStatus->unk_BC != 0) {
                    playerStatus->actionSubstate++;
                    playerStatus->currentStateTime = 0;
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_A0001);
                }
                break;
            case 2: {
                playerStatus->currentStateTime++;
                if (playerStatus->currentStateTime > 200) {
                    playerStatus->actionSubstate++;
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_C0003);
                }
                break;
            }
            case 3:
                if (playerStatus->flags & (PLAYER_STATUS_FLAGS_1000 | PLAYER_STATUS_FLAGS_INPUT_DISABLED)) {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_A0001);
                    playerStatus->actionSubstate = 0;
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
