#include "common.h"
#include "effects.h"

void surface_standard_behavior(void);
void surface_flowers_behavior(void);
void surface_cloud_behavior(void);
void surface_snow_behavior(void);
void surface_hedges_behavior(void);
void surface_water_behavior(void);

s32 D_80109480 = 0;
f32 D_80109484 = 0.0f;
s16 D_80109488 = 4;
s16 D_8010948A = 0; // unused?
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

SHIFT_BSS s32 D_8010CFF0;
SHIFT_BSS s32 D_8010CFF4;

void func_800EFD00(void) {
}

// Particles (dust, flowers, snow) and etc
void handle_floor_behavior(void) {
    s32 colliderType = 0;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState == ACTION_STATE_JUMP) {
        colliderType = D_80109480;
    }

    D_80109480 = get_collider_flags((u16)gCollisionStatus.curFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;

    if (playerStatus->actionState != ACTION_STATE_JUMP) {
        colliderType = D_80109480;
    }

    if (playerStatus->actionState == ACTION_STATE_LAND && playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        D_8010CFF4 = D_8010CFF0;
    }

    D_8010CFF0 = playerStatus->timeInAir;

    switch (colliderType) {
        case SURFACE_TYPE_FLOWERS:
            surface_flowers_behavior();
            break;
        case SURFACE_TYPE_CLOUD:
            surface_cloud_behavior();
            break;
        case SURFACE_TYPE_SNOW:
            surface_snow_behavior();
            break;
        case SURFACE_TYPE_HEDGES:
            surface_hedges_behavior();
            break;
        case SURFACE_TYPE_WATER:
            surface_water_behavior();
            break;
        default:
            surface_standard_behavior();
            break;
    }
}

void surface_standard_behavior(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinTheta, cosTheta;
    f32 x, y, z;
    s32 cond;

    cond = FALSE;
    if (gGameStatusPtr->areaID == AREA_HOS) {
        cond = gGameStatusPtr->mapID == 2;
    }

    if (playerStatus->actionState == ACTION_STATE_LAND &&
        (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) &&
        D_8010CFF4 >= 10)
    {
        x = playerStatus->pos.x;
        y = playerStatus->pos.y + 0.0f;
        z = playerStatus->pos.z;
        if (!cond) {
            fx_landing_dust(0, x, y, z, D_80109484);
        } else {
            fx_misc_particles(3, x, y, z, 13.0f, 10.0f, 1.0f, 5, 30);

        }
    } else if (
        (playerStatus->actionState == ACTION_STATE_SPIN_POUND || playerStatus->actionState == ACTION_STATE_TORNADO_POUND) && (playerStatus->flags & PS_FLAG_SPECIAL_LAND))
    {
        x = playerStatus->pos.x;
        y = playerStatus->pos.y + 0.0f;
        z = playerStatus->pos.z;
        if (!cond) {
            fx_landing_dust(0, x, y, z, D_80109484);
        } else {
            fx_misc_particles(3, x, y, z, playerStatus->colliderDiameter, 10.0f, 1.0f, 5, 40);
        }
    } else if (playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->curSpeed != 0.0f) {
        if (D_80109488++ >= 4) {
            D_80109488 = 2;
            if (cond) {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(playerStatus->targetYaw)), &sinTheta, &cosTheta);
                fx_misc_particles(
                    3,
                    playerStatus->pos.x + (playerStatus->colliderDiameter * sinTheta),
                    playerStatus->pos.y + 1.5f,
                    playerStatus->pos.z + (playerStatus->colliderDiameter * cosTheta),
                    13.0f, 10.0f, 1.0f, 5, 30
                );
            } else {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sinTheta, &cosTheta);
                fx_walking_dust(
                    0,
                    playerStatus->pos.x + (playerStatus->colliderDiameter * sinTheta * 0.2f),
                    playerStatus->pos.y + 1.5f,
                    playerStatus->pos.z + (playerStatus->colliderDiameter * cosTheta * 0.2f),
                    sinTheta, cosTheta
                );
            }
        }
    } else {
        if (playerStatus->actionState != ACTION_STATE_RUN &&
            !(playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->actionSubstate == 0))
        {
            D_80109488 = 4;
            return;
        }

        if (D_80109488++ >= 4) {
            D_80109488 = 0;
            if (!cond) {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sinTheta, &cosTheta);
                fx_walking_dust(
                    0,
                    playerStatus->pos.x + (playerStatus->colliderDiameter * sinTheta * 0.2f),
                    playerStatus->pos.y + 1.5f,
                    playerStatus->pos.z + (playerStatus->colliderDiameter * cosTheta * 0.2f),
                    sinTheta, cosTheta
                );
            } else {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(playerStatus->targetYaw)), &sinTheta, &cosTheta);
                fx_misc_particles(
                    3,
                    playerStatus->pos.x + (playerStatus->curSpeed * sinTheta),
                    playerStatus->pos.y + 1.5f,
                    playerStatus->pos.z + (playerStatus->curSpeed * cosTheta),
                    13.0f, 10.0f, 1.0f, 5, 30
                );
            }
        }
    }
}

void surface_flowers_behavior(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos, x, y, z;
    f32 t1;

    if (playerStatus->actionState == ACTION_STATE_JUMP && playerStatus->timeInAir == 1 && D_80109492 == 5) {
        z = playerStatus->pos.z; // TODO weird use of temps required to match
        x = playerStatus->pos.y + 14.0f;
        y = D_8010948C;
        fx_flower_splash(playerStatus->pos.x, x, z, y);
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
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sin, &cos);

        colliderDiameter = playerStatus->colliderDiameter;

        x = playerStatus->pos.x + (colliderDiameter * sin * -0.4f);
        z = playerStatus->pos.z + (colliderDiameter * cos * -0.4f);
        y = playerStatus->pos.y + 15.5f;

        fx_flower_trail(0, x, y, z, -playerStatus->curYaw + rand_int(10) - 5.0f, D_80109494);
        D_80109494 = !D_80109494;
    }
}

void surface_cloud_behavior(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinTheta, cosTheta;
    f32 xTemp, xTemp2;
    f32 yTemp, yTemp2;
    f32 zTemp, zTemp2;
    s32 i;

    D_801094A0 += 0.1f;

    if (((playerStatus->actionState == ACTION_STATE_LAND && (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED)) ||
        ((playerStatus->actionState == ACTION_STATE_SPIN_POUND || playerStatus->actionState == ACTION_STATE_TORNADO_POUND) && (playerStatus->flags & PS_FLAG_SPECIAL_LAND))) &&
        D_8010CFF4 >= 10)
    {
        fx_cloud_puff(
            playerStatus->pos.x,
            (playerStatus->pos.y + 14.0f) - 5.0f,
            playerStatus->pos.z, D_80109498
        );
        D_80109498 = clamp_angle(D_80109498 + 35.0f);

        for (i = 0; i < 4; i++) {
            xTemp = rand_int(10) - 5;
            zTemp = rand_int(10) - 5;
            yTemp = -2.0f - ((SQ(xTemp) + SQ(zTemp)) / 5.0f);
            D_8010949C = 0;
            sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw + (i * 90))), &sinTheta, &cosTheta);
            fx_cloud_trail(
                0,
                playerStatus->pos.x + (playerStatus->colliderDiameter * sinTheta * -0.3f) + xTemp,
                playerStatus->pos.y + 15.5f + yTemp,
                playerStatus->pos.z + (playerStatus->colliderDiameter * cosTheta * -0.3f) + zTemp
            );
        }
    } else {
        if (!(playerStatus->actionState == ACTION_STATE_WALK || playerStatus->actionState == ACTION_STATE_RUN) &&
            !(playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->actionSubstate == 0))
        {
            D_8010949C = 0;
            return;
        }
        xTemp2 = rand_int(10) - 5;
        zTemp2 = rand_int(10) - 5;
        yTemp2 = -2.0f - ((SQ(xTemp2) + SQ(zTemp2)) / 5.0f);
        D_8010949C = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sinTheta, &cosTheta);
        fx_cloud_trail(
            1,
            playerStatus->pos.x + (playerStatus->colliderDiameter * sinTheta * -0.3f) + xTemp2,
            playerStatus->pos.y + 15.5f + yTemp2,
            playerStatus->pos.z + (playerStatus->colliderDiameter * cosTheta * -0.3f) + zTemp2
        );
    }
}

void surface_snow_behavior(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos;

    if (!(playerStatus->actionState == ACTION_STATE_WALK ||
          playerStatus->actionState == ACTION_STATE_RUN ||
         (playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->actionSubstate == 0) ||
        ((playerStatus->actionState == ACTION_STATE_LAND || playerStatus->actionState == ACTION_STATE_IDLE)
            && playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED))
    ) {
        D_801094A4 = 4;
        return;
    }

    if (D_801094A4++ >= 4) {
        D_801094A4 = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sin, &cos);
        fx_footprint(
            playerStatus->pos.x + (playerStatus->colliderDiameter * sin * 0.2f),
            playerStatus->pos.y + 1.5f,
            playerStatus->pos.z + (playerStatus->colliderDiameter * cos * 0.2f),
            -playerStatus->curYaw,
            D_801094A8
        );
        D_801094A8 = !D_801094A8;
    }
}

void surface_hedges_behavior(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos;

    if (!(playerStatus->actionState == ACTION_STATE_WALK ||
          playerStatus->actionState == ACTION_STATE_RUN ||
         (playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->actionSubstate == 0) ||
        ((playerStatus->actionState == ACTION_STATE_LAND || playerStatus->actionState == ACTION_STATE_IDLE)
            && playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED))
    ) {
        D_801094AC = 4;
        return;
    }

    if (D_801094AC++ >= 4) {
        D_801094AC = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sin, &cos);
        fx_falling_leaves(
            0,
            playerStatus->pos.x + (playerStatus->colliderDiameter * sin * 0.2f),
            40.0f,
            playerStatus->pos.z + (playerStatus->colliderDiameter * cos * 0.2f)
        );
    }
}

void surface_water_behavior(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sin, cos;

    if (!(playerStatus->actionState == ACTION_STATE_WALK ||
          playerStatus->actionState == ACTION_STATE_RUN ||
         (playerStatus->actionState == ACTION_STATE_SPIN && playerStatus->actionSubstate == 0) ||
        ((playerStatus->actionState == ACTION_STATE_LAND || playerStatus->actionState == ACTION_STATE_IDLE)
            && playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED))
    ) {
        D_801094AE = 4;
        return;
    }

    if (D_801094AE++ >= 4) {
        D_801094AE = 0;
        sin_cos_rad(DEG_TO_RAD(clamp_angle(-playerStatus->curYaw)), &sin, &cos);
        fx_rising_bubble(
            0,
            playerStatus->pos.x + (playerStatus->colliderDiameter * sin * 0.2f),
            playerStatus->pos.y + 0.0f,
            playerStatus->pos.z + (playerStatus->colliderDiameter * cos * 0.2f),
            0.0f
        );
    }
}

void func_800F0C9C(void) {
}
