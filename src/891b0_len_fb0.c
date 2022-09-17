#include "common.h"
#include "effects.h"

void func_800EFE2C(void);
void func_800F0248(void);
void func_800F0490(void);
void func_800F0864(void);
void func_800F09EC(void);
void func_800F0B3C(void);

s32 D_80109480 = 0;
f32 D_80109484 = 0.0f;
s16 D_80109488[] = {4, 0};
f32 D_8010948C = 0.0f;
s16 D_80109490 = 4;
s16 D_80109492 = 5;
s32 D_80109494 = 0;
f32 D_80109498 = 0.0f;
s16 D_8010949C = 4;
s16 D_8010949E = 0;
f32 D_801094A0 = 0.0f;
s16 D_801094A4 = 4;
s16 D_801094A6 = 0;
s32 D_801094A8 = 0;
s16 D_801094AC = 4;
s16 D_801094AE = 4;

extern s32 D_8010CFF0;
extern s32 D_8010CFF4;

void func_800EFD00(void) {
}

void func_800EFD08(void) {
    s32 colliderType = 0;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState == ACTION_STATE_JUMP) {
        colliderType = D_80109480;
    }

    D_80109480 = get_collider_flags((u16)gCollisionStatus.currentFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;

    if (playerStatus->actionState != ACTION_STATE_JUMP) {
        colliderType = D_80109480;
    }

    if (playerStatus->actionState == ACTION_STATE_LAND && playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        D_8010CFF4 = D_8010CFF0;
    }

    D_8010CFF0 = playerStatus->timeInAir;

    switch (colliderType) {
        case SURFACE_TYPE_FLOWERS:
            func_800F0248();
            break;
        case SURFACE_TYPE_CLOUD:
            func_800F0490();
            break;
        case SURFACE_TYPE_SNOW:
            func_800F0864();
            break;
        case SURFACE_TYPE_HEDGES:
            func_800F09EC();
            break;
        case SURFACE_TYPE_WATER:
            func_800F0B3C();
            break;
        default:
            func_800EFE2C();
            break;
    }
}

INCLUDE_ASM(s32, "891b0_len_fb0", func_800EFE2C);

void func_800F0248(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos, x, y, z;
    f32 t1;

    if (playerStatus->actionState == ACTION_STATE_JUMP && playerStatus->timeInAir == 1 && D_80109492 == 5) {
        z = playerStatus->position.z; // TODO weird use of temps required to match
        x = playerStatus->position.y + 14.0f;
        y = D_8010948C;
        fx_flower_splash(playerStatus->position.x, x, z, y);
        D_8010948C = clamp_angle(D_8010948C + 35.0f);
        D_80109492 = 0;
        return;
    }

    D_80109492++;
    if (D_80109492 > 5) {
        D_80109492 = 5;
    }

    if (
        playerStatus->actionState != ACTION_STATE_WALK && playerStatus->actionState != ACTION_STATE_RUN &&
        !(playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->actionSubstate == 0)
    ) {
        D_80109490 = 0;
        return;
    }

    if (D_80109490++ > 0) {
        f32 colliderDiameter;
        D_80109490 = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->currentYaw)), &sin, &cos);

        colliderDiameter = playerStatus->colliderDiameter;

        x = playerStatus->position.x + (colliderDiameter * sin * -0.4f);
        z = playerStatus->position.z + (colliderDiameter * cos * -0.4f);
        y = playerStatus->position.y + 15.5f;

        fx_flower_trail(0, x, y, z, -playerStatus->currentYaw + rand_int(10) - 5.0f, D_80109494);
        D_80109494 = !D_80109494;
    }
}

INCLUDE_ASM(s32, "891b0_len_fb0", func_800F0490);

void func_800F0864(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos;

    if (playerStatus->actionState != ACTION_STATE_WALK &&
        playerStatus->actionState != ACTION_STATE_RUN &&
        (playerStatus->actionState != ACTION_STATE_SPIN || playerStatus->actionSubstate != 0) &&
        ((playerStatus->actionState != ACTION_STATE_LAND && playerStatus->actionState != ACTION_STATE_IDLE) ||
          playerStatus->flags >= 0)
    ) {
        D_801094A4 = 4;
        return;
    }

    if (D_801094A4++ >= 4) {
        D_801094A4 = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->currentYaw)), &sin, &cos);
        fx_footprint(
            playerStatus->position.x + (playerStatus->colliderDiameter * sin * 0.2f),
            playerStatus->position.y + 1.5f,
            playerStatus->position.z + (playerStatus->colliderDiameter * cos * 0.2f),
            -playerStatus->currentYaw,
            D_801094A8
        );
        D_801094A8 = !D_801094A8;
    }
}

void func_800F09EC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos;

    if (playerStatus->actionState != ACTION_STATE_WALK &&
        playerStatus->actionState != ACTION_STATE_RUN &&
        (playerStatus->actionState != ACTION_STATE_SPIN || playerStatus->actionSubstate != 0) &&
        ((playerStatus->actionState != ACTION_STATE_LAND && playerStatus->actionState != ACTION_STATE_IDLE) ||
          playerStatus->flags >= 0)
    ) {
        D_801094AC = 4;
        return;
    }

    if (D_801094AC++ >= 4) {
        D_801094AC = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->currentYaw)), &sin, &cos);
        fx_falling_leaves(
            0,
            playerStatus->position.x + (playerStatus->colliderDiameter * sin * 0.2f),
            40.0f,
            playerStatus->position.z + (playerStatus->colliderDiameter * cos * 0.2f)
        );
    }
}

void func_800F0B3C(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos;

    if (playerStatus->actionState != ACTION_STATE_WALK &&
        playerStatus->actionState != ACTION_STATE_RUN &&
        (playerStatus->actionState != ACTION_STATE_SPIN || playerStatus->actionSubstate != 0) &&
        ((playerStatus->actionState != ACTION_STATE_LAND && playerStatus->actionState != ACTION_STATE_IDLE) ||
          playerStatus->flags >= 0)
    ) {
        D_801094AE = 4;
        return;
    }

    if (D_801094AE++ >= 4) {
        D_801094AE = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->currentYaw)), &sin, &cos);
        fx_rising_bubble(
            0,
            playerStatus->position.x + (playerStatus->colliderDiameter * sin * 0.2f),
            playerStatus->position.y + 0.0f,
            playerStatus->position.z + (playerStatus->colliderDiameter * cos * 0.2f),
            0.0f
        );
    }
}

void func_800F0C9C(void) {
}
