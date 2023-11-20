#include "common.h"
#include "../actions.h"
#include "sprite/player.h"

AnimID IdlePeachAnims[] = {
    [PEACH_BAKING_NONE]                 ANIM_Peach1_Idle,
    [PEACH_BAKING_CREAM]                ANIM_Peach1_HoldCream,
    [PEACH_BAKING_STRAWBERRY]           ANIM_Peach1_HoldStrawberry,
    [PEACH_BAKING_BUTTER]               ANIM_Peach1_HoldButter,
    [PEACH_BAKING_CLEANSER]             ANIM_Peach1_HoldCleanser,
    [PEACH_BAKING_WATER]                ANIM_Peach1_HoldWater,
    [PEACH_BAKING_MILK]                 ANIM_Peach1_HoldMilk,
    [PEACH_BAKING_FLOUR]                ANIM_Peach1_HoldFlour,
    [PEACH_BAKING_EGG]                  ANIM_Peach1_HoldEgg,
    [PEACH_BAKING_COMPLETE_CAKE]        ANIM_Peach1_HoldCompleteCake,
    [PEACH_BAKING_CAKE_BOWL]            ANIM_Peach1_HoldCakeBowl,
    [PEACH_BAKING_CAKE_MIXED]           ANIM_Peach1_HoldCakeMixed,
    [PEACH_BAKING_CAKE_PAN]             ANIM_Peach1_HoldCakePan,
    [PEACH_BAKING_CAKE_BATTER]          ANIM_Peach1_HoldCakeBatter,
    [PEACH_BAKING_CAKE_BARE]            ANIM_Peach1_HoldBareCake,
    [PEACH_BAKING_SALT]                 ANIM_Peach1_HoldSalt,
    [PEACH_BAKING_SUGAR]                ANIM_Peach1_HoldSugar,
    [PEACH_BAKING_CAKE_WITH_ICING]      ANIM_Peach1_HoldIcingCake,
    [PEACH_BAKING_CAKE_WITH_BERRIES]    ANIM_Peach1_HoldBerryCake,
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
    s32 firstFrame = FALSE;
    f32 angle, magnitude;
    AnimID anim;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_idle_peach();
        return;
    }

    playerStatus->curStateTime++;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_ARMS_RAISED | PS_FLAG_AIRBORNE);
        firstFrame = TRUE;
        playerStatus->actionSubstate = SUBSTATE_IDLE_DEFAULT;
        playerStatus->curStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->curSpeed = 0.0f;
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
        return;
    }

    player_input_to_move_vector(&angle, &magnitude);
    phys_update_interact_collider();

    if (check_input_jump()) {
        if (magnitude != 0.0f || playerStatus->targetYaw != angle) {
            playerStatus->targetYaw = angle;
        }
        return;
    }
    
    if (!firstFrame && check_input_hammer()) {
        return;
    }

    if (magnitude == 0.0f) {
        playerData->idleFrameCounter++;
    } else {
        playerStatus->curStateTime = 0;
        set_action_state(ACTION_STATE_WALK);
        if (magnitude != 0.0f) {
            playerStatus->targetYaw = angle;
            playerStatus->animFlags &= ~PA_FLAG_80000000;
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
        playerStatus->curStateTime = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->curSpeed = 0.0f;
        playerStatus->flags &= ~PS_FLAG_AIRBORNE;

        if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
            if (!(gGameStatusPtr->peachFlags & PEACH_FLAG_DEPRESSED)) {
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
                    && (playerStatus->peachItemHeld == PEACH_BAKING_NONE)
                ) {
                    if (playerStatus->curStateTime > 1800) {
                        // begin first yawm
                        playerStatus->actionSubstate++;
                        suggest_player_anim_allow_backward(ANIM_Peach2_Yawn);
                        return;
                    }
                    playerStatus->curStateTime++;
                }
                break;
            case SUBSTATE_IDLE_STRETCH:
                // waiting for yawn to finish
                if (playerStatus->animNotifyValue != 0) {
                    playerStatus->actionSubstate++;
                    playerStatus->curStateTime = 0;
                    suggest_player_anim_allow_backward(ANIM_Peach1_Idle);
                }
                break;
            case SUBSTATE_DELAY_SLEEP:
                // delay before next yawn and sleep
                playerStatus->curStateTime++;
                if (playerStatus->curStateTime > 200) {
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
        playerStatus->curStateTime = 0;
        playerStatus->targetYaw = angle;
        set_action_state(ACTION_STATE_WALK);
    }
}
