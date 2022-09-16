#include "common.h"
#include "world/actions.h"

AnimID WalkPeachAnims[] = {
    ANIM_Peach_A0002, // none
    ANIM_Peach_A002B, // cream
    ANIM_Peach_A002D, // strawberry
    ANIM_Peach_A002F, // butter
    ANIM_Peach_A0031, // cleanser
    ANIM_Peach_A0033, // water
    ANIM_Peach_A0035, // milk
    ANIM_Peach_A0037, // flour
    ANIM_Peach_A0039, // egg
    ANIM_Peach_A003B, // complete cake
    ANIM_Peach_A003D, // cake bowl
    ANIM_Peach_A003F, // cake mixed
    ANIM_Peach_A0041, // cake pan
    ANIM_Peach_A0043, // cake batter
    ANIM_Peach_A0045, // cake bare
    ANIM_Peach_A0047, // salt
    ANIM_Peach_A0049, // sugar
    ANIM_Peach_A004B, // cake with icing
    ANIM_Peach_A004D, // cake with berries
    0x00000000
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
    if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        action_update_walk_peach();
        return;
    }

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_800000 | PS_FLAGS_80000);
        playerStatus->unk_60 = 0;
        changedAnim = TRUE;

        if (!(playerStatus->flags & PA_FLAGS_8BIT_MARIO)) {
            playerStatus->currentSpeed = playerStatus->walkSpeed;
        }

        if (playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) {
            anim = ANIM_Mario_90003;
        }
        else if (!(playerStatus->animFlags & PA_FLAGS_HOLDING_WATT)) {
            anim = ANIM_Mario_Walking;
        }
        else {
            anim = ANIM_Mario_60000;
        }
        suggest_player_anim_clearUnkFlag(anim);
    }

    if (playerStatus->flags & PA_FLAGS_8BIT_MARIO) {
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
                if (!(playerStatus->animFlags & PA_FLAGS_80000000)) {
                    if (moveVectorMagnitude >= 20.0f) {
                        playerStatus->targetYaw = moveVectorAngle;
                    }
                }
                playerStatus->animFlags &= ~PA_FLAGS_80000000;
            } else {
                if (playerStatus->animFlags & PA_FLAGS_80000000) {
                    playerStatus->targetYaw = moveVectorAngle;
                } else {
                    playerStatus->animFlags |= PA_FLAGS_80000000;
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
    if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        action_update_run_peach();
        return;
    }

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED |
            PS_FLAGS_800000 | PS_FLAGS_80000);
        D_8010C980 = 0;
        playerStatus->unk_60 = 0;
        phi_s3 = 1;

        if (!(playerStatus->flags & PS_FLAGS_4000)) {
            playerStatus->currentSpeed = playerStatus->runSpeed;
        }
        if (playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) {
            anim = ANIM_Mario_90003;
        } else {
            if (!(playerStatus->animFlags & PA_FLAGS_HOLDING_WATT)) {
                anim = ANIM_Mario_Running;
            } else {
                anim = ANIM_Mario_60002;
            }
        }
        suggest_player_anim_clearUnkFlag(anim);
    }

    if (playerStatus->flags & PS_FLAGS_4000) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    D_8010C980++;
    runSpeedModifier = 1.0f;

    if (playerStatus->animFlags & PA_FLAGS_SPINNING) {
        runSpeedModifier = 1.5f;
    }

    playerStatus->currentSpeed = playerStatus->runSpeed * runSpeedModifier;
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
            if (!(playerStatus->animFlags & PA_FLAGS_80000000)) {
                playerStatus->targetYaw = moveX;
            }
            playerStatus->animFlags &= ~PA_FLAGS_80000000;
        } else {
            if (playerStatus->animFlags & PA_FLAGS_80000000) {
                playerStatus->targetYaw = moveX;
            } else {
                playerStatus->animFlags |= PA_FLAGS_80000000;
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
    if (!(gPlayerStatus.animFlags & PA_FLAGS_IN_DISGUISE)) {
        if (!(gGameStatusPtr->peachFlags & 0x10)) {
            suggest_player_anim_clearUnkFlag(WalkPeachAnims[gGameStatusPtr->peachCookingIngredient]);
            return;
        }
        suggest_player_anim_clearUnkFlag(ANIM_Peach_D000D);
        return;
    }
    peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].walk);
}

static void action_update_walk_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 magnitude;
    f32 angle;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & PS_FLAGS_4000)) {
            playerStatus->currentSpeed = playerStatus->walkSpeed;
        }
        func_802B6550_E23C30();
    }

    if (playerStatus->flags & PS_FLAGS_4000) {
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
    if (gGameStatusPtr->peachCookingIngredient == 0 && sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
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

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & PS_FLAGS_4000)) {
            playerStatus->currentSpeed = playerStatus->runSpeed;
        }

        if (!(playerStatus->animFlags & PA_FLAGS_IN_DISGUISE)) {
            gameStatus = gGameStatusPtr;
            if (!(gameStatus->peachFlags & PEACH_STATUS_FLAG_HAS_INGREDIENT)) {
                if (!gameStatus->peachCookingIngredient) {
                    suggest_player_anim_clearUnkFlag(ANIM_Peach_A0003);
                } else {
                    suggest_player_anim_clearUnkFlag(WalkPeachAnims[gameStatus->peachCookingIngredient]);
                }
            } else {
                suggest_player_anim_clearUnkFlag(ANIM_Peach_D000D);
            }
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].run);
        }
    }

    if (playerStatus->flags & PS_FLAGS_4000) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    playerStatus->currentSpeed = playerStatus->runSpeed;
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
