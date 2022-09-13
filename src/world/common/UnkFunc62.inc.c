#include "common.h"
#include "npc.h"

ApiStatus N(UnkFunc62)(Evt* script, s32 isInitialCall) {
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
    f32 phi_f8;
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
        state->currentPos.x = actor->currentPos.x;
        state->currentPos.y = actor->currentPos.y;
        stateGoalX = state->goalPos.x;
        stateGoalZ = state->goalPos.z;
        stateCurrentX = state->currentPos.x;
        stateCurrentZ = actor->currentPos.z;
        state->currentPos.z = stateCurrentZ;
        state->angle = atan2(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        state->distance = dist2D(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        if (state->moveTime == 0) {
            state->moveTime = state->distance / state->speed;
            phi_f8 = state->distance - (state->moveTime * state->speed);
        } else {
            state->speed = state->distance / state->moveTime;
            phi_f8 = state->distance - (state->moveTime * state->speed);
        }

        if (state->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        state->unk_30.x = (state->goalPos.x - state->currentPos.x) / state->moveTime;
        state->unk_30.y = (state->goalPos.y - state->currentPos.y) / state->moveTime;
        state->unk_30.z = (state->goalPos.z - state->currentPos.z) / state->moveTime;
        state->acceleration = PI_S / state->moveTime;
        state->velocity = 0.0f;
        state->speed += phi_f8 / state->moveTime;

        if (state->moveArcAmplitude < 3) {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            phi_f8 = state->distance;
            phi_f8 -= 20.0;
            phi_f8 /= 6.0;
            phi_f8 += 47.0;
            state->bounceDivisor = phi_f8;
            if (state->moveArcAmplitude == 2) {
                state->bounceDivisor *= 1.12;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            phi_f20 = state->velocity;
            temp_f22_2 = state->acceleration;
            phi_f0 = sin_rad(DEG_TO_RAD(state->unk_24));
            phi_f2 = 0.53;
            state->velocity = phi_f20 + ((phi_f0 * phi_f2 * temp_f22_2) + temp_f22_2);
        } else {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            phi_f8 = state->distance;
            phi_f8 -= 20.0;
            phi_f8 /= 6.0;
            phi_f8 += 47.0;
            state->bounceDivisor = phi_f8;
            if (state->moveArcAmplitude == 4) {
                state->bounceDivisor *= 1.25;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            velocity = state->velocity;
            temp_f22_3 = state->acceleration;
            phi_f0 = sin_rad(DEG_TO_RAD(state->unk_24));
            phi_f2 = 0.8;
            state->velocity = velocity + ((phi_f0 * phi_f2 * temp_f22_3) + temp_f22_3);
        }
        set_animation(ACTOR_SELF, 1, state->animJumpRise);
        sfx_play_sound(SOUND_JUMP_2081);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (state->velocity > PI_S / 2) {
                set_animation(ACTOR_SELF, 1, state->animJumpFall);
            }
            oldActorX = actor->currentPos.x;
            oldActorY = actor->currentPos.y;
            state->currentPos.x += state->unk_30.x;
            state->currentPos.y = state->currentPos.y + state->unk_30.y;
            state->currentPos.z = state->currentPos.z + state->unk_30.z;
            state->unk_18.x = actor->currentPos.y;
            actor->currentPos.x = state->currentPos.x;
            actor->currentPos.y = state->currentPos.y + (state->bounceDivisor * sin_rad(state->velocity));
            actor->currentPos.z = state->currentPos.z;
            if (state->goalPos.y > actor->currentPos.y && state->moveTime < 3) {
                actor->currentPos.y = state->goalPos.y;
            }

            actor->rotation.z = -atan2(oldActorX, -oldActorY, actor->currentPos.x, -actor->currentPos.y);
            state->unk_18.y = actor->currentPos.y;
            if (state->moveArcAmplitude < 3) {
                phi_f20_2 = state->velocity;
                temp_f22_5 = state->acceleration;
                phi_f0_2 = sin_rad(DEG_TO_RAD(state->unk_24));
                phi_f2_2 = 0.53;
                state->velocity = phi_f20_2 + ((phi_f0_2 * phi_f2_2 * temp_f22_5) + temp_f22_5);
            } else {
                temp_f20_6 = state->velocity;
                temp_f22_6 = state->acceleration;
                phi_f0_2 = sin_rad(DEG_TO_RAD(state->unk_24));
                phi_f2_2 = 0.8;
                state->velocity = temp_f20_6 + ((phi_f0_2 * phi_f2_2 * temp_f22_6) + temp_f22_6);
            }

            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            state->moveTime--;
            if (state->moveTime == 0) {
                actor->currentPos.y = state->goalPos.y;
                state->acceleration = 1.8f;
                state->velocity = -(state->unk_18.x - state->unk_18.y);
                set_animation(ACTOR_SELF, 1, state->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 2:
            state->moveTime = 1;
            state->acceleration = 1.8f;
            state->unk_24 = 90.0f;
            state->velocity = -(state->unk_18.x - state->unk_18.y);
            state->bounceDivisor = fabsf(state->unk_18.x - state->unk_18.y) / 16.5;
            state->unk_28 = 360 / state->moveTime;
            state->currentPos.x = actor->currentPos.x;
            state->currentPos.y = actor->currentPos.y;
            state->currentPos.z = actor->currentPos.z;
            script->functionTemp[0] = 3;
            // fallthrough
        case 3:
            currentPosX64 = state->currentPos.x; // required to match
            state->currentPos.x = currentPosX64 + state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24)) / 33.0;
            state->currentPos.y -= state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24));
            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            actor->currentPos.x = state->currentPos.x;
            actor->currentPos.y = state->currentPos.y;
            actor->currentPos.z = state->currentPos.z;

            state->moveTime--;
            if (state->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}
