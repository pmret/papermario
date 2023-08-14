#include "arn_08.h"

EvtScript N(EVS_AnimateGears) = {
    EVT_CALL(PlaySound, SOUND_LOOP_WINDMILL_GEARS)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(10)
            EVT_CALL(RotateModel, MODEL_o45, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_o47, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_o46, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_o44, LVar0, 0, 0, -1)
            EVT_CALL(RotateModel, MODEL_o48, LVar0, 0, 0, -1)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
