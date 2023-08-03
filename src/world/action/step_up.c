#include "common.h"
#include "world/actions.h"
#include "sprite/player.h"

AnimID StepUpPeachAnims[] = {
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

void func_802B6198_E24768(void);

void action_update_step_up(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 cosTheta;
    f32 sinTheta;
    s32 colliderID;
    AnimID anim;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        phys_adjust_cam_on_landing();
        if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
            if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                anim = ANIM_Mario1_Walk;
            } else {
                anim = ANIM_MarioW1_CarryWalk;
            }
            suggest_player_anim_allow_backward(anim);
        } else {
            func_802B6198_E24768();
        }
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->peakJumpTime = 0;
        playerStatus->gravityIntegrator[0] = 17.7566f;
        playerStatus->gravityIntegrator[1] = -11.3862f;
        playerStatus->gravityIntegrator[2] = 3.5f;
        playerStatus->gravityIntegrator[3] = -0.75f;
    }

    integrate_gravity();
    sin_cos_rad(DEG_TO_RAD(playerStatus->targetYaw), &sinTheta, &cosTheta);
    colliderID = NO_COLLIDER;
    playerStatus->pos.x += sinTheta * 3.0f;
    playerStatus->pos.z -= cosTheta * 3.0f;

    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        playerStatus->pos.y = player_check_collision_below(playerStatus->gravityIntegrator[0], &colliderID);
    } else {
        playerStatus->pos.y += playerStatus->gravityIntegrator[0];
    }

    if (colliderID >= 0) {
        if (playerStatus->prevActionState != ACTION_STATE_SPIN) {
            set_action_state(playerStatus->prevActionState);
        } else {
            update_locomotion_state();
        }
    }
}

void func_802B6198_E24768(void) {
    if (!(gPlayerStatus.animFlags & PA_FLAG_INVISIBLE)) {
        if (!(gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_DEPRESSED)) {
            suggest_player_anim_allow_backward(StepUpPeachAnims[gGameStatusPtr->peachBakingIngredient]);
        } else {
            suggest_player_anim_allow_backward(ANIM_Peach3_WalkSad);
        }
    } else {
        peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].walk);
    }
}

void action_update_step_up_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        suggest_player_anim_allow_backward(ANIM_Peach1_StepUp);
        playerStatus->curStateTime = 8;
    }

    if (playerStatus->curStateTime != 0) {
        playerStatus->curStateTime--;
        if (playerStatus->curStateTime == 4) {
            try_player_footstep_sounds(1);
        }
    } else {
        if (!(playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT)) {
            set_action_state(ACTION_STATE_IDLE);
        } else if (playerStatus->curSpeed >= playerStatus->runSpeed) {
            set_action_state(ACTION_STATE_RUN);
        } else {
            set_action_state(ACTION_STATE_WALK);
        }
    }
}
