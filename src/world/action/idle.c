#include "common.h"
#include "../actions.h"

AnimID IdlePeachAnims[] = {
    ANIM_Peach1_Idle, // none
    ANIM_Peach1_HoldCream, // cream
    ANIM_Peach1_HoldStrawberry, // strawberry
    ANIM_Peach1_HoldButter, // butter
    ANIM_Peach1_HoldCleanser, // cleanser
    ANIM_Peach1_HoldWater, // water
    ANIM_Peach1_HoldMilk, // milk
    ANIM_Peach1_HoldFlour, // flour
    ANIM_Peach1_HoldEgg, // egg
    ANIM_Peach1_HoldCompleteCake, // complete cake
    ANIM_Peach1_HoldCakeBowl, // cake bowl
    ANIM_Peach1_HoldCakeMixed, // cake mixed
    ANIM_Peach1_HoldCakePan, // cake pan
    ANIM_Peach1_HoldCakeBatter, // cake batter
    ANIM_Peach1_HoldBareCake, // cake bare
    ANIM_Peach1_HoldSalt, // salt
    ANIM_Peach1_HoldSugar, // sugar
    ANIM_Peach1_HoldIcingCake, // cake with icing
    ANIM_Peach1_HoldBerryCake, // cake with berries
    0x00000000,
};

enum {
    SUBSTATE_IDLE_DEFAULT   = 0,
    SUBSTATE_IDLE_STRETCH   = 1,
    SUBSTATE_DELAY_SLEEP    = 2,
    SUBSTATE_IDLE_SLEEP     = 3,
};

void action_update_idle_peach(void);

void action_update_idle(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 wasMoving = FALSE;
    f32 angle, magnitude;
    AnimID anim;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_idle_peach();
        return;
    }

    playerStatus->currentStateTime++;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_ARMS_RAISED | PS_FLAG_AIRBORNE);
        wasMoving = TRUE;
        playerStatus->actionSubstate = SUBSTATE_IDLE_DEFAULT;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;

        if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
            anim = ANIM_MarioW3_8bit_Still;
        } else if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
            anim = ANIM_Mario1_Idle;
        } else if (playerStatus->prevActionState == ACTION_STATE_IDLE) {
            anim = ANIM_MarioW1_TakeItem;
        } else {
            anim = ANIM_MarioW1_CarryIdle;
        }
        suggest_player_anim_allow_backward(anim);
    }

    if (playerStatus->animFlags & PA_FLAG_RAISED_ARMS) {
        set_action_state(ACTION_STATE_RAISE_ARMS);
    } else {
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
                    playerStatus->animFlags &= ~PA_FLAG_80000000;
                }
            }
        }
    }
}

void action_update_idle_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 angle, magnitude;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_IDLE_DEFAULT;
        playerStatus->currentStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->flags &= ~PS_FLAG_AIRBORNE;

        if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
            if (!(gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_DEPRESSED)) {
                suggest_player_anim_allow_backward(IdlePeachAnims[gGameStatusPtr->peachBakingIngredient]);
            } else {
                suggest_player_anim_allow_backward(ANIM_Peach2_SadStill);
            }
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].idle);
        }
    }

    if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
        switch (playerStatus->actionSubstate) {
            case SUBSTATE_IDLE_DEFAULT:
                if (!(playerStatus->flags & (PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_INPUT_DISABLED))
                    && (playerStatus->peachItemHeld == 0)) {
                    if (playerStatus->currentStateTime > 1800) {
                        // begin first yawm
                        playerStatus->actionSubstate++;
                        suggest_player_anim_allow_backward(ANIM_Peach2_Yawn);
                        return;
                    }
                    playerStatus->currentStateTime++;
                }
                break;
            case SUBSTATE_IDLE_STRETCH:
                // waiting for yawn to finish
                if (playerStatus->animNotifyValue != 0) {
                    playerStatus->actionSubstate++;
                    playerStatus->currentStateTime = 0;
                    suggest_player_anim_allow_backward(ANIM_Peach1_Idle);
                }
                break;
            case SUBSTATE_DELAY_SLEEP:
                // delay before next yawn and sleep
                playerStatus->currentStateTime++;
                if (playerStatus->currentStateTime > 200) {
                    playerStatus->actionSubstate++;
                    suggest_player_anim_allow_backward(ANIM_Peach2_Yawn);
                }
                break;
            case SUBSTATE_IDLE_SLEEP:
                // peach is asleep
                if (playerStatus->flags & (PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_INPUT_DISABLED)) {
                    suggest_player_anim_allow_backward(ANIM_Peach1_Idle);
                    playerStatus->actionSubstate = SUBSTATE_IDLE_DEFAULT;
                } else if (playerStatus->animNotifyValue != 0) {
                    suggest_player_anim_allow_backward(ANIM_Peach2_Sleep);
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
