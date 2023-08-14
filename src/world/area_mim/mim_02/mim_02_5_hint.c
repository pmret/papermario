#include "mim_02.h"

EvtScript N(EVS_SetupExitHint) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVar0, 0)
    EVT_CALL(EnableModel, MODEL_o414, TRUE)
    EVT_CALL(EnableModel, MODEL_me, FALSE)
    EVT_LABEL(10)
        EVT_CALL(AwaitPlayerApproach, 20, -340, 50)
        EVT_CALL(RandInt, 1, LVar2)
        EVT_ADD(LVar2, 1)
        EVT_CALL(EnableModel, MODEL_o414, FALSE)
        EVT_CALL(EnableModel, MODEL_me, TRUE)
        EVT_CALL(PlaySoundAt, SOUND_IMPISH_LAUGH, SOUND_SPACE_DEFAULT, 10, 110, -200)
        EVT_LOOP(LVar2)
            EVT_CALL(EnableModel, MODEL_o414, TRUE)
            EVT_CALL(EnableModel, MODEL_me, FALSE)
            EVT_WAIT(2)
            EVT_CALL(EnableModel, MODEL_o414, FALSE)
            EVT_CALL(EnableModel, MODEL_me, TRUE)
            EVT_CALL(RandInt, 5, LVar3)
            EVT_ADD(LVar3, 2)
            EVT_WAIT(LVar3)
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(EnableModel, MODEL_o414, TRUE)
        EVT_CALL(EnableModel, MODEL_me, FALSE)
        EVT_WAIT(60)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};
