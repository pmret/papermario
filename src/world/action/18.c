#include "common.h"
#include "world/actions.h"

s32 State18PeachAnims[] = {
    0x000A0002,	// none
    0x000A002B,	// cream
    0x000A002D,	// strawberry
    0x000A002F,	// butter
    0x000A0031,	// cleanser
    0x000A0033,	// water
    0x000A0035,	// milk
    0x000A0037,	// flour
    0x000A0039,	// egg
    0x000A003B,	// complete cake
    0x000A003D,	// cake bowl
    0x000A003F,	// cake mixed
    0x000A0041,	// cake pan
    0x000A0043,	// cake batter
    0x000A0045,	// cake bare
    0x000A0047,	// salt
    0x000A0049,	// sugar
    0x000A004B,	// cake with icing
    0x000A004D,	// cake with berries
    0x00000000
};

void func_802B6000_E245D0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 cosTheta;
    f32 sinTheta;
    s32 colliderID;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        phys_adjust_cam_on_landing();
        if (!(playerStatus->animFlags & 0x1000)) {
            s32 temp;

            if (!(playerStatus->animFlags & 1)) {
                temp = 0x10004;
            } else {
                temp = 0x60000;
            }
            suggest_player_anim_clearUnkFlag(temp);
        } else {
            func_802B6198_E24768();
        }
        playerStatus->fallState = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->gravityIntegrator[0] = 17.7566f;
        playerStatus->gravityIntegrator[1] = -11.3862f;
        playerStatus->gravityIntegrator[2] = 3.5f;
        playerStatus->gravityIntegrator[3] = -0.75f;
    }

    integrate_gravity();
    sin_cos_rad((playerStatus->targetYaw * TAU) / 360.0f, &sinTheta, &cosTheta);
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
    if (!(gPlayerStatus.animFlags & 0x2000)) {
        if (!(gGameStatusPtr->peachFlags & 0x10)) {
            suggest_player_anim_clearUnkFlag((State18PeachAnims)[gGameStatusPtr->peachCookingIngredient]);
        } else {
            suggest_player_anim_clearUnkFlag(0xD000D); // doood
        }
    } else {
        peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].walk);
    }
}

void func_802B6230_E24800(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        suggest_player_anim_clearUnkFlag(0xA0005);
        playerStatus->currentStateTime = 8;
    }

    if (playerStatus->currentStateTime != 0) {
        playerStatus->currentStateTime--;
        if (playerStatus->currentStateTime == 4) {
            try_player_footstep_sounds(1);
        }
    } else {
        if (!(playerStatus->flags & 0x4000)) {
            set_action_state(0);
        } else if (playerStatus->currentSpeed >= playerStatus->runSpeed) {
            set_action_state(2);
        } else {
            set_action_state(1);
        }
    }
}
