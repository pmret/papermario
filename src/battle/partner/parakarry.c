#include "common.h"
#include "battle/battle.h"
#include "hud_element.h"
#include "effects.h"

extern s32 D_8023BD78[7];
extern s32 D_8023BD98[6];
extern s32 D_8023BDB4;
extern s32 D_8023BDB8;
extern s32 D_8023BDBC;
extern s32 D_8023BDC0;
extern s32 D_8023BDC4;
extern s32 D_8023BDC8;
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
extern HudScript HES_StickHoldLeft;
extern HudScript HES_StickNeutral;

extern f64 D_8023BD60_703AE0;

ApiStatus func_80238000_6FFD80(Evt* evt, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    Actor* parakarry = battleStatus->partnerActor;
    ActorState* state = &parakarry->state;
    Actor* targetActor;
    ActorPart* targetActorPart;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;
    f32 tempX, tempY, tempZ;
    f32 clampedAngleDiff, tempAngle;
    s32 hudID, i;

    if (isInitialCall) {
        evt->functionTemp[0] = 0;
    }

    switch (evt->functionTemp[0]) {
        case 0:
            D_8023BD78[0] = hudID = hud_element_create(&HES_AimMarkerF);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD78[1] = hudID = hud_element_create(&HES_AimMarkerE);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD78[2] = hudID = hud_element_create(&HES_AimMarkerD);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD78[3] = hudID = hud_element_create(&HES_AimMarkerC);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD78[4] = hudID = hud_element_create(&HES_AimMarkerB);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD78[5] = hudID = hud_element_create(&HES_AimMarkerA);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD78[6] = hudID = hud_element_create(&HES_AimReticle);
            hud_element_set_render_depth(hudID, 10);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD98[0] = hudID = hud_element_create(&HES_AimShimmerF);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD98[1] = hudID = hud_element_create(&HES_AimShimmerE);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD98[2] = hudID = hud_element_create(&HES_AimShimmerD);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD98[3] = hudID = hud_element_create(&HES_AimShimmerC);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD98[4] = hudID = hud_element_create(&HES_AimShimmerB);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BD98[5] = hudID = hud_element_create(&HES_AimShimmerA);
            hud_element_set_render_depth(hudID, 9);
            hud_element_set_render_pos(hudID, -100, -100);

            D_8023BDB4 = hudID = hud_element_create(&HES_AimTarget);
            hud_element_set_render_depth(hudID, 10);
            hud_element_create_transform_A(D_8023BDB4);
            hud_element_set_render_pos(hudID, -100, -100);
            D_8023BDC4 = -48;
            D_8023BDC8 = 80;

            D_8023BDC0 = hudID = hud_element_create(&HES_StickHoldLeft);
            hud_element_set_render_pos(hudID, D_8023BDC4, D_8023BDC8);
            hud_element_set_render_depth(hudID, 0);

            set_goal_pos_to_part(state, parakarry->targetActorID, parakarry->targetPartIndex);
            targetActor = get_actor(parakarry->targetActorID);
            targetActorPart = get_actor_part(targetActor, parakarry->targetPartIndex);

            state->goalPos.x += targetActorPart->unk_75 * targetActor->scalingFactor;
            state->goalPos.y += targetActorPart->unk_76 * targetActor->scalingFactor;
            state->goalPos.z = state->goalPos.z;
            state->unk_24 = (targetActorPart->size.y + targetActorPart->size.x) / 2 / 24.0;
            hud_element_set_scale(D_8023BDB4, state->unk_24 * targetActor->scalingFactor);
            state->currentPos.x = parakarry->currentPos.x + 8.0f;
            state->currentPos.y = parakarry->currentPos.y + 16.0f;
            state->currentPos.z = parakarry->currentPos.z;
            state->angle = atan2(state->currentPos.x, state->currentPos.y, state->goalPos.x, state->goalPos.y);
            state->bounceDivisor = state->angle;
            state->distance = 116.0f;
            state->unk_18.x = state->angle;
            i = 0;

            for (i = 0; i < 30; i++) {
                state->unk_18.x -= 1.0f;
                tempAngle = clamp_angle(state->unk_18.x);
                x = state->currentPos.x;
                y = state->currentPos.y;
                z = state->currentPos.z;
                clampedAngleDiff = state->distance;
                add_vec2D_polar(&x, &y, clampedAngleDiff, tempAngle);
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                if (screenY > 180) {
                    break;
                }
            }

            state->unk_18.y = state->angle;
            i = 0;

            for (i = 0; i < 30; i++) {
                state->unk_18.y += 1.0f;
                tempAngle = clamp_angle(state->unk_18.y);
                x = state->currentPos.x;
                y = state->currentPos.y;
                z = state->currentPos.z;
                add_vec2D_polar(&x, &y, state->distance, tempAngle);
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                if (screenY < 30) {
                    break;
                }
            }

            state->moveTime = 120;
            state->angle = state->unk_18.x + rand_int(state->unk_18.y - state->unk_18.x - 2.0f);
            D_8023BDB8 = 0;
            D_8023BDBC = 90;
            state->velocity = 3.0f;
            battleStatus->unk_86 = 0;
            func_80268858();
            func_80269118();
            evt->functionTemp[0] = 1;
            break;
        case 1:
            if (gActionCommandStatus.autoSucceed || battleStatus->currentButtonsDown & BUTTON_STICK_LEFT) {
                D_8023BDBC = 0;
            }

            if (D_8023BDBC != 0) {
                D_8023BDBC--;
                if (D_8023BDBC == 0) {
                    if (rand_int(100) < 50) {
                        state->angle = state->unk_18.x;
                    } else {
                        state->angle = state->unk_18.y;
                    }
                } else {
                    break;
                }
            }

            sfx_play_sound(SOUND_311);
            D_8023BDBC = 60;
            evt->functionTemp[0] = 2;
            break;
        case 2:
            if (!(gActionCommandStatus.autoSucceed)) {
                if (!(battleStatus->currentButtonsDown & BUTTON_STICK_LEFT)) {
                    evt->functionTemp[0] = 3;
                    break;
                }
            } else {
                if (D_8023BDBC == 0) {
                    targetActor = get_actor(parakarry->targetActorID);
                    tempAngle = fabsf(get_clamped_angle_diff(state->angle, state->bounceDivisor)) / state->unk_24 * targetActor->scalingFactor;

                    if (tempAngle < 3.0f) {
                        evt->functionTemp[0] = 3;
                        break;
                    }
                } else {
                    D_8023BDBC--;
                }
            }

            state->angle += state->velocity;

            if (state->angle <= state->unk_18.x) {
                state->angle = state->unk_18.x;
                state->velocity = 0.0f - state->velocity;
            }

            if (state->angle >= state->unk_18.y) {
                state->angle = state->unk_18.y;
                state->velocity = 0.0f - state->velocity;
            }
            break;
        case 3:
            targetActor = get_actor(parakarry->targetActorID);
            clampedAngleDiff = get_clamped_angle_diff(state->angle, state->bounceDivisor);
            tempAngle = fabsf(clampedAngleDiff) / state->unk_24 * targetActor->scalingFactor;

            if (state->velocity >= 0.0f) {
                if (clampedAngleDiff < 0.0f) {
                    battleStatus->unk_86 = 0;
                } else {
                    battleStatus->unk_86 = -1;
                }
            } else if (clampedAngleDiff < 0.0f) {
                battleStatus->unk_86 = -1;
            } else {
                battleStatus->unk_86 = 0;
            }
            battleStatus->unk_84 = 0;

            if (tempAngle < 7.0f) {
                battleStatus->unk_84 = 1;
                battleStatus->unk_86 = 1;
                func_80269160();
            } else if (state->angle < state->bounceDivisor) {
                battleStatus->unk_84 = -1;
            }

            for (i = 0; i < ARRAY_COUNT(D_8023BD78); i++) {
                hud_element_free(D_8023BD78[i]);
            }

            for (i = 0; i < ARRAY_COUNT(D_8023BD98); i++) {
                hud_element_free(D_8023BD98[i]);
            }

            hud_element_free(D_8023BDB4);
            hud_element_free(D_8023BDC0);
            btl_set_popup_duration(0);
            return ApiStatus_DONE2;
    }

    if (evt->functionTemp[0] < 3) {
        if (evt->functionTemp[0] > 0) {
            hudID = D_8023BDC0;
            targetActor = get_actor(parakarry->targetActorID);
            clampedAngleDiff = get_clamped_angle_diff(state->angle, state->bounceDivisor);
            tempAngle = fabsf(clampedAngleDiff) / state->unk_24 * targetActor->scalingFactor;

            if (tempAngle < 7.0f) {
                hud_element_set_script(hudID, &HES_StickNeutral);
            } else {
                hud_element_set_script(hudID, &HES_StickHoldLeft);
            }

            D_8023BDC4 += 20;
            if (D_8023BDC4 >= 51) {
                D_8023BDC4 = 50;
            }
            hud_element_set_render_pos(hudID, D_8023BDC4, D_8023BDC8);
        }
    }

    get_screen_coords(gCurrentCameraID, state->goalPos.x, state->goalPos.y, state->goalPos.z, &screenX, &screenY, &screenZ);
    hudID = D_8023BDB4;
    hud_element_set_render_pos(hudID, screenX, screenY);
    hud_element_set_transform_rotation(hudID, 0.0f, 0.0f, D_8023BDB8);
    D_8023BDB8 -= 10;
    D_8023BDB8 = clamp_angle(D_8023BDB8);

    if (evt->functionTemp[0] >= 2) {
        if (evt->functionTemp[0] < 3) {
            tempAngle = clamp_angle(state->angle);
            tempX = state->currentPos.x;
            tempY = state->currentPos.y;
            tempZ = state->currentPos.z;
            add_vec2D_polar(&tempX, &tempY, state->distance, tempAngle);
            z = state->currentPos.z;
            x = state->currentPos.x;
            y = state->currentPos.y;

            for (i = 0; i < ARRAY_COUNT(D_8023BD98); i++) {
                x += (tempX - state->currentPos.x) / 6.0f;
                y += (tempY - state->currentPos.y) / 6.0f;
                z += (tempZ - state->currentPos.z) / 6.0f;
                get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);
                hud_element_set_render_pos(D_8023BD78[i], screenX, screenY);
                hudID = D_8023BD98[i];
                hud_element_set_render_pos(hudID, screenX, screenY);
            }

            hud_element_set_render_pos(D_8023BD78[i], screenX, screenY);
            btl_set_popup_duration(99);
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238C88_700A08(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var0 = 0;

    switch (battleStatus->partnerActor->actorBlueprint->level) {
        case 0:
            var0 = 5;
            break;
        case 1:
            var0 = 6;
            break;
        case 2:
            var0 = 7;
            break;
    }

    script->varTable[15] = var0;
    return ApiStatus_DONE2;
}

ApiStatus func_80238CE0_700A60(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartIndex);
    s32 airLiftChance = targetActor->actorBlueprint->airLiftChance;
    s32 hpPercentLost = 100 - (targetActor->currentHP * 100) / targetActor->maxHP;

    if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
        airLiftChance = 0;
    }

    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        airLiftChance = 0;
    }

    if (airLiftChance > 0) {
        airLiftChance = airLiftChance + ((airLiftChance * hpPercentLost) / 100);

        if (airLiftChance > 100) {
            airLiftChance = 100;
        }

        if (targetActor->debuff != 0) {
            airLiftChance = (airLiftChance * 150) / 100;

            if (airLiftChance > 150) {
                airLiftChance = 150;
            }
        }
    }

    script->varTable[0] = airLiftChance;

    return ApiStatus_DONE2;
}

ApiStatus func_80238E24_700BA4(Evt* evt, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* parakarry = battleStatus->partnerActor;
    ActorState* actorState = &parakarry->state;
    f32* animationRatePtr = &parakarry->partsTable->animationRate;
    Actor* targetActor;
    f64 y;
    u32 temp_s4;

    if (isInitialCall) {
        evt->functionTempPtr[1] = get_actor(parakarry->targetActorID);
        evt->functionTemp[0] = 0;
    }

    temp_s4 = evt->functionTemp[0];
    targetActor = evt->functionTempPtr[1];

    switch (evt->functionTemp[0]) {
        case 0:
            parakarry->state.goalPos.x = targetActor->currentPos.x - parakarry->currentPos.x;
            parakarry->state.goalPos.y = targetActor->currentPos.y - parakarry->currentPos.y;
            parakarry->state.goalPos.z = targetActor->currentPos.z - parakarry->currentPos.z;
            parakarry->state.speed = 2.0f;
            parakarry->state.moveTime = 0;
            evt->functionTemp[0] = 1;
            break;
        case 1:
            parakarry->state.currentPos.x += parakarry->state.speed;
            *animationRatePtr = 1.0f;
            y = parakarry->state.currentPos.y;
            parakarry->state.currentPos.y = y + (sin_rad(2.0f * sin_rad(DEG_TO_RAD(parakarry->state.moveTime)) * PI_S) * D_8023BD60_703AE0 + 0.5);
            parakarry->state.moveTime += 6;
            parakarry->state.moveTime = clamp_angle(parakarry->state.moveTime);

            if (gGameStatusPtr->frameCounter % 10 == 0) {
                sfx_play_sound_at_position(SOUND_2009, 0, parakarry->state.currentPos.x, parakarry->state.currentPos.y, parakarry->state.currentPos.z);
            }

            if (parakarry->state.currentPos.x > 240.0f) {
                battleStatus->unk_84 = temp_s4;
                return ApiStatus_DONE2;
            }
            break;
    }

    parakarry->currentPos.x = actorState->currentPos.x;
    parakarry->currentPos.y = actorState->currentPos.y;
    parakarry->currentPos.z = actorState->currentPos.z;

    targetActor->currentPos.x = actorState->currentPos.x + actorState->goalPos.x;
    targetActor->currentPos.y = actorState->currentPos.y + actorState->goalPos.y;
    targetActor->currentPos.z = actorState->currentPos.z + actorState->goalPos.z;
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "battle/partner/parakarry", func_802390B4_700E34);

ApiStatus func_802397C8_701548(Evt* script, s32 isInitialCall) {
    script->varTable[15] = ((script->varTable[0] * 100) / 2499) + 2;

    return ApiStatus_DONE2;
}
