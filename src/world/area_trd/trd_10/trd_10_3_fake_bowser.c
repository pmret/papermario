#include "trd_10.h"

EvtScript N(EVS_InitFakeBowser) = {
    Return
    End
};

EvtScript N(EVS_HideFakeBowser) = {
    Call(EnableGroup, MODEL_atama, FALSE)
    Call(EnableGroup, MODEL_left_arm, FALSE)
    Call(EnableGroup, MODEL_shippo, FALSE)
    Call(EnableGroup, MODEL_dou, FALSE)
    Call(EnableGroup, MODEL_koura, FALSE)
    Call(EnableGroup, MODEL_koma1, FALSE)
    Call(EnableGroup, MODEL_koma2, FALSE)
    Call(EnableModel, MODEL_o171, FALSE)
    Call(EnableModel, MODEL_o172, FALSE)
    Call(EnableModel, MODEL_o183, FALSE)
    Call(EnableModel, MODEL_o118, FALSE)
    Call(EnableModel, MODEL_o120, FALSE)
    Call(EnableModel, MODEL_o165, FALSE)
    Return
    End
};

EvtScript N(EVS_SetModelsPos) = {
    Call(TranslateGroup, MODEL_atama, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_left_arm, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_shippo, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_dou, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_koura, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_koma1, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_koma2, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o171, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o172, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o183, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o118, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o120, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o165, LVar0, 0, 0)
    Return
    End
};

EvtScript N(EVS_RevealFakeBowser) = {
    Set(LVar0, 100)
    ExecWait(N(EVS_SetModelsPos))
    Set(AF_TRD_FakeBowserRevealed, FALSE)
    Label(0)
        IfEq(AF_TRD_FakeBowserRevealed, FALSE)
            Wait(1)
            Goto(0)
        EndIf
    Call(MakeLerp, 100, -100, 60 * DT, EASING_QUADRATIC_OUT)
    Call(PlaySoundAt, SOUND_FAKE_BOWSER_LONG_WALK, SOUND_SPACE_DEFAULT, 50, 0, 0)
    Label(10)
        Call(UpdateLerp)
        ExecWait(N(EVS_SetModelsPos))
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_SetupFakeBowser) = {
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Exec(N(EVS_HideFakeBowser))
    Else
        Exec(N(EVS_RevealFakeBowser))
    EndIf
    Return
    End
};
