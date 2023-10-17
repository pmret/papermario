#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc62)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.enemyID);
    ActorState* state = &actor->state;
    f32 stateCurrentX;
    f32 stateCurrentZ;
    f32 stateGoalX;
    f32 stateGoalZ;
    f32 oldActorY;
    f32 oldActorX;
    f64 currentPosX64;
    f32 temp_f8_2;
    f64 velocity;
    f64 temp_f20_6;
    f64 temp_f22_2;
    f64 temp_f22_3;
    f64 temp_f22_5;
    f64 temp_f22_6;
    f32 temp;
    f64 phi_f20;
    f32 phi_f0;
    f64 phi_f2;
    f64 phi_f20_2;
    f32 phi_f0_2;
    f64 phi_f2_2;

    if (isInitialCall) {
        actor->state.moveTime = evt_get_variable(script, *args++);
        actor->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 0;
        if (actor->state.moveArcAmplitude == 1) {
            script->functionTemp[0] = 2;
        }
    }

    if (script->functionTemp[0] == 0) {
        state->curPos.x = actor->curPos.x;
        state->curPos.y = actor->curPos.y;
        stateGoalX = state->goalPos.x;
        stateGoalZ = state->goalPos.z;
        stateCurrentX = state->curPos.x;
        stateCurrentZ = actor->curPos.z;
        state->curPos.z = stateCurrentZ;
        state->angle = atan2(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        state->dist = dist2D(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        if (state->moveTime == 0) {
            state->moveTime = state->dist / state->speed;
            temp = state->dist - (state->moveTime * state->speed);
        } else {
            state->speed = state->dist / state->moveTime;
            temp = state->dist - (state->moveTime * state->speed);
        }

        if (state->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        state->velStep.x = (state->goalPos.x - state->curPos.x) / state->moveTime;
        state->velStep.y = (state->goalPos.y - state->curPos.y) / state->moveTime;
        state->velStep.z = (state->goalPos.z - state->curPos.z) / state->moveTime;
        state->acceleration = PI_S / state->moveTime;
        state->vel = 0.0f;
        state->speed += temp / state->moveTime;

        if (state->moveArcAmplitude < 3) {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            temp = state->dist;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            state->bounceDivisor = temp;
            if (state->moveArcAmplitude == 2) {
                state->bounceDivisor *= 1.12;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            phi_f20 = state->vel;
            temp_f22_2 = state->acceleration;
            phi_f0 = sin_rad(DEG_TO_RAD(state->unk_24));
            phi_f2 = 0.53;
            state->vel = phi_f20 + ((phi_f0 * phi_f2 * temp_f22_2) + temp_f22_2);
        } else {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            temp = state->dist;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            state->bounceDivisor = temp;
            if (state->moveArcAmplitude == 4) {
                state->bounceDivisor *= 1.25;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            velocity = state->vel;
            temp_f22_3 = state->acceleration;
            phi_f0 = sin_rad(DEG_TO_RAD(state->unk_24));
            phi_f2 = 0.8;
            state->vel = velocity + ((phi_f0 * phi_f2 * temp_f22_3) + temp_f22_3);
        }
        set_actor_anim(ACTOR_SELF, 1, state->animJumpRise);
        sfx_play_sound(SOUND_QUICK_PLAYER_JUMP);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (state->vel > PI_S / 2) {
                set_actor_anim(ACTOR_SELF, 1, state->animJumpFall);
            }
            oldActorX = actor->curPos.x;
            oldActorY = actor->curPos.y;
            state->curPos.x += state->velStep.x;
            state->curPos.y = state->curPos.y + state->velStep.y;
            state->curPos.z = state->curPos.z + state->velStep.z;
            state->unk_18.x = actor->curPos.y;
            actor->curPos.x = state->curPos.x;
            actor->curPos.y = state->curPos.y + (state->bounceDivisor * sin_rad(state->vel));
            actor->curPos.z = state->curPos.z;
            if (state->goalPos.y > actor->curPos.y && state->moveTime < 3) {
                actor->curPos.y = state->goalPos.y;
            }

            actor->rot.z = -atan2(oldActorX, -oldActorY, actor->curPos.x, -actor->curPos.y);
            state->unk_18.y = actor->curPos.y;
            if (state->moveArcAmplitude < 3) {
                phi_f20_2 = state->vel;
                temp_f22_5 = state->acceleration;
                phi_f0_2 = sin_rad(DEG_TO_RAD(state->unk_24));
                phi_f2_2 = 0.53;
                state->vel = phi_f20_2 + ((phi_f0_2 * phi_f2_2 * temp_f22_5) + temp_f22_5);
            } else {
                temp_f20_6 = state->vel;
                temp_f22_6 = state->acceleration;
                phi_f0_2 = sin_rad(DEG_TO_RAD(state->unk_24));
                phi_f2_2 = 0.8;
                state->vel = temp_f20_6 + ((phi_f0_2 * phi_f2_2 * temp_f22_6) + temp_f22_6);
            }

            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            state->moveTime--;
            if (state->moveTime == 0) {
                actor->curPos.y = state->goalPos.y;
                state->acceleration = 1.8f;
                state->vel = -(state->unk_18.x - state->unk_18.y);
                set_actor_anim(ACTOR_SELF, 1, state->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 2:
            state->moveTime = 1;
            state->acceleration = 1.8f;
            state->unk_24 = 90.0f;
            state->vel = -(state->unk_18.x - state->unk_18.y);
            state->bounceDivisor = fabsf(state->unk_18.x - state->unk_18.y) / 16.5;
            state->unk_28 = 360 / state->moveTime;
            state->curPos.x = actor->curPos.x;
            state->curPos.y = actor->curPos.y;
            state->curPos.z = actor->curPos.z;
            script->functionTemp[0] = 3;
            // fallthrough
        case 3:
            currentPosX64 = state->curPos.x; // required to match
            state->curPos.x = currentPosX64 + state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24)) / 33.0;
            state->curPos.y -= state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24));
            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            actor->curPos.x = state->curPos.x;
            actor->curPos.y = state->curPos.y;
            actor->curPos.z = state->curPos.z;

            state->moveTime--;
            if (state->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}
