#include "hos_10.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(ResumeIntroState)) {
    if (gGameStatusPtr->introPart > INTRO_PART_NONE && gGameStatusPtr->introPart < INTRO_PART_5) {
        gGameStatusPtr->introPart++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

void N(lerp_value_with_max_step)(f32 start, f32 end, f32 current, f32 maxStep, f32* out) {
    f32 remaining = end - current;

    if (end - start > 0.0f) {
        if (remaining < 0.0f) {
            *out = end;
        } else if (maxStep < remaining) {
            *out += maxStep;
        } else {
            *out += remaining;
        }
    } else if (remaining > 0.0f) {
        *out = end;
    } else if (remaining < -maxStep) {
        *out -= maxStep;
    } else {
        *out += remaining;
    }
}

API_CALLABLE(N(MakeShootingStar)) {
    fx_star(FX_STAR_FOREGROUND, 200.0f, 400.0f, 1200.0f, -300.0f, -100.0f, 0.0f, 30.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_Unused_Impl) = {
    Thread
        SetF(LVar0, 0)
        Loop(310)
            Call(TranslateModel, MODEL_o3, 0, LVar0, 0)
            AddF(LVar0, Float(-1.5))
            Wait(1)
        EndLoop
    EndThread
    Wait(100)
    Call(N(ResumeIntroState))
    Return
    End
};

EvtScript N(EVS_Scene_Rising_Impl) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  400,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(  600,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP( 1000,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_F)
        TEX_PAN_PARAMS_STEP(    0, 1000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_E)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(EnableTexPanning, MODEL_k2, TRUE)
    Call(EnableTexPanning, MODEL_k7, TRUE)
    Call(EnableTexPanning, MODEL_k1, TRUE)
    Call(EnableTexPanning, MODEL_k5, TRUE)
    Call(EnableTexPanning, MODEL_k9, TRUE)
    Call(EnableTexPanning, MODEL_k12, TRUE)
    Call(EnableTexPanning, MODEL_s1, TRUE)
    Call(EnableTexPanning, MODEL_s2, TRUE)
    Thread
        Wait(510)
        Call(N(MakeShootingStar))
    EndThread
    Call(EnableModel, MODEL_nagare, FALSE)
    Call(SetTexPanner, MODEL_nagare, 1)
    Thread
        Set(LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Wait(560)
        Call(EnableModel, MODEL_nagare, TRUE)
        Loop(32)
            Add(LVar0, 0x800)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Wait(1)
        EndLoop
        Call(EnableModel, MODEL_nagare, FALSE)
        Call(TranslateModel, MODEL_nagare, -400, 100, 0)
        Set(LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Wait(100)
        Call(EnableModel, MODEL_nagare, TRUE)
        Loop(32)
            Add(LVar0, 0x800)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Wait(1)
        EndLoop
        Call(EnableModel, MODEL_nagare, FALSE)
    EndThread
    Thread
        SetF(LVar0, -1125)
        Loop(1450)
            Call(TranslateModel, MODEL_o3, 0, LVar0, 0)
            AddF(LVar0, Float(-1.5))
            Wait(1)
        EndLoop
    EndThread
    Thread
        SetF(LVar0, -500)
        Loop(1450)
            Call(TranslateGroup, MODEL_kumo, 0, LVar0, 0)
            AddF(LVar0, Float(-2.5))
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(600)
        SetF(LVar0, 0)
        SetF(LVar1, 0)
        Loop(1000)
            Call(TranslateGroup, MODEL_starland, 0, LVar0, 0)
            Call(RotateGroup, MODEL_stl_1, LVar1, 0, -1, 0)
            AddF(LVar0, Float(-3.59375))
            AddF(LVar1, Float(1.0))
            Wait(1)
        EndLoop
    EndThread
    Wait(740)
    Call(N(ResumeIntroState))
    Return
    End
};

EvtScript N(EVS_Scene_UnusedWhiteScreen) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(EnableModel, MODEL_nagare, FALSE)
    Exec(N(EVS_Scene_Unused_Impl))
    Return
    End
};

EvtScript N(EVS_Scene_RisingAboveClouds) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Exec(N(EVS_Scene_Rising_Impl))
    Return
    End
};
