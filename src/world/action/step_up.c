#include "common.h"
#include "world/actions.h"

AnimID StepUpPeachAnims[] = {
    ANIM_Peach1_Walk, // none
    ANIM_Peach1_CarryCream, // cream
    ANIM_Peach1_CarryStrawberry, // strawberry
    ANIM_Peach1_CarryButter, // butter
    ANIM_Peach1_CarryCleanser, // cleanser
    ANIM_Peach1_CarryWater, // water
    ANIM_Peach1_CarryMilk, // milk
    ANIM_Peach1_CarryFlour, // flour
    ANIM_Peach1_CarryEgg, // egg
    ANIM_Peach1_CarryCompleteCake, // complete cake
    ANIM_Peach1_CarryCakeBowl, // cake bowl
    ANIM_Peach1_CarryCakeMixed, // cake mixed
    ANIM_Peach1_CarryCakePan, // cake pan
    ANIM_Peach1_CarryCakeBatter, // cake batter
    ANIM_Peach1_CarryBareCake, // cake bare
    ANIM_Peach1_CarrySalt, // salt
    ANIM_Peach1_CarrySugar, // sugar
    ANIM_Peach1_CarryIcingCake, // cake with icing
    ANIM_Peach1_CarryBerryCake, // cake with berries
    0x00000000
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
    playerStatus->position.x += sinTheta * 3.0f;
    playerStatus->position.z -= cosTheta * 3.0f;

    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        playerStatus->position.y = player_check_collision_below(playerStatus->gravityIntegrator[0], &colliderID);
    } else {
        playerStatus->position.y += playerStatus->gravityIntegrator[0];
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
        playerStatus->currentStateTime = 8;
    }

    if (playerStatus->currentStateTime != 0) {
        playerStatus->currentStateTime--;
        if (playerStatus->currentStateTime == 4) {
            try_player_footstep_sounds(1);
        }
    } else {
        if (!(playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT)) {
            set_action_state(ACTION_STATE_IDLE);
        } else if (playerStatus->currentSpeed >= playerStatus->runSpeed) {
            set_action_state(ACTION_STATE_RUN);
        } else {
            set_action_state(ACTION_STATE_WALK);
        }
    }
}
