#include "mim_09.h"

EvtScript N(EVS_FlowersGentleRocking) = {
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x10000)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -23, 0, 300)
    EVT_CALL(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o464, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o465, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o466, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o467, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o468, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o469, LVar0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -23, 0, 300)
    EVT_CALL(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
    EVT_LABEL(20)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o464, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o465, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o466, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o467, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o468, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o469, LVar0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -23, 0, 300)
    EVT_CALL(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
    EVT_LABEL(30)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o464, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o465, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o466, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o467, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o468, LVar0, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o469, LVar0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    EVT_WAIT(2)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InspectBush) = {
    EVT_IF_EQ(MV_FoundHint, FALSE)
        EVT_SET(MV_FoundHint, TRUE)
        EVT_CALL(SetGroupVisibility, MODEL_hana, MODEL_GROUP_VISIBLE)
        EVT_CALL(PlaySound, SOUND_FLOWERS_GROW)
        EVT_CALL(MakeLerp, 10, 100, 30, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_MULF(LVar0, EVT_FLOAT(0.01))
        EVT_CALL(ScaleModel, MODEL_o464, LVar0, LVar0, LVar0)
        EVT_CALL(ScaleModel, MODEL_o465, LVar0, LVar0, LVar0)
        EVT_CALL(ScaleModel, MODEL_o466, LVar0, LVar0, LVar0)
        EVT_CALL(ScaleModel, MODEL_o467, LVar0, LVar0, LVar0)
        EVT_CALL(ScaleModel, MODEL_o468, LVar0, LVar0, LVar0)
        EVT_CALL(ScaleModel, MODEL_o469, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(EVS_FlowersGentleRocking))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_FlowersGentleRocking))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupExitHint) = {
    EVT_SET(MV_FoundHint, 0)
    EVT_CALL(SetGroupVisibility, MODEL_hana, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetTexPanner, MODEL_o465, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o467, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o469, TEX_PANNER_0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_InspectBush)), TRIGGER_WALL_PRESS_A, COLLIDER_atari_kusa, 1, 0)
    EVT_RETURN
    EVT_END
};
