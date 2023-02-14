#include "flo_19.h"

API_CALLABLE(N(CosInterpAbsMinMax)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVarTime = *args++;
    s32 time = evt_get_variable(script, outVarTime);
    s32 outValue = *args++;
    f32 min = evt_get_float_variable(script, *args++);
    f32 max = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 onlyOnce = evt_get_variable(script, *args++);
    f32 phaseOffset = (evt_get_float_variable(script, *args++) / 180.0f) * PI;
    f32 delta = fabsf(max - min) / 2; // fabsf here is the only difference between this and CosInterpMinMax

    if (onlyOnce && duration < time) {
        time = duration;
        evt_set_variable(script, outVarTime, duration);
    }

    evt_set_float_variable(script, outValue,
        (min + delta) // average value
        - (delta * cos_rad(((time * PI) / duration) + phaseOffset))); // perturbation

    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimatePlatforms) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
        EVT_SETF(LVar0, EVT_FLOAT(-215.4375))
        EVT_SETF(LVar1, EVT_FLOAT(128.593))
        EVT_SETF(LVar2, EVT_FLOAT(-200.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_01)
        EVT_CALL(TranslateGroup, MODEL_g17, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(-79.86))
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(5.0), EVT_FLOAT(136.765), 300, 0, 0)
        EVT_SETF(LVar2, EVT_FLOAT(-200.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_02)
        EVT_CALL(TranslateGroup, MODEL_g21, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(-364.265625))
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(5.0), EVT_FLOAT(106.765), 300, 0, 0)
        EVT_SETF(LVar2, EVT_FLOAT(10.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_03)
        EVT_CALL(TranslateGroup, MODEL_g22, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(295.734))
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(65.0), EVT_FLOAT(86.984), 200, 0, 0)
        EVT_SETF(LVar2, EVT_FLOAT(-80.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_04)
        EVT_CALL(TranslateGroup, MODEL_g23, LVar0, LVar1, LVar2)
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar2, EVT_FLOAT(0.968), EVT_FLOAT(1.031), 15, 0, 0)
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar3, EVT_FLOAT(1.031), EVT_FLOAT(0.968), 15, 0, 0)
        EVT_SETF(LVar0, MV_Distortion_Platform_01)
        EVT_SETF(LVar1, MV_Distortion_Platform_01)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g17, LVar0, LVar1, 1)
        EVT_SETF(LVar0, MV_Distortion_Platform_02)
        EVT_SETF(LVar1, MV_Distortion_Platform_02)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g21, LVar0, LVar1, 1)
        EVT_SETF(LVar0, MV_Distortion_Platform_03)
        EVT_SETF(LVar1, MV_Distortion_Platform_03)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g22, LVar0, LVar1, 1)
        EVT_SETF(LVar0, MV_Distortion_Platform_04)
        EVT_SETF(LVar1, MV_Distortion_Platform_04)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g23, LVar0, LVar1, 1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o77)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o78)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o76)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o79)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 1200)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_SETF(LVar0, LVarA)
        // the rest of the script is cut off halfway through the next EVT_SETF cmd
    /*
        EVT_SETF(LVar1, LVarB)
        EVT_SETF(LVar2, LVarC)
        EVT_SETF(LVar3, LVarD)
        EVT_MULF(LVar0, EVT_FLOAT(-0.046875))
        EVT_MULF(LVar1, EVT_FLOAT(-0.09375))
        EVT_MULF(LVar2, EVT_FLOAT(-0.09375))
        EVT_MULF(LVar3, EVT_FLOAT(-0.09375))
        EVT_ADDF(MV_Distortion_Platform_01, LVar0)
        EVT_ADDF(MV_Distortion_Platform_02, LVar1)
        EVT_ADDF(MV_Distortion_Platform_03, LVar2)
        EVT_ADDF(MV_Distortion_Platform_04, LVar3)
        EVT_MULF(MV_Distortion_Platform_01, EVT_FLOAT(0.843))
        EVT_MULF(MV_Distortion_Platform_02, EVT_FLOAT(0.843))
        EVT_MULF(MV_Distortion_Platform_03, EVT_FLOAT(0.843))
        EVT_MULF(MV_Distortion_Platform_04, EVT_FLOAT(0.843))
        EVT_ADDF(LVarA, MV_Distortion_Platform_01)
        EVT_ADDF(LVarB, MV_Distortion_Platform_02)
        EVT_ADDF(LVarC, MV_Distortion_Platform_03)
        EVT_ADDF(LVarD, MV_Distortion_Platform_04)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
    */
};

// half of EVT_SETF(LVar1, LVarB)
s32 N(EVS_AnimatePlatforms_Fragment)[] = {
    EVT_OP_SETF, 2,
};

// remaining data is truncated
/*
EvtScript N(EVS_AddPlayerWeight_Platform_01) = {
    EVT_THREAD
        EVT_ADDF(MV_Distortion_Platform_01, EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MV_Distortion_Platform_01, EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AddPlayerWeight_Platform_02) = {
    EVT_THREAD
        EVT_ADDF(MV_Distortion_Platform_02, EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MV_Distortion_Platform_02, EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AddPlayerWeight_Platform_03) = {
    EVT_THREAD
        EVT_ADDF(MV_Distortion_Platform_03, EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MV_Distortion_Platform_03, EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AddPlayerWeight_Platform_04) = {
    EVT_THREAD
        EVT_ADDF(MV_Distortion_Platform_04, EVT_FLOAT(-1.5))
        EVT_WAIT(1)
        EVT_ADDF(MV_Distortion_Platform_04, EVT_FLOAT(-1.5))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupClouds) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o77, MODEL_g17)
    EVT_CALL(ParentColliderToModel, COLLIDER_o78, MODEL_g21)
    EVT_CALL(ParentColliderToModel, COLLIDER_o76, MODEL_g22)
    EVT_CALL(ParentColliderToModel, COLLIDER_o79, MODEL_g23)
    EVT_CALL(SetModelFlags, MODEL_g17, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_g21, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_g22, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_CALL(SetModelFlags, MODEL_g23, MODEL_FLAG_USE_CAMERA_UNK_MATRIX, TRUE)
    EVT_EXEC(N(EVS_AnimatePlatforms))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_AddPlayerWeight_Platform_01)), TRIGGER_FLOOR_TOUCH, COLLIDER_o77, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_AddPlayerWeight_Platform_02)), TRIGGER_FLOOR_TOUCH, COLLIDER_o78, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_AddPlayerWeight_Platform_03)), TRIGGER_FLOOR_TOUCH, COLLIDER_o76, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_AddPlayerWeight_Platform_04)), TRIGGER_FLOOR_TOUCH, COLLIDER_o79, 1, 0)
    EVT_THREAD
        EVT_SET(LVarF, 0)
        EVT_LABEL(0)
            EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar0, EVT_FLOAT(0.968), EVT_FLOAT(1.031), 15, 0, 0)
            EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(1.031), EVT_FLOAT(0.968), 15, 0, 0)
            EVT_CALL(ScaleModel, MODEL_o73, LVar1, LVar0, 1)
            EVT_CALL(ScaleModel, MODEL_o74, LVar1, LVar0, 1)
            EVT_CALL(ScaleModel, MODEL_o75, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o76, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o77, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o78, LVar1, LVar0, 1)
            EVT_CALL(ScaleModel, MODEL_o45, LVar0, LVar1, 1)
            EVT_CALL(ScaleModel, MODEL_o56, LVar0, LVar1, 1)
            EVT_ADD(LVarF, 1)
            EVT_IF_GE(LVarF, 30)
                EVT_SET(LVarF, 0)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
*/
