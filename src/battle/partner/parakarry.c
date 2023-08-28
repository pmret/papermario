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
extern EvtScript N(executeAction);
extern EvtScript N(celebrate);
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

            set_goal_pos_to_part(state, parakarry->targetActorID, parakarry->targetPartIndex);
            targetActor = get_actor(parakarry->targetActorID);
            targetActorPart = get_actor_part(targetActor, parakarry->targetPartIndex);

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
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartIndex);
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
                sfx_play_sound_at_position(SOUND_2009, SOUND_SPACE_DEFAULT, parakarry->state.curPos.x, parakarry->state.curPos.y, parakarry->state.curPos.z);
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
                    sfx_play_sound_at_position(SOUND_200A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_200B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
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
                    sfx_play_sound_at_position(SOUND_200A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_200B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
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
                    sfx_play_sound_at_position(SOUND_200A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_200B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
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
                    sfx_play_sound_at_position(SOUND_200A, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_200B, SOUND_SPACE_DEFAULT, state->curPos.x, state->curPos.y, state->curPos.z);
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
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_PARTNER, EVT_PTR(N(EVS_HandlePhase)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_SET_CONST(LVar2, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Hit)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_SET(LVar2, 22)
            EVT_EXEC_WAIT(EVS_Partner_SpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_BurnHurt)
            EVT_SET(LVar2, 22)
            EVT_SET_CONST(LVar3, ANIM_BattleParakarry_BurnStill)
            EVT_EXEC_WAIT(EVS_Partner_BurnContact)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_15)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleParakarry_BurnStill)
            EVT_EXEC_WAIT(EVS_Partner_BurnHit)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_SET(LVar2, 22)
            EVT_EXEC_WAIT(EVS_Partner_ShockHit)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Walk)
            EVT_SET_CONST(LVar2, ANIM_BattleParakarry_Run)
            EVT_SET(LVar3, 30)
            EVT_EXEC_WAIT(EVS_Partner_Recover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleParakarry_OrientShell)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ExitShell)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(firstStrike))
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(executeAction))
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(N(celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(celebrate) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Celebrate)
    EVT_SET_CONST(LVar2, ANIM_BattleParakarry_Walk)
    EVT_SET_CONST(LVar3, ANIM_BattleParakarry_Idle)
    EVT_EXEC_WAIT(EVS_Partner_Celebrate)
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_STAR_POWERS)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SKY_DIVE1)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(skyDive))
        EVT_CASE_EQ(MOVE_SKY_DIVE2)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 3)
            EVT_EXEC_WAIT(N(skyDive))
        EVT_CASE_EQ(MOVE_SKY_DIVE3)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            EVT_SET(LVarE, 4)
            EVT_SET(LVarF, 5)
            EVT_EXEC_WAIT(N(skyDive))
        EVT_CASE_EQ(MOVE_SHELL_SHOT)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            EVT_EXEC_WAIT(N(shellShot))
        EVT_CASE_EQ(MOVE_AIR_LIFT)
            EVT_EXEC_WAIT(N(airLift))
        EVT_CASE_EQ(MOVE_AIR_RAID)
            EVT_EXEC_WAIT(N(airRaid))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(firstStrike) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleParakarry_Run)
    EVT_EXEC_WAIT(EVS_Partner_RunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -50, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Still)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -30, 0, 0)
    EVT_CALL(JumpWithBounce, ACTOR_PARTNER, 5, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -5, EASING_LINEAR)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, LVarA)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 15, FALSE, FALSE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Still)
    EVT_CHILD_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_END_CHILD_THREAD
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(JumpWithBounce, ACTOR_PARTNER, 5, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -5, EASING_LINEAR)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    EVT_RETURN
    EVT_END
};

s32 N(actionCommandTable)[] = { 7, 6, 5, 4, 3, 2, 1, 0 };

EvtScript N(skyDive) = {
    EVT_CALL(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(actionCommandTable)))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Still)
    EVT_WAIT(3)
    EVT_CALL(action_command_jump_start, 32, 3)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2004)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_FlyFast)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, 0, 10, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CHILD_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_PreDive)
    EVT_END_CHILD_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -26, 25, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, -20, EASING_QUARTIC_OUT)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2005)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Dive)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CHILD_THREAD
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
        EVT_END_CHILD_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 10, 0)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, -20, EASING_QUADRATIC_OUT)
        EVT_WAIT(20)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -5, EASING_LINEAR)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_PostDive)
    EVT_WAIT(2)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarE, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_SET_CONST(LVarA, ANIM_BattleParakarry_Think)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_SET_CONST(LVarA, ANIM_BattleParakarry_Dive)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shellShot) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_EnterShell)
    EVT_WAIT(15)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFly)
    EVT_CALL(N(ShellShotActionCommand))
    EVT_CALL(StopSound, SOUND_AIM_SHELL_SHOT)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2006)
    EVT_CALL(GetActionQuality, LVar0)
    EVT_CALL(PartnerTestEnemy, LVarA, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVarA, HIT_RESULT_MISS)
        EVT_SET(LVar0, -2)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 7, 0, EASING_LINEAR)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        EVT_CASE_EQ(-1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, 50, -50, 0)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 7, 0, 0x00000064)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        EVT_CASE_EQ(0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, 50, 50, 0)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 7, 0, EASING_LINEAR)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        EVT_CASE_EQ(-2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
            EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 7, 0, EASING_LINEAR)
            EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EVT_END_SWITCH
    EVT_CALL(N(GetShellShotDamage))
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_HIT_RATTLE)
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, HIT_RESULT_NO_DAMAGE)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_LABEL(10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_SET_CONST(LVarA, ANIM_BattleParakarry_HurtStill)
            EVT_ELSE
                EVT_SET_CONST(LVarA, ANIM_BattleParakarry_Think)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_SET_CONST(LVarA, ANIM_BattleParakarry_ShellFly)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(airLift) = {
    EVT_CALL(InitTargetIterator)
    EVT_CALL(N(AirLiftChance))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_AIR_LIFT)
    EVT_CALL(action_command_air_lift_init, LVar0)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetDistanceToGoal, ACTOR_PARTNER, LVar0)
    EVT_DIV(LVar0, 4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetBattleCamOffsetZ, 8)
    EVT_CALL(MoveBattleCamOver, LVar0)
    EVT_SUB(LVar0, 12)
    EVT_IF_LT(LVar0, 0)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_CALL(SetActionHudPrepareTime, LVar0)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, -4, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(AddBattleCamZoom, -160)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_LiftLight)
    EVT_CALL(SetAnimationRate, ACTOR_PARTNER, 0, EVT_FLOAT(2.0))
    EVT_WAIT(2)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(CloseActionCommandInfo)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_COS_IN)
        EVT_CALL(SetAnimationRate, ACTOR_PARTNER, 0, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
        EVT_WAIT(10)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetAnimationRate, ACTOR_PARTNER, 0, EVT_FLOAT(1.0))
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_LINEAR)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(3)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_AIR_LIFT, SUPPRESS_EVENT_SPIKY_FRONT, 0, 0, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(N(AirLiftChance))
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(action_command_air_lift_start, 0, 87 * DT, 3, 0)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CHILD_THREAD
            EVT_WAIT(1)
            EVT_CALL(GetActionQuality, LVar1)
            EVT_DIV(LVar1, 10)
            EVT_ADD(LVar1, 1)
            EVT_LOOP(88 * DT)
                EVT_CALL(GetActionQuality, LVar0)
                EVT_SET(LVar2, LVar1)
                EVT_MUL(LVar2, 10)
                EVT_IF_GT(LVar0, LVar2)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(AddBattleCamZoom, -2)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_ADD(LVar1, 1)
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_WAIT(90 * DT)
        EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_ELSE
        EVT_CALL(CloseActionCommandInfo)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(DispatchEvent, LVar0, EVENT_BLOW_AWAY)
            EVT_CALL(N(CarryAway), LVar0)
            EVT_WAIT(30)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_STAR_POINTS_DROPPED, TRUE)
            EVT_CALL(RemoveActor, LVar0)
        EVT_CASE_DEFAULT
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(DispatchEvent, LVar0, EVENT_AIR_LIFT_FAILED)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_PARTNER, 5, -10, EASING_COS_IN)
            EVT_CALL(SetAnimationRate, ACTOR_PARTNER, 0, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
            EVT_WAIT(10)
    EVT_END_SWITCH
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(12.0))
    EVT_CALL(SetAnimationRate, ACTOR_PARTNER, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_LINEAR)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    EVT_RETURN
    EVT_END
};

EvtScript N(airRaid) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_AIR_RAID)
    EVT_CALL(action_command_air_raid_init)
    EVT_CALL(SetupMashMeter, 4, 25, 50, 75, 100, 0)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 70)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, -2, EASING_LINEAR)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Idle)
    EVT_CALL(action_command_air_raid_start, 0, 90 * DT, 3)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_PreDive)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_ADD(LVar1, 30)
    EVT_ADD(LVar2, 40)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_COS_IN_OUT)
    EVT_WAIT(2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    EVT_CHILD_THREAD
        EVT_LOOP(5)
            EVT_WAIT(18)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 10, 0)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(5)
            EVT_WAIT(18)
            EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 40, 0)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_ShellFlyFastest)
    EVT_CALL(N(FlyAround))
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(GetActionQuality, LVar0)
    EVT_CALL(N(GetAirRaidDamage))
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_HIT_RATTLE)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_WAIT(5)
    EVT_LABEL(11)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetActorPos, ACTOR_PARTNER, -200, 50, 0)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(12.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Run)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_LINEAR)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleParakarry_Walk)
    EVT_END_CHILD_THREAD
    EVT_WAIT(20)
    EVT_CALL(PartnerYieldTurn)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};
