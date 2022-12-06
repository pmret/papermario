#include "obk_05.h"
#include "model.h"
#include "mapfs/obk_05_shape.h"
#include "mapfs/obk_05_hit.h"

static char* N(exit_str_0) = "obk_01";
static char* N(exit_str_1) = "obk_06";

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

ApiStatus N(RetroJar_AwaitPlayerEntry)(Evt* script, s32 isInitialCall) {
    if (gCollisionStatus.currentFloor == COLLIDER_o420) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus N(RockingChair_UpdatePhysics)(Evt* script, s32 isInitialCall) {
    typedef struct RockingChairPhysics {
        /* 0x00 */ f32 angleDelta;
        /* 0x04 */ f32 angularAccel;
        /* 0x08 */ f32 rotationAngle;
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
        physics->rotationAngle = 0;
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
            if (collisionStatus->currentFloor == COLLIDER_i3) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }
            if (collisionStatus->currentFloor == COLLIDER_i2) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }
            physics->angleDelta = 0.0f;
            physics->verticalOffset = 0.0f;
            physics->angleB = 0.0f;
            physics->angleA = 0.0f;
            physics->rotationAngle = 0.0f;
            physics->angularAccel = 0.1f;
            physics->mass = 3.0f;
            physics->equilibriumAngle = 20.0f;
            break;
        case CHAIR_STATE_PLAYER_TOUCHING:
            //TODO odd match
            currentFloor = collisionStatus->currentFloor;
            if (currentFloor != COLLIDER_i3 && collisionStatus->currentFloor != COLLIDER_i2) {
                script->functionTemp[3] = 120; // settle time
                script->functionTemp[0] = CHAIR_STATE_PLAYER_NOT_TOUCHING;
            }
            if (fabsf(physics->rotationAngle) < 5.0f) {
                physics->angularAccel = fabsf(0.0 - playerStatus->position.x) / 200.0f;
            } else {
                physics->angularAccel = 0.1f;
            }
            if (playerStatus->position.x <= 0.0) {
                physics->angleB += physics->angularAccel;
                physics->equilibriumAngle = SQ(fabsf(0.0 - playerStatus->position.x)) / 50.0f;
                if (physics->equilibriumAngle > 15.0f) {
                    physics->equilibriumAngle = 15.0f;
                }
                if (physics->rotationAngle > physics->equilibriumAngle) {
                    physics->angleA += physics->angularAccel * physics->mass;
                }
            } else {
                physics->angleA += physics->angularAccel;
                physics->equilibriumAngle = -SQ(-fabsf(0.0 - playerStatus->position.x) * 0.5f) / 50.0f;
                if (physics->equilibriumAngle < -5.0f) {
                    physics->equilibriumAngle = -5.0f;
                }
                if (physics->rotationAngle < physics->equilibriumAngle) {
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
            physics->rotationAngle += physics->angleDelta;
            break;
        case CHAIR_STATE_PLAYER_NOT_TOUCHING:
            if (collisionStatus->currentFloor == COLLIDER_i3) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }
            if (collisionStatus->currentFloor == COLLIDER_i2) {
                script->functionTemp[0] = CHAIR_STATE_PLAYER_TOUCHING;
            }

            physics->angularAccel = 0.1f;
            physics->equilibriumAngle = 0;
            physics->angleB += physics->angularAccel;

            if (physics->rotationAngle > physics->equilibriumAngle) {
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
                physics->rotationAngle = zero;
            } else {
                script->functionTemp[3]--;
            }
            physics->angleDelta = physics->angleB - physics->angleA;
            physics->rotationAngle += physics->angleDelta;
            break;
    }

    // play creak sound once per cycle
    if (physics->rotationAngle <= -7.0f) {
        if (script->functionTemp[2] != -1) {
            get_collider_center(COLLIDER_i3, &centerX, &centerY, &centerZ);
            sfx_play_sound_at_position(SOUND_CREAKY_ROCKING_CHAIR, 0, centerX, centerY, centerZ);
            script->functionTemp[2] = -1;
        }
    } else {
        script->functionTemp[2] = 0;
    }

    physics->verticalOffset = SQ(physics->rotationAngle) / 90.0f;

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_i3));
    model->flags |= (MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED);
    guTranslateF(model->transformMatrix, 0.0f, physics->verticalOffset, 0.0f);
    guRotateF(tempMtx, physics->rotationAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->transformMatrix, tempMtx, model->transformMatrix);
    update_collider_transform(COLLIDER_i3);
    update_collider_transform(COLLIDER_i2);

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_i2));
    model->flags |= (MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED);
    guTranslateF(model->transformMatrix, 0.0f, physics->verticalOffset, 0.0f);
    guRotateF(tempMtx, physics->rotationAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->transformMatrix, tempMtx, model->transformMatrix);

    model = get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_i1));
    model->flags |= (MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED);
    guTranslateF(model->transformMatrix, 0.0f, physics->verticalOffset, 0.0f);
    guRotateF(tempMtx, physics->rotationAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->transformMatrix, tempMtx, model->transformMatrix);
    update_collider_transform(COLLIDER_i1);

    return ApiStatus_BLOCK;
}
