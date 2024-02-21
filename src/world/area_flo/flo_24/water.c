#include "flo_24.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_Scene_FillWithWater) = {
    Call(DisablePlayerInput, TRUE)
    Call(TranslateGroup, MODEL_g73, 0, 45, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 170, 0, 160)
    Call(SetPanTarget, CAM_DEFAULT, 170, -90, 160)
    Call(SetCamDistance, CAM_DEFAULT, 800)
    Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-7.5))
    Call(SetCamPosA, CAM_DEFAULT, Float(-300.0), Float(200.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(300.0), Float(-150.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(PlaySound, SOUND_LOOP_FLO_FILL_WATER_POOL)
    //@bug thread is never terminated
    Thread
        Call(MakeLerp, 80, 90, 10, EASING_LINEAR)
        Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o219, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o220, LVar0, 1, 0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(0)
        EndIf
        // should end thread here
    //@bug thread is never terminated
    Thread
        Call(MakeLerp, 45, 100, 150, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_g73, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        // should end thread here
    Wait(30)
    Set(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
    Call(GotoMap, Ref("flo_10"), flo_10_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_SetupWater) = {
    IfLt(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        Call(EnableGroup, MODEL_water1, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableGroup, MODEL_g60, FALSE)
    EndIf
    Call(GetEntryID, LVar0)
    IfNe(LVar0, flo_24_ENTRY_2)
        Call(EnableGroup, MODEL_g67, FALSE)
    EndIf
    Call(EnableTexPanning, MODEL_o165, TRUE)
    Call(EnableTexPanning, MODEL_o215, TRUE)
    Call(EnableTexPanning, MODEL_o166, TRUE)
    Call(EnableTexPanning, MODEL_o216, TRUE)
    Call(EnableTexPanning, MODEL_o189, TRUE)
    Call(EnableTexPanning, MODEL_o192, TRUE)
    Call(EnableTexPanning, MODEL_o219, TRUE)
    Call(EnableTexPanning, MODEL_o220, TRUE)
    Call(EnableTexPanning, MODEL_o218, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  140,  -80,  -70,  100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  -70,  100,  100,  -40)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0, -800,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(    0, -800, -200,  100)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,-2500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_6)
        TEX_PAN_PARAMS_STEP(    0,-2500, -200,  100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
