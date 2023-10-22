#include "trd_10.h"

EvtScript N(EVS_InitFakeBowser) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HideFakeBowser) = {
    EVT_CALL(EnableGroup, MODEL_atama, FALSE)
    EVT_CALL(EnableGroup, MODEL_left_arm, FALSE)
    EVT_CALL(EnableGroup, MODEL_shippo, FALSE)
    EVT_CALL(EnableGroup, MODEL_dou, FALSE)
    EVT_CALL(EnableGroup, MODEL_koura, FALSE)
    EVT_CALL(EnableGroup, MODEL_koma1, FALSE)
    EVT_CALL(EnableGroup, MODEL_koma2, FALSE)
    EVT_CALL(EnableModel, MODEL_o171, FALSE)
    EVT_CALL(EnableModel, MODEL_o172, FALSE)
    EVT_CALL(EnableModel, MODEL_o183, FALSE)
    EVT_CALL(EnableModel, MODEL_o118, FALSE)
    EVT_CALL(EnableModel, MODEL_o120, FALSE)
    EVT_CALL(EnableModel, MODEL_o165, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetModelsPos) = {
    EVT_CALL(TranslateGroup, MODEL_atama, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_left_arm, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_shippo, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_dou, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_koura, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_koma1, LVar0, 0, 0)
    EVT_CALL(TranslateGroup, MODEL_koma2, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o171, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o172, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o183, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o118, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o120, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o165, LVar0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RevealFakeBowser) = {
    EVT_SET(LVar0, 100)
    EVT_EXEC_WAIT(N(EVS_SetModelsPos))
    EVT_SET(AF_TRD_FakeBowserRevealed, FALSE)
    EVT_LABEL(0)
        EVT_IF_EQ(AF_TRD_FakeBowserRevealed, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(MakeLerp, 100, -100, 60 * DT, EASING_QUADRATIC_OUT)
    EVT_CALL(PlaySoundAt, SOUND_FAKE_BOWSER_LONG_WALK, SOUND_SPACE_DEFAULT, 50, 0, 0)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_EXEC_WAIT(N(EVS_SetModelsPos))
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupFakeBowser) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_EXEC(N(EVS_HideFakeBowser))
    EVT_ELSE
        EVT_EXEC(N(EVS_RevealFakeBowser))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
