#include "common.h"
#include "world/actions.h"
#include "sprite/player.h"

AnimID WalkPeachAnims[] = {
    [PEACH_BAKING_NONE]                 ANIM_Peach1_Walk,
    [PEACH_BAKING_CREAM]                ANIM_Peach1_CarryCream,
    [PEACH_BAKING_STRAWBERRY]           ANIM_Peach1_CarryStrawberry,
    [PEACH_BAKING_BUTTER]               ANIM_Peach1_CarryButter,
    [PEACH_BAKING_CLEANSER]             ANIM_Peach1_CarryCleanser,
    [PEACH_BAKING_WATER]                ANIM_Peach1_CarryWater,
    [PEACH_BAKING_MILK]                 ANIM_Peach1_CarryMilk,
    [PEACH_BAKING_FLOUR]                ANIM_Peach1_CarryFlour,
    [PEACH_BAKING_EGG]                  ANIM_Peach1_CarryEgg,
    [PEACH_BAKING_COMPLETE_CAKE]        ANIM_Peach1_CarryCompleteCake,
    [PEACH_BAKING_CAKE_BOWL]            ANIM_Peach1_CarryCakeBowl,
    [PEACH_BAKING_CAKE_MIXED]           ANIM_Peach1_CarryCakeMixed,
    [PEACH_BAKING_CAKE_PAN]             ANIM_Peach1_CarryCakePan,
    [PEACH_BAKING_CAKE_BATTER]          ANIM_Peach1_CarryCakeBatter,
    [PEACH_BAKING_CAKE_BARE]            ANIM_Peach1_CarryBareCake,
    [PEACH_BAKING_SALT]                 ANIM_Peach1_CarrySalt,
    [PEACH_BAKING_SUGAR]                ANIM_Peach1_CarrySugar,
    [PEACH_BAKING_CAKE_WITH_ICING]      ANIM_Peach1_CarryIcingCake,
    [PEACH_BAKING_CAKE_WITH_BERRIES]    ANIM_Peach1_CarryBerryCake,
};

static void action_update_run_peach(void);
static void action_update_walk_peach(void);

void action_update_walk(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 moveVectorMagnitude;
    f32 moveVectorAngle;
    s32 stickAxisX;
    s32 stickAxisY;
    AnimID anim;
    s32 changedAnim = FALSE;
    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_walk_peach();
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_SCRIPTED_FALL | PS_FLAG_ARMS_RAISED);
        playerStatus->unk_60 = 0;
        changedAnim = TRUE;

        if (!(playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT)) {
            playerStatus->curSpeed = playerStatus->walkSpeed;
        }

        if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
            anim = ANIM_MarioW3_8bit_Run;
        }
        else if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
            anim = ANIM_Mario1_Walk;
        }
        else {
            anim = ANIM_MarioW1_CarryWalk;
        }
        suggest_player_anim_allow_backward(anim);
    }

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(8);
        return;
    }

    player_input_to_move_vector(&moveVectorAngle, &moveVectorMagnitude);
    phys_update_interact_collider();

    if (!check_input_jump()) {
        if (changedAnim != 0 || !check_input_hammer()) {
            player_input_to_move_vector(&moveVectorAngle, &moveVectorMagnitude);
            if (moveVectorMagnitude == 0.0f) {
                set_action_state(ACTION_STATE_IDLE);
                return;
            }

            if (fabsf(PrevPlayerCamRelativeYaw - moveVectorAngle) <= 90.0f && abs(moveVectorMagnitude - D_800F7B44) < 20) {
                if (!(playerStatus->animFlags & PA_FLAG_80000000)) {
                    if (moveVectorMagnitude >= 20.0f) {
                        playerStatus->targetYaw = moveVectorAngle;
                    }
                }
                playerStatus->animFlags &= ~PA_FLAG_80000000;
            } else {
                if (playerStatus->animFlags & PA_FLAG_80000000) {
                    playerStatus->targetYaw = moveVectorAngle;
                } else {
                    playerStatus->animFlags |= PA_FLAG_80000000;
                }
            }

            if (!is_ability_active(ABILITY_SLOW_GO)) {
                stickAxisX = playerStatus->stickAxis[0];
                stickAxisY = playerStatus->stickAxis[1];
                if (SQ(stickAxisX) + SQ(stickAxisY) > SQ(55)) {
                    set_action_state(ACTION_STATE_RUN);
                    return;
                }
            }

            try_player_footstep_sounds(8);
            playerData->walkingStepsTaken++;
        }
    }
}

void action_update_run(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 moveX;
    f32 moveY;
    s32 temp_v1;
    AnimID anim;
    f32 runSpeedModifier;
    s32 phi_s3;

    phi_s3 = 0;
    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        action_update_run_peach();
        return;
    }

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED |
            PS_FLAG_SCRIPTED_FALL | PS_FLAG_ARMS_RAISED);
        D_8010C980 = 0;
        playerStatus->unk_60 = 0;
        phi_s3 = 1;

        if (!(playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT)) {
            playerStatus->curSpeed = playerStatus->runSpeed;
        }
        if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
            anim = ANIM_MarioW3_8bit_Run;
        } else {
            if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                anim = ANIM_Mario1_Run;
            } else {
                anim = ANIM_MarioW1_CarryRun;
            }
        }
        suggest_player_anim_allow_backward(anim);
    }

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    D_8010C980++;
    runSpeedModifier = 1.0f;

    if (playerStatus->animFlags & PA_FLAG_SPINNING) {
        runSpeedModifier = 1.5f;
    }

    playerStatus->curSpeed = playerStatus->runSpeed * runSpeedModifier;
    player_input_to_move_vector(&moveX, &moveY);
    phys_update_interact_collider();
    if (check_input_jump() == FALSE) {
        if (phi_s3 == 0) {
            if (check_input_hammer()) {
                return;
            }
        }

        player_input_to_move_vector(&moveX, &moveY);
        if (moveY == 0.0f) {
            set_action_state(ACTION_STATE_IDLE);
            return;
        }

        if (fabsf(PrevPlayerCamRelativeYaw - moveX) <= 90.0f) {
            if (!(playerStatus->animFlags & PA_FLAG_80000000)) {
                playerStatus->targetYaw = moveX;
            }
            playerStatus->animFlags &= ~PA_FLAG_80000000;
        } else {
            if (playerStatus->animFlags & PA_FLAG_80000000) {
                playerStatus->targetYaw = moveX;
            } else {
                playerStatus->animFlags |= PA_FLAG_80000000;
            }
        }

        if (!is_ability_active(ABILITY_SLOW_GO)) {
            if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) <= 55.0f) {
                set_action_state(ACTION_STATE_WALK);
                return;
            }
        } else {
            set_action_state(ACTION_STATE_WALK);
            return;
        }
        try_player_footstep_sounds(4);
        playerData->runningStepsTaken++;
    }
}

void func_802B6550_E23C30(void) {
    if (!(gPlayerStatus.animFlags & PA_FLAG_INVISIBLE)) {
        if (!(gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_DEPRESSED)) {
            suggest_player_anim_allow_backward(WalkPeachAnims[gGameStatusPtr->peachBakingIngredient]);
            return;
        }
        suggest_player_anim_allow_backward(ANIM_Peach3_WalkSad);
        return;
    }
    peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].walk);
}

static void action_update_walk_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 magnitude;
    f32 angle;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT)) {
            playerStatus->curSpeed = playerStatus->walkSpeed;
        }
        func_802B6550_E23C30();
    }

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(8);
        return;
    }
    player_input_to_move_vector(&angle, &magnitude);
    phys_update_interact_collider();

    if (magnitude == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
        return;
    }

    playerStatus->targetYaw = angle;
    if (gGameStatusPtr->peachBakingIngredient == 0 && sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
        return;
    }

    try_player_footstep_sounds(8);
}

static void action_update_run_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    GameStatus* gameStatus;
    f32 moveX;
    f32 moveY;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT)) {
            playerStatus->curSpeed = playerStatus->runSpeed;
        }

        if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
            gameStatus = gGameStatusPtr;
            if (!(gameStatus->peachFlags & PEACH_STATUS_FLAG_DEPRESSED)) {
                if (!gameStatus->peachBakingIngredient) {
                    suggest_player_anim_allow_backward(ANIM_Peach1_Run);
                } else {
                    suggest_player_anim_allow_backward(WalkPeachAnims[gameStatus->peachBakingIngredient]);
                }
            } else {
                suggest_player_anim_allow_backward(ANIM_Peach3_WalkSad);
            }
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].run);
        }
    }

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    playerStatus->curSpeed = playerStatus->runSpeed;
    player_input_to_move_vector(&moveX, &moveY);
    phys_update_interact_collider();
    if (moveY == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
        return;
    }

    playerStatus->targetYaw = moveX;
    if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) < 55.0f) {
        set_action_state(ACTION_STATE_WALK);
        return;
    } else {
        try_player_footstep_sounds(4);
    }
}
