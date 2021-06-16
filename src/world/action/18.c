#include "common.h"
#include "world/actions.h"

s32 D_802B6300_E248D0[] = {
    0x000A0002, 0x000A002B, 0x000A002D, 0x000A002F, 0x000A0031, 0x000A0033, 0x000A0035, 0x000A0037, 0x000A0039,
    0x000A003B, 0x000A003D, 0x000A003F, 0x000A0041, 0x000A0043, 0x000A0045, 0x000A0047, 0x000A0049, 0x000A004B,
    0x000A004D
};

void func_802B6000_E245D0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 cosTheta;
    f32 sinTheta;
    s32 colliderID;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        func_800E5530();
        if (!(playerStatus->animFlags & 0x1000)) {
            s32 temp;

            if (!(playerStatus->animFlags & 1)) {
                temp = 0x10004;
            } else {
                temp = 0x60000;
            }
            func_800DFEFC(temp);
        } else {
            func_802B6198_E24768();
        }
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
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
        playerStatus->position.y = func_800E3514(playerStatus->gravityIntegrator[0], &colliderID);
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
            func_800DFEFC((D_802B6300_E248D0)[gGameStatusPtr->peachAnimIdx]);
        } else {
            func_800DFEFC(0xD000D); // dood
        }
    } else {
        func_800E636C(world_actions_peachDisguises[gPlayerStatus.peachDisguise].unk_04);
    }
}

void func_802B6230_E24800(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        func_800DFEFC(0xA0005);
        playerStatus->framesOnGround = 8;
    }

    if (playerStatus->framesOnGround != 0) {
        playerStatus->framesOnGround--;
        if (playerStatus->framesOnGround == 4) {
            func_800E5098(1);
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
