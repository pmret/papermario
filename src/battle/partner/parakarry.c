#include "battle/battle.h"
#include "script_api/battle.h"
#include "hud_element.h"
#include "effects.h"
#include "battle/action_cmd/jump.h"
#include "battle/action_cmd/air_lift.h"
#include "battle/action_cmd/air_raid.h"
#include "sprite/npc/BattleParakarry.h"

#define NAMESPACE battle_partner_parakarry

extern HudScript HES_AimMarkerA;
extern HudScript HES_AimMarkerB;
extern HudScript HES_AimMarkerC;
extern HudScript HES_AimMarkerD;
extern HudScript HES_AimMarkerE;
extern HudScript HES_AimMarkerF;
extern HudScript HES_AimReticle;
extern HudScript HES_AimShimmerA;
extern HudScript HES_AimShimmerB;
extern HudScript HES_AimShimmerC;
extern HudScript HES_AimShimmerD;
extern HudScript HES_AimShimmerE;
extern HudScript HES_AimShimmerF;
extern HudScript HES_AimTarget;

extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Init);
extern EvtScript N(firstStrike);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(skyDive);
extern EvtScript N(shellShot);
extern EvtScript N(airLift);
extern EvtScript N(airRaid);

static EffectInstance* airRaidEffect;
static s32 D_8023BD74_unused;
static s32 hudMarkers[7];
static s32 D_8023BD94_unused;
static s32 hudShimmers[6];
static s32 D_8023BDB0_unused;
static s32 hudTarget;
static s32 hudTargetRotation;
static s32 shellShotTimer;
static s32 hudStick;
static s32 hudStickPosX;
static s32 hudStickPosY;

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

API_CALLABLE(N(ShellShotActionCommand)) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    Actor* parakarry = battleStatus->partnerActor;
    ActorState* state = &parakarry->state;
    Actor* targetActor;
    ActorPart* targetActorPart;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;
    f32 aimX, aimY, aimZ;
    f32 clampedAngleDiff, aimAngle;
    s32 hudID, i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            hudMarkers[0] = hudID = hud_element_create(&HES_AimMarkerF);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudMarkers[1] = hudID = hud_element_create(&HES_AimMarkerE);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudMarkers[2] = hudID = hud_element_create(&HES_AimMarkerD);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudMarkers[3] = hudID = hud_element_create(&HES_AimMarkerC);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudMarkers[4] = hudID = hud_element_create(&HES_AimMarkerB);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudMarkers[5] = hudID = hud_element_create(&HES_AimMarkerA);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudMarkers[6] = hudID = hud_element_create(&HES_AimReticle);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            hudShimmers[0] = hudID = hud_element_create(&HES_AimShimmerF);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            hudShimmers[1] = hudID = hud_element_create(&HES_AimShimmerE);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            hudShimmers[2] = hudID = hud_element_create(&HES_AimShimmerD);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            hudShimmers[3] = hudID = hud_element_create(&HES_AimShimmerC);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            hudShimmers[4] = hudID = hud_element_create(&HES_AimShimmerB);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            hudShimmers[5] = hudID = hud_element_create(&HES_AimShimmerA);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            hudTarget = hudID = hud_element_create(&HES_AimTarget);
            hud_element_set_render_depth(hudID, 10);
            hud_element_create_transform_A(hudTarget);
            hud_element_set_render_pos(hudID, -100, -100);
            hudStickPosX = -48;
            hudStickPosY = 80;

            hudStick = hudID = hud_element_create(&HES_StickHoldLeft);
            hud_element_set_render_pos(hudID, hudStickPosX, hudStickPosY);
            hud_element_set_render_depth(hudID, 0);

            set_goal_pos_to_part(state, parakarry->targetActorID, parakarry->targetPartID);
            targetActor = get_actor(parakarry->targetActorID);
            targetActorPart = get_actor_part(targetActor, parakarry->targetPartID);

            state->goalPos.x += targetActorPart->projectileTargetOffset.x * targetActor->scalingFactor;
            state->goalPos.y += targetActorPart->projectileTargetOffset.y * targetActor->scalingFactor;
            state->goalPos.z = state->goalPos.z;
            state->unk_24 = (targetActorPart->size.y + targetActorPart->size.x) / 2 / 24.0;
            hud_element_set_scale(hudTarget, state->unk_24 * targetActor->scalingFactor);
            state->curPos.x = parakarry->curPos.x + 8.0f;
            state->curPos.y = parakarry->curPos.y + 16.0f;
            state->curPos.z = parakarry->curPos.z;
            state->angle = atan2(state->curPos.x, state->curPos.y, state->goalPos.x, state->goalPos.y);
            state->bounceDivisor = state->angle;
            state->dist = 116.0f;
            state->unk_18.x = state->angle;
            i = 0;

            for (i = 0; i < 30; i++) {
                state->unk_18.x -= 1.0f;
                aimAngle = clamp_angle(state->unk_18.x);
                x = state->curPos.x;
                y = state->curPos.y;
                z = state->curPos.z;
                clampedAngleDiff = state->dist;
                add_vec2D_polar(&x, &y, clampedAngleDiff, aimAngle);
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                if (screenY > 180) {
                    break;
                }
            }

            state->unk_18.y = state->angle;
            i = 0;

            for (i = 0; i < 30; i++) {
                state->unk_18.y += 1.0f;
                aimAngle = clamp_angle(state->unk_18.y);
                x = state->curPos.x;
                y = state->curPos.y;
                z = state->curPos.z;
                add_vec2D_polar(&x, &y, state->dist, aimAngle);
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                if (screenY < 30) {
                    break;
                }
            }

            state->moveTime = 120;
            state->angle = state->unk_18.x + rand_int(state->unk_18.y - state->unk_18.x - 2.0f);
            hudTargetRotation = 0;
            shellShotTimer = 90;
#if VERSION_PAL
            state->vel = 4.0f;
#else
            state->vel = 3.0f;
#endif
            battleStatus->actionResult = ACTION_RESULT_FAIL;
            action_command_init_status();
            func_80269118();
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (gActionCommandStatus.autoSucceed || battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                shellShotTimer = 0;
            }

            if (shellShotTimer != 0) {
                shellShotTimer--;
                if (shellShotTimer == 0) {
                    if (rand_int(100) < 50) {
                        state->angle = state->unk_18.x;
                    } else {
                        state->angle = state->unk_18.y;
                    }
                } else {
                    break;
                }
            }

            sfx_play_sound(SOUND_AIM_SHELL_SHOT);
            shellShotTimer = 60;
            script->functionTemp[0] = 2;
            break;
        case 2:
            if (!(gActionCommandStatus.autoSucceed)) {
                if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)) {
                    script->functionTemp[0] = 3;
                    break;
                }
            } else {
                if (shellShotTimer == 0) {
                    targetActor = get_actor(parakarry->targetActorID);
                    aimAngle = fabsf(get_clamped_angle_diff(state->angle, state->bounceDivisor)) / state->unk_24 * targetActor->scalingFactor;

                    if (aimAngle < 3.0f) {
                        script->functionTemp[0] = 3;
                        break;
                    }
                } else {
                    shellShotTimer--;
                }
            }

            state->angle += state->vel;

            if (state->angle <= state->unk_18.x) {
                state->angle = state->unk_18.x;
                state->vel = 0.0f - state->vel;
            }

            if (state->angle >= state->unk_18.y) {
                state->angle = state->unk_18.y;
                state->vel = 0.0f - state->vel;
            }
            break;
        case 3:
            targetActor = get_actor(parakarry->targetActorID);
            clampedAngleDiff = get_clamped_angle_diff(state->angle, state->bounceDivisor);
            aimAngle = fabsf(clampedAngleDiff) / state->unk_24 * targetActor->scalingFactor;

            if (state->vel >= 0.0f) {
                if (clampedAngleDiff < 0.0f) {
                    battleStatus->actionResult = ACTION_RESULT_FAIL;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_EARLY;
                }
            } else if (clampedAngleDiff < 0.0f) {
                battleStatus->actionResult = ACTION_RESULT_EARLY;
            } else {
                battleStatus->actionResult = ACTION_RESULT_FAIL;
            }
            battleStatus->actionQuality = 0;

            if (aimAngle < 7.0f) {
                battleStatus->actionQuality = 1;
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                func_80269160();
            } else if (state->angle < state->bounceDivisor) {
                battleStatus->actionQuality = -1;
            }

            for (i = 0; i < ARRAY_COUNT(hudMarkers); i++) {
                hud_element_free(hudMarkers[i]);
            }

            for (i = 0; i < ARRAY_COUNT(hudShimmers); i++) {
                hud_element_free(hudShimmers[i]);
            }

            hud_element_free(hudTarget);
            hud_element_free(hudStick);
            btl_set_popup_duration(0);
            return ApiStatus_DONE2;
    }

    if (script->functionTemp[0] < 3) {
        if (script->functionTemp[0] > 0) {
            hudID = hudStick;
            targetActor = get_actor(parakarry->targetActorID);
            clampedAngleDiff = get_clamped_angle_diff(state->angle, state->bounceDivisor);
            aimAngle = fabsf(clampedAngleDiff) / state->unk_24 * targetActor->scalingFactor;

            if (aimAngle < 7.0f) {
                hud_element_set_script(hudID, &HES_StickNeutral);
            } else {
                hud_element_set_script(hudID, &HES_StickHoldLeft);
            }

            hudStickPosX += 20;
            if (hudStickPosX >= 51) {
                hudStickPosX = 50;
            }
            hud_element_set_render_pos(hudID, hudStickPosX, hudStickPosY);
        }
    }

    get_screen_coords(gCurrentCameraID, state->goalPos.x, state->goalPos.y, state->goalPos.z, &screenX, &screenY, &screenZ);
    hudID = hudTarget;
    hud_element_set_render_pos(hudID, screenX, screenY);
    hud_element_set_transform_rotation(hudID, 0.0f, 0.0f, hudTargetRotation);
    hudTargetRotation -= 10;
    hudTargetRotation = clamp_angle(hudTargetRotation);

    if (script->functionTemp[0] >= 2) {
        if (script->functionTemp[0] < 3) {
            aimAngle = clamp_angle(state->angle);
            aimX = state->curPos.x;
            aimY = state->curPos.y;
            aimZ = state->curPos.z;
            add_vec2D_polar(&aimX, &aimY, state->dist, aimAngle);
            z = state->curPos.z;
            x = state->curPos.x;
            y = state->curPos.y;

            for (i = 0; i < ARRAY_COUNT(hudShimmers); i++) {
                x += (aimX - state->curPos.x) / 6.0f;
                y += (aimY - state->curPos.y) / 6.0f;
                z += (aimZ - state->curPos.z) / 6.0f;
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                hud_element_set_render_pos(hudMarkers[i], screenX, screenY);
                hudID = hudShimmers[i];
                hud_element_set_render_pos(hudID, screenX, screenY);
            }

            hud_element_set_render_pos(hudMarkers[i], screenX, screenY);
            btl_set_popup_duration(99);
        }
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(GetShellShotDamage)) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 damage = 0;

    switch (battleStatus->partnerActor->actorBlueprint->level) {
        case 0:
            damage = 5;
            break;
        case 1:
            damage = 6;
            break;
        case 2:
            damage = 7;
            break;
    }

    script->varTable[15] = damage;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AirLiftChance)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartID);
    s32 airLiftChance = targetActor->actorBlueprint->airLiftChance;
    s32 hpPercentLost = 100 - targetActor->curHP * 100 / targetActor->maxHP;

    if (targetActor->transparentStatus == STATUS_KEY_TRANSPARENT) {
        airLiftChance = 0;
    }

    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        airLiftChance = 0;
    }

    if (airLiftChance > 0) {
        airLiftChance += airLiftChance * hpPercentLost / 100;

        if (airLiftChance > 100) {
            airLiftChance = 100;
        }

        if (targetActor->debuff != 0) {
            airLiftChance = airLiftChance * 150 / 100;

            if (airLiftChance > 150) {
                airLiftChance = 150;
            }
        }
    }

    script->varTable[0] = airLiftChance;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(CarryAway)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* parakarry = battleStatus->partnerActor;
    ActorState* actorState = &parakarry->state;
    f32* animationRatePtr = &parakarry->partsTable->animationRate;
    Actor* targetActor;
    f64 y;
    u32 temp_s4;

    if (isInitialCall) {
        script->functionTempPtr[1] = get_actor(parakarry->targetActorID);
        script->functionTemp[0] = 0;
    }

    temp_s4 = script->functionTemp[0];
    targetActor = script->functionTempPtr[1];

    switch (script->functionTemp[0]) {
        case 0:
            parakarry->state.goalPos.x = targetActor->curPos.x - parakarry->curPos.x;
            parakarry->state.goalPos.y = targetActor->curPos.y - parakarry->curPos.y;
            parakarry->state.goalPos.z = targetActor->curPos.z - parakarry->curPos.z;
            parakarry->state.speed = 2.0f;
            parakarry->state.moveTime = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            parakarry->state.curPos.x += parakarry->state.speed;
            *animationRatePtr = 1.0f;
            y = parakarry->state.curPos.y;
            parakarry->state.curPos.y = y + (sin_rad(2.0f * sin_rad(DEG_TO_RAD(parakarry->state.moveTime)) * PI_S) * 1.4 + 0.5);
            parakarry->state.moveTime += 6;
            parakarry->state.moveTime = clamp_angle(parakarry->state.moveTime);

            if (gGameStatusPtr->frameCounter % 10 == 0) {
                sfx_play_sound_at_position(SOUND_PARAKARRY_FLAP, SOUND_SPACE_DEFAULT, parakarry->state.curPos.x, parakarry->state.curPos.y, parakarry->state.curPos.z);
            }

            if (parakarry->state.curPos.x > 240.0f) {
                battleStatus->actionQuality = temp_s4;
                return ApiStatus_DONE2;
            }
            break;
    }

    parakarry->curPos.x = actorState->curPos.x;
    parakarry->curPos.y = actorState->curPos.y;
    parakarry->curPos.z = actorState->curPos.z;

    targetActor->curPos.x = actorState->curPos.x + actorState->goalPos.x;
    targetActor->curPos.y = actorState->curPos.y + actorState->goalPos.y;
    targetActor->curPos.z = actorState->curPos.z + actorState->goalPos.z;
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(FlyAround)) {
    Actor* partner = gBattleStatus.partnerActor;
    ActorState* state = &partner->state;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            state->curPos.x = partner->curPos.x;
            state->curPos.y = partner->curPos.y;
            state->curPos.z = partner->curPos.z;
            state->angle = 60 - rand_int(10);
            state->bounceDivisor = 0.0f;
            state->moveTime = 90;
            state->speed = 48.0f;
            script->functionTemp[1] = 0;
            script->functionTemp[2] = 0;
            script->functionTemp[3] = 0;
            airRaidEffect = fx_effect_65(0, state->curPos.x, state->curPos.y, state->curPos.z, 1.0f, 0);
            script->functionTemp[0] = 1;
            break;
        case 1:
            add_vec2D_polar(&state->curPos.x, &state->curPos.y, state->speed, state->angle);
            airRaidEffect->data.unk_65->pos.x = state->curPos.x;
            airRaidEffect->data.unk_65->pos.y = state->curPos.y;
            airRaidEffect->data.unk_65->pos.z = state->curPos.z;
            if (state->curPos.x < -190.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }
                if (state->angle >= 270.0f && state->angle < 360.0f) {
                    state->angle = 90.0f + (90.0f - clamp_angle(state->angle + 180.0f));
                    state->bounceDivisor = rand_int(4) - 2;
                }
                if (state->angle >= 180.0f && state->angle < 270.0f) {
                    state->angle = 90.0f - (clamp_angle(state->angle + 180.0f) - 90.0f);
                    state->bounceDivisor = rand_int(4) - 2;
                }

                if (script->functionTemp[3] != 0) {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_1, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_2, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[3] = 1 - script->functionTemp[3];
            }

            if (state->curPos.x > 190.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }

                do {
                    if (state->angle >= 0.0f && state->angle < 90.0f) {
                        state->angle = 270.0f + (270.0f - clamp_angle(state->angle + 180.0f));
                    } else if (state->angle >= 90.0f && state->angle < 180.0f) {
                        state->angle = 270.0f - (clamp_angle(state->angle + 180.0f) - 270.0f);
                    }
                } while (0);

                if (script->functionTemp[3] != 0) {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_1, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_2, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[3] = 1 - script->functionTemp[3];
            }

            if (state->curPos.y < -30.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }

                do {
                    if (state->angle >= 270.0f && state->angle < 360.0f) {
                        state->angle = 180.0f + (180.0f - clamp_angle(state->angle + 180.0f));
                    } else if (state->angle >= 0.0f && state->angle < 90.0f) {
                        state->angle = 180.0f - (clamp_angle(state->angle + 180.0f) - 180.0f);
                    }
                } while (0); // TODO macro?

                if (script->functionTemp[3] != 0) {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_1, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_2, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[3] = 1 - script->functionTemp[3];
            }

            if (state->curPos.y > 160.0f) {
                if (script->functionTemp[1] != 0) {
                    script->functionTemp[0] = 2;
                    break;
                }

                do {
                    if (state->angle >= 90.0f && state->angle < 180.0f) {
                        state->angle = 360.0f + (360.0f - clamp_angle(state->angle + 180.0f));
                    } else if (state->angle >= 180.0f && state->angle < 270.0f) {
                        state->angle = 360.0f - (clamp_angle(state->angle + 180.0f) - 360.0f);
                    }
                } while (0); // TODO macro?

                if (script->functionTemp[3] != 0) {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_1, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_PARAKARRY_AIR_RAID_2, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                }
                script->functionTemp[3] = 1 - script->functionTemp[3];
            }

            state->angle = clamp_angle(state->angle + (state->bounceDivisor * 0.5));
            if (state->moveTime != 0) {
                state->moveTime--;
            } else {
                script->functionTemp[1] = 1;
            }
            break;
    }

    switch (script->functionTemp[0]) {
        case 2:
            state->moveTime = 5;
            script->functionTemp[0] = 3;
            airRaidEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
            // fallthrough
        case 3:
            add_vec2D_polar(&state->curPos.x, &state->curPos.y, state->speed, state->angle);
            if (state->moveTime == 0) {
                partner->rot.z = 0.0f;
                return ApiStatus_DONE2;
            }
            state->moveTime--;
            // fallthrough
        default:
            partner->curPos.x = state->curPos.x;
            partner->curPos.y = state->curPos.y;
            partner->curPos.z = state->curPos.z;
            return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(GetAirRaidDamage)) {
    script->varTable[15] = ((script->varTable[0] * 100) / 2499) + 2;

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleParakarry_Walk,
    STATUS_KEY_STONE,     ANIM_BattleParakarry_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleParakarry_Pray,
    STATUS_KEY_POISON,    ANIM_BattleParakarry_Still,
    STATUS_KEY_STOP,      ANIM_BattleParakarry_Still,
    STATUS_KEY_DAZE,      ANIM_BattleParakarry_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleParakarry_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 11, 28 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PARAKARRY,
    .level = ACTOR_LEVEL_PARAKARRY,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 38, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 10, 30 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_PARTNER, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_PARTNER, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_PARTNER, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_PARTNER, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(CloseActionCommandInfo)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            SetConst(LVar2, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            Set(LVar2, 22)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar1, ANIM_BattleParakarry_BurnHurt)
            Set(LVar2, 22)
            SetConst(LVar3, ANIM_BattleParakarry_BurnStill)
            ExecWait(EVS_Partner_BurnContact)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_15)
            SetConst(LVar1, ANIM_BattleParakarry_BurnHurt)
            SetConst(LVar2, ANIM_BattleParakarry_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            Set(LVar2, 22)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            SetConst(LVar1, ANIM_BattleParakarry_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar1, ANIM_BattleParakarry_Walk)
            SetConst(LVar2, ANIM_BattleParakarry_Run)
            Set(LVar3, 30)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleParakarry_OrientShell)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ExitShell)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_FIRST_STRIKE)
            ExecWait(N(firstStrike))
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(runAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(runAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleParakarry_Celebrate)
    SetConst(LVar2, ANIM_BattleParakarry_Walk)
    SetConst(LVar3, ANIM_BattleParakarry_Idle)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SKY_DIVE1)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            Set(LVarE, 1)
            Set(LVarF, 2)
            ExecWait(N(skyDive))
        CaseEq(MOVE_SKY_DIVE2)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            Set(LVarE, 2)
            Set(LVarF, 3)
            ExecWait(N(skyDive))
        CaseEq(MOVE_SKY_DIVE3)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            Set(LVarE, 4)
            Set(LVarF, 5)
            ExecWait(N(skyDive))
        CaseEq(MOVE_SHELL_SHOT)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(shellShot))
        CaseEq(MOVE_AIR_LIFT)
            ExecWait(N(airLift))
        CaseEq(MOVE_AIR_RAID)
            ExecWait(N(airRaid))
    EndSwitch
    Return
    End
};

EvtScript N(firstStrike) = {
    Return
    End
};

EvtScript N(runAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleParakarry_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(runAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(returnHome2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(AddGoalPos, ACTOR_PARTNER, -50, 0, 0)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Still)
    ChildThread
        Wait(4)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EndChildThread
    Call(AddGoalPos, ACTOR_PARTNER, -30, 0, 0)
    Call(JumpWithBounce, ACTOR_PARTNER, 5, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    Wait(2)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 0, -5, EASING_LINEAR)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(AddGoalPos, ACTOR_PARTNER, -30, 0, 0)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Still)
    ChildThread
        Wait(4)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EndChildThread
    Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    Call(JumpWithBounce, ACTOR_PARTNER, 5, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    Wait(2)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 0, -5, EASING_LINEAR)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    Return
    End
};

s32 N(actionCommandTable)[] = { 7, 6, 5, 4, 3, 2, 1, 0 };

EvtScript N(skyDive) = {
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(SetActionDifficultyTable, Ref(N(actionCommandTable)))
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(InitTargetIterator)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(5.0))
    Call(FlyToGoal, ACTOR_PARTNER, 0, -10, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Still)
    Wait(3)
    Call(action_command_jump_start, 32, 3)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_PARAKARRY_PREDIVE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_FlyFast)
    Call(AddGoalPos, ACTOR_PARTNER, 0, 10, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    Wait(2)
    ChildThread
        Wait(3)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_PreDive)
    EndChildThread
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(AddGoalPos, ACTOR_PARTNER, -26, 25, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 20, -20, EASING_QUARTIC_OUT)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_PARAKARRY_DIVE)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Dive)
    Call(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        ChildThread
            Wait(5)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
        EndChildThread
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, 40, 10, 0)
        Call(FlyToGoal, ACTOR_PARTNER, 10, -20, EASING_QUADRATIC_OUT)
        Wait(20)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
        Call(FlyToGoal, ACTOR_PARTNER, 0, -5, EASING_LINEAR)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
        Return
    EndIf
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_PostDive)
    Wait(2)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            SetConst(LVarA, ANIM_BattleParakarry_Think)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            SetConst(LVarA, ANIM_BattleParakarry_Dive)
            ExecWait(N(returnHome2))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(shellShot) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_EnterShell)
    Wait(15)
    Call(InitTargetIterator)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFly)
    Call(N(ShellShotActionCommand))
    Call(StopSound, SOUND_AIM_SHELL_SHOT)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_PARAKARRY_SHELL_SHOT)
    Call(GetActionQuality, LVar0)
    Call(PartnerTestEnemy, LVarA, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVarA, HIT_RESULT_MISS)
        Set(LVar0, -2)
    EndIf
    Switch(LVar0)
        CaseEq(1)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
            Call(MoveBattleCamOver, 5)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            Call(FlyToGoal, ACTOR_PARTNER, 7, 0, EASING_LINEAR)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        CaseEq(-1)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
            Call(MoveBattleCamOver, 5)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(AddGoalPos, ACTOR_PARTNER, 50, -50, 0)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            Call(FlyToGoal, ACTOR_PARTNER, 7, 0, 0x00000064)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        CaseEq(0)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
            Call(MoveBattleCamOver, 5)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(AddGoalPos, ACTOR_PARTNER, 50, 50, 0)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            Call(FlyToGoal, ACTOR_PARTNER, 7, 0, EASING_LINEAR)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        CaseEq(-2)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
            Call(MoveBattleCamOver, 5)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            Call(FlyToGoal, ACTOR_PARTNER, 7, 0, EASING_LINEAR)
            Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EndSwitch
    Call(N(GetShellShotDamage))
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_HIT_RATTLE)
        CaseDefault
            Set(LVar0, HIT_RESULT_NO_DAMAGE)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Label(10)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                SetConst(LVarA, ANIM_BattleParakarry_HurtStill)
            Else
                SetConst(LVarA, ANIM_BattleParakarry_Think)
            EndIf
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            SetConst(LVarA, ANIM_BattleParakarry_ShellFly)
            ExecWait(N(returnHome2))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(airLift) = {
    Call(InitTargetIterator)
    Call(N(AirLiftChance))
    Call(LoadActionCommand, ACTION_COMMAND_AIR_LIFT)
    Call(action_command_air_lift_init, LVar0)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(SetActionHudPrepareTime, 0)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(GetDistanceToGoal, ACTOR_PARTNER, LVar0)
    Div(LVar0, 4)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(SetBattleCamOffsetZ, 8)
    Call(MoveBattleCamOver, LVar0)
    Sub(LVar0, 12)
    IfLt(LVar0, 0)
        Set(LVar0, 0)
    EndIf
    Call(SetActionHudPrepareTime, LVar0)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(5.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 0, -4, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    Wait(15)
    Call(SetBattleCamOffsetZ, 0)
    Call(AddBattleCamZoom, -160)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_LiftLight)
    Call(SetAnimationRate, ACTOR_PARTNER, 0, Float(2.0))
    Wait(2)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(CloseActionCommandInfo)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_COS_IN)
        Call(SetAnimationRate, ACTOR_PARTNER, 0, Float(8.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
        Wait(10)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
        Call(SetAnimationRate, ACTOR_PARTNER, 0, Float(1.0))
        Call(SetActorYaw, ACTOR_SELF, 180)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
        Call(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_LINEAR)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
        Return
    EndIf
    Wait(3)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_AIR_LIFT, SUPPRESS_EVENT_SPIKY_FRONT, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    Call(N(AirLiftChance))
    IfNe(LVar0, -1)
        Call(action_command_air_lift_start, 0, 87 * DT, 3, 0)
        Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        ChildThread
            Wait(1)
            Call(GetActionQuality, LVar1)
            Div(LVar1, 10)
            Add(LVar1, 1)
            Loop(88 * DT)
                Call(GetActionQuality, LVar0)
                Set(LVar2, LVar1)
                Mul(LVar2, 10)
                IfGt(LVar0, LVar2)
                    Call(SetBattleCamOffsetZ, 0)
                    Call(AddBattleCamZoom, -2)
                    Call(MoveBattleCamOver, 10)
                    Add(LVar1, 1)
                EndIf
                Wait(1)
            EndLoop
        EndChildThread
        Wait(90 * DT)
        Call(GetActionSuccessCopy, LVar0)
    Else
        Call(CloseActionCommandInfo)
        Set(LVar0, 0)
    EndIf
    Switch(LVar0)
        CaseEq(1)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
            Call(GetOwnerTarget, LVar0, LVar1)
            Call(DispatchEvent, LVar0, EVENT_BLOW_AWAY)
            Call(N(CarryAway), LVar0)
            Wait(30)
            Call(GetOwnerTarget, LVar0, LVar1)
            Call(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, TRUE)
            Call(RemoveActor, LVar0)
        CaseDefault
            Call(GetOwnerTarget, LVar0, LVar1)
            Call(DispatchEvent, LVar0, EVENT_AIR_LIFT_FAILED)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_PARTNER, 5, -10, EASING_COS_IN)
            Call(SetAnimationRate, ACTOR_PARTNER, 0, Float(8.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
            Wait(10)
    EndSwitch
    Call(PartnerYieldTurn)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(12.0))
    Call(SetAnimationRate, ACTOR_PARTNER, 0, Float(1.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_LINEAR)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    Return
    End
};

EvtScript N(airRaid) = {
    Call(LoadActionCommand, ACTION_COMMAND_AIR_RAID)
    Call(action_command_air_raid_init)
    Call(SetupMashMeter, 4, 25, 50, 75, 100, 0)
    Call(SetActionHudPrepareTime, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 70)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 15, -2, EASING_LINEAR)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    Call(action_command_air_raid_start, 0, 90 * DT, 3)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Wait(2)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_PreDive)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 50)
    Add(LVar1, 30)
    Add(LVar2, 40)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_COS_IN_OUT)
    Wait(2)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    ChildThread
        Loop(5)
            Wait(18)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 10, 0)
        EndLoop
    EndChildThread
    ChildThread
        Loop(5)
            Wait(18)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 40, 0)
        EndLoop
    EndChildThread
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
    Call(N(FlyAround))
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 20)
    Call(GetActionQuality, LVar0)
    Call(N(GetAirRaidDamage))
    Call(InitTargetIterator)
    Label(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, 6)
        Goto(11)
    EndIf
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(99)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_HIT_RATTLE)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Wait(5)
    Label(11)
    Call(ChooseNextTarget, ITER_NEXT, LVar0)
    IfNe(LVar0, ITER_NO_MORE)
        Goto(10)
    EndIf
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(99)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EndSwitch
    ChildThread
        Wait(10)
        Call(SetActorPos, ACTOR_PARTNER, -200, 50, 0)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(12.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
        Call(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_LINEAR)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    EndChildThread
    Wait(20)
    Call(PartnerYieldTurn)
    Wait(20)
    Return
    End
};
