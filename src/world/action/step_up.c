#include "common.h"
#include "world/actions.h"

AnimID StepUpPeachAnims[] = {
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

void action_update_step_up(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 cosTheta;
    f32 sinTheta;
    s32 colliderID;
    AnimID anim;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        phys_adjust_cam_on_landing();
        if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
            if (!(playerStatus->animFlags & PA_FLAGS_HOLDING_WATT)) {
                anim = ANIM_Mario_Walking;
            } else {
                anim = ANIM_Mario_60000;
            }
            suggest_player_anim_clearUnkFlag(anim);
        } else {
            func_802B6198_E24768();
        }
        playerStatus->actionSubstate = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->gravityIntegrator[0] = 17.7566f;
        playerStatus->gravityIntegrator[1] = -11.3862f;
        playerStatus->gravityIntegrator[2] = 3.5f;
        playerStatus->gravityIntegrator[3] = -0.75f;
    }

    integrate_gravity();
    sin_cos_rad(DEG_TO_RAD(playerStatus->targetYaw), &sinTheta, &cosTheta);
    colliderID = -1;
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
    if (!(gPlayerStatus.animFlags & PA_FLAGS_IN_DISGUISE)) {
        if (!(gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_HAS_INGREDIENT)) {
            suggest_player_anim_clearUnkFlag((StepUpPeachAnims)[gGameStatusPtr->peachCookingIngredient]);
        } else {
            suggest_player_anim_clearUnkFlag(ANIM_Peach_D000D);
        }
    } else {
        peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].walk);
    }
}

void action_update_step_up_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        suggest_player_anim_clearUnkFlag(ANIM_Peach_A0005);
        playerStatus->currentStateTime = 8;
    }

    if (playerStatus->currentStateTime != 0) {
        playerStatus->currentStateTime--;
        if (playerStatus->currentStateTime == 4) {
            try_player_footstep_sounds(1);
        }
    } else {
        if (!(playerStatus->flags & PS_FLAGS_4000)) {
            set_action_state(ACTION_STATE_IDLE);
        } else if (playerStatus->currentSpeed >= playerStatus->runSpeed) {
            set_action_state(ACTION_STATE_RUN);
        } else {
            set_action_state(ACTION_STATE_WALK);
        }
    }
}
