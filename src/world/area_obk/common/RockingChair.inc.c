#include "common.h"
#include "model.h"

#ifndef ROCKING_CHAIR_CENTER_X
#error ROCKING_CHAIR_CENTER_X is not defined!
#endif

/*
    Also assumes the following are defined:
    MODEL_i1, MODEL_i2, MODEL_i3
    COLLIDER_i1, COLLIDER_i2, COLLIDER_i3
*/

typedef struct RockingChairPhysics {
    /* 0x00 */ f32 angleDelta;
    /* 0x04 */ f32 angularAccel;
    /* 0x08 */ f32 rotAngle;
    /* 0x0C */ f32 verticalOffset;
    /* 0x10 */ f32 angleB;
    /* 0x14 */ f32 angleA;
    /* 0x18 */ f32 mass;
    /* 0x1C */ f32 equilibriumAngle;
} RockingChairPhysics; // size = 0x20

enum RockingChairState {
    CHAIR_STATE_INITIAL             = 0,
    CHAIR_STATE_PLAYER_TOUCHING     = 1,
    CHAIR_STATE_PLAYER_NOT_TOUCHING = 2
};

API_CALLABLE(N(UpdateRockingChair)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    RockingChairPhysics* physics;
    f32 centerX, centerY, centerZ;
    Matrix4f tempMtx;
    Model* model;
    s16 currentFloor;

    if (isInitialCall) {
        physics = heap_malloc(sizeof(*physics));
        script->functionTempPtr[1] = physics;
        physics->angleDelta = 0;
        physics->verticalOffset = 0;
        physics->rotAngle = 0;
        physics->angleB = 0;
        physics->angleA = 0;
        physics->angularAccel = 0.1f;
        physics->mass = 3.0f;
        script->functionTemp[0] = CHAIR_STATE_INITIAL;
        script->functionTemp[2] = 0;
        script->functionTemp[3] = 0;
    }

    physics = script->functionTempPtr[1];
    switch (script->functionTemp[0]) {
        case CHAIR_STATE_INITIAL:
            if (collisionStatus->curFloor == COLLIDER_i3) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }
            if (collisionStatus->curFloor == COLLIDER_i2) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }
            physics->angleDelta = 0.0f;
            physics->verticalOffset = 0.0f;
            physics->angleB = 0.0f;
            physics->angleA = 0.0f;
            physics->rotAngle = 0.0f;
            physics->angularAccel = 0.1f;
            physics->mass = 3.0f;
            physics->equilibriumAngle = 20.0f;
            break;
        case CHAIR_STATE_PLAYER_TOUCHING:
            //TODO odd match
            currentFloor = collisionStatus->curFloor;
            if (currentFloor != COLLIDER_i3 && collisionStatus->curFloor != COLLIDER_i2) {
                script->functionTemp[3] = 120; // settle time
                script->functionTemp[0] = CHAIR_STATE_PLAYER_NOT_TOUCHING;
            }
            if (fabsf(physics->rotAngle) < 5.0f) {
                physics->angularAccel = fabsf(ROCKING_CHAIR_CENTER_X - playerStatus->pos.x) / 200.0f;
            } else {
                physics->angularAccel = 0.1f;
            }
            if (playerStatus->pos.x <= ROCKING_CHAIR_CENTER_X) {
                physics->angleB += physics->angularAccel;
                physics->equilibriumAngle = SQ(fabsf(ROCKING_CHAIR_CENTER_X - playerStatus->pos.x)) / 50.0f;
                if (physics->equilibriumAngle > 15.0f) {
                    physics->equilibriumAngle = 15.0f;
                }
                if (physics->rotAngle > physics->equilibriumAngle) {
                    physics->angleA += physics->angularAccel * physics->mass;
                }
            } else {
                physics->angleA += physics->angularAccel;
                physics->equilibriumAngle = -SQ(-fabsf(ROCKING_CHAIR_CENTER_X - playerStatus->pos.x) * 0.5f) / 50.0f;
                if (physics->equilibriumAngle < -5.0f) {
                    physics->equilibriumAngle = -5.0f;
                }
                if (physics->rotAngle < physics->equilibriumAngle) {
                    physics->angleB += physics->angularAccel * physics->mass;
                }
            }
            if ((physics->angleB > 100.0) && (physics->angleA > 100.0)) {
                physics->angleB -= 100.0;
                physics->angleA -= 100.0;
            }
            // clamp difference to 1.5 degrees
            if (fabsf(physics->angleB - physics->angleA) > 1.5) {
                if (physics->angleA > physics->angleB) {
                    physics->angleA = physics->angleB + 1.5;
                } else {
                    physics->angleB = physics->angleA + 1.5;
                }
            }
            physics->angleDelta = physics->angleB - physics->angleA;
            physics->rotAngle += physics->angleDelta;
            break;
        case CHAIR_STATE_PLAYER_NOT_TOUCHING:
            if (collisionStatus->curFloor == COLLIDER_i3) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }
            if (collisionStatus->curFloor == COLLIDER_i2) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }

            physics->angularAccel = 0.1f;
            physics->equilibriumAngle = 0;
            physics->angleB += physics->angularAccel;

            if (physics->rotAngle > physics->equilibriumAngle) {
                physics->angleA += physics->angularAccel * physics->mass;
            }
            if ((physics->angleB > 100.0) && ( physics->angleA > 100.0)) {
                physics->angleB -= 100.0;
                physics->angleA -= 100.0;
            }

            if (fabsf(physics->angleB - physics->angleA) > 0.5) {
                if (physics->angleA > physics->angleB) {
                    physics->angleA = physics->angleB + 0.5;
                } else {
                    physics->angleB = physics->angleA + 0.5;
                }
            }
            if (script->functionTemp[3] < 0) {
                f32 zero = 0.0f;
                physics->angleA = zero;
                physics->angleB = zero;
                physics->angleDelta = zero;
                physics->rotAngle = zero;
            } else {
                script->functionTemp[3]--;
            }
            physics->angleDelta = physics->angleB - physics->angleA;
            physics->rotAngle += physics->angleDelta;
            break;
    }

    // play creak sound once per cycle
    if (physics->rotAngle <= -7.0f) {
        if (script->functionTemp[2] != -1) {
            get_collider_center(COLLIDER_i3, &centerX, &centerY, &centerZ);
            sfx_play_sound_at_position(SOUND_CREAKY_ROCKING, SOUND_SPACE_DEFAULT, centerX, centerY, centerZ);
            script->functionTemp[2] = -1;
        }
    } else {
        script->functionTemp[2] = 0;
    }

    physics->verticalOffset = SQ(physics->rotAngle) / 90.0f;

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_i3));
    model->flags |= (MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM);
    guTranslateF(model->userTransformMtx, 0.0f, physics->verticalOffset, 0.0f);
    guRotateF(tempMtx, physics->rotAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->userTransformMtx, tempMtx, model->userTransformMtx);
    update_collider_transform(COLLIDER_i3);
    update_collider_transform(COLLIDER_i2);

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_i2));
    model->flags |= (MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM);
    guTranslateF(model->userTransformMtx, 0.0f, physics->verticalOffset, 0.0f);
    guRotateF(tempMtx, physics->rotAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->userTransformMtx, tempMtx, model->userTransformMtx);

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_i1));
    model->flags |= (MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM);
    guTranslateF(model->userTransformMtx, 0.0f, physics->verticalOffset, 0.0f);
    guRotateF(tempMtx, physics->rotAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->userTransformMtx, tempMtx, model->userTransformMtx);
    update_collider_transform(COLLIDER_i1);

    return ApiStatus_BLOCK;
}
