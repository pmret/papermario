#include "common.h"
#include "model.h"

typedef struct RockingHorse {
    /* 0x00 */ f32 posX;
    /* 0x04 */ f32 posZ;
    /* 0x08 */ f32 lastRockAngle;
    /* 0x0C */ f32 rockPhaseAngularVel;
    /* 0x10 */ f32 rockPhase;
    /* 0x14 */ s32 modelID;
} RockingHorse; // size = 0x18

API_CALLABLE(N(UpdateRockingHorses)) {
    Matrix4f mtxPivot, mtxRotate;
    RockingHorse* horse;
    Model* model;
    f32 rockAngle;
    f32 offsetY;
    u32 i;

    if (isInitialCall) {
        horse = heap_malloc(sizeof(*horse) * ARRAY_COUNT(N(RockingHorseModels)));
        script->functionTempPtr[0] = horse;

        for (i = 0; i < ARRAY_COUNT(N(RockingHorseModels)); i++, horse++) {
            s32 modelID = N(RockingHorseModels)[i];

            horse->modelID = modelID;
            model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));
            horse->posX = model->center.x;
            horse->posZ = model->center.z;
            horse->rockPhaseAngularVel = 3.5f;
            horse->rockPhase = 0;
            horse->lastRockAngle = 0;
        }
    }

    horse = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(RockingHorseModels)); i++, horse++) {
        horse->rockPhase += horse->rockPhaseAngularVel;
        horse->rockPhase = clamp_angle(horse->rockPhase);
        #ifdef ROCKING_USE_SIN_DEG
        rockAngle = sin_deg(horse->rockPhase) * 20.0f;
        #else
        rockAngle = sin_rad((horse->rockPhase * 3.14f) / 180.0f) * 20.0f;
        #endif
        offsetY = SQ(rockAngle) / 90.0f;
        if (i == 0) {
            if ((horse->lastRockAngle >= 0.0f && rockAngle < 0.0f) || (horse->lastRockAngle < 0.0f && rockAngle >= 0.0f)) {
                sfx_play_sound_at_position(SOUND_CREAKY_ROCKING, SOUND_SPACE_DEFAULT, ROCKING_SOUND_LOCATION);
            }
            horse->lastRockAngle = rockAngle;
        }
        model = get_model_from_list_index(get_model_list_index_from_tree_index(horse->modelID));
        model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
        guTranslateF(mtxPivot, -horse->posX, 0.0f, -horse->posZ);
        guRotateF(mtxRotate, rockAngle, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxPivot, mtxRotate, model->userTransformMtx);
        guTranslateF(mtxPivot, horse->posX, offsetY, horse->posZ);
        guMtxCatF(model->userTransformMtx, mtxPivot, model->userTransformMtx);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Gizmos_RockingHorses) = {
    EVT_CALL(N(UpdateRockingHorses))
    EVT_RETURN
    EVT_END
};
