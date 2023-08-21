#include "arn_07.h"

MAP_RODATA_PAD(1,windmill);

API_CALLABLE(N(WrapWindmillAngle)) {
    f32 angle = evt_get_float_variable(script, LVar0);

    if (angle >= 360.0) {
        angle -= 360.0;
    }
    evt_set_float_variable(script, LVar0, angle);
    return ApiStatus_DONE2;
}

extern EvtScript(N(EVS_UpdateWindmill));

EvtScript N(EVS_SetupWindmill) = {
    EVT_EXEC(N(EVS_UpdateWindmill))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateWindmill) = {
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_SET(LVar1, 30)
    EVT_CALL(PlaySoundAtModel, MODEL_o36, SOUND_LOOP_WINDMILL_EXT, SOUND_SPACE_DEFAULT)
    EVT_LABEL(0)
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(N(WrapWindmillAngle))
        EVT_CALL(RotateModel, MODEL_o40, LVar0, 0, 0, 1)
        EVT_WAIT(1)
        EVT_SUB(LVar1, 1)
        EVT_IF_GT(LVar1, 0)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_SET(LVar1, 30)
        EVT_CALL(RandInt, 100, LVar2)
        EVT_IF_GT(LVar2, 10)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_SETF(LVar2, EVT_FLOAT(1.0))
        EVT_LOOP(50)
            EVT_SUBF(LVar2, EVT_FLOAT(0.01))
            EVT_ADDF(LVar0, LVar2)
            EVT_CALL(RotateModel, MODEL_o40, LVar0, 0, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(50)
            EVT_ADDF(LVar2, EVT_FLOAT(0.01))
            EVT_ADDF(LVar0, LVar2)
            EVT_CALL(RotateModel, MODEL_o40, LVar0, 0, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SET(LVar1, 30)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
