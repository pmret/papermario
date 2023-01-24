#include "omo_01.h"
#include "model.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ha1, LVar0, 1, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha2, LVar0, 1, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha3, LVar0, 1, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha4, LVar0, 1, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Shutters) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            EVT_WAIT(2)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Clocks) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_hari2, LVar0, 1, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(RockingHorseModels)[] = {
    MODEL_o353,
    MODEL_o355,
};

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
        rockAngle = sin_deg(horse->rockPhase) * 20.0f;
        offsetY = SQ(rockAngle) / 90.0f;
        if (i == 0) {
            if ((horse->lastRockAngle >= 0.0f && rockAngle < 0.0f) || (horse->lastRockAngle < 0.0f && rockAngle >= 0.0f)) {
                // different among UpdateRockingHorses functions
                sfx_play_sound_at_position(SOUND_CREAKY_ROCKING_CHAIR, 0, -185.0f, 0.0f, 160.0f);
            }
            horse->lastRockAngle = rockAngle;
        }
        model = get_model_from_list_index(get_model_list_index_from_tree_index(horse->modelID));
        model->flags |= MODEL_FLAG_USES_TRANSFORM_MATRIX | MODEL_FLAG_HAS_TRANSFORM_APPLIED;
        guTranslateF(mtxPivot, -horse->posX, 0.0f, -horse->posZ);
        guRotateF(mtxRotate, rockAngle, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtxPivot, mtxRotate, model->transformMatrix);
        guTranslateF(mtxPivot, horse->posX, offsetY, horse->posZ);
        guMtxCatF(model->transformMatrix, mtxPivot, model->transformMatrix);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Gizmos_RockingHorses) = {
    EVT_CALL(N(UpdateRockingHorses))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Wheels))
    EVT_EXEC(N(EVS_Gizmos_Shutters))
    EVT_EXEC(N(EVS_Gizmos_Clocks))
    EVT_EXEC(N(EVS_Gizmos_RockingHorses))
    EVT_RETURN
    EVT_END
};
