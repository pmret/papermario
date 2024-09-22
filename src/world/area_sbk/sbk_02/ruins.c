#include "sbk_02.h"
#include "effects.h"
#include "model.h"

#include "world/common/atomic/ApplyTint.inc.c"

API_CALLABLE(N(HideSun)) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, MV_Unk_00);

    effect->data.sun->targetAlpha = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InterpWorldEnvColor)) {
    static u8 savedPrimR, savedPrimG, savedPrimB;
    static u8 savedEnvR, savedEnvG, savedEnvB;
    static s32 targetPrimR, targetPrimG, targetPrimB;
    static s32 targetEnvR, targetEnvG, targetEnvB;
    static s32 duration, elapsed;

    Bytecode* args = script->ptrReadPos;
    s32 blendPrimR, blendPrimG, blendPrimB;
    s32 blendEnvR, blendEnvG, blendEnvB;

    if (isInitialCall) {
        mdl_get_remap_tint_params(&savedPrimR, &savedPrimG, &savedPrimB, &savedEnvR, &savedEnvG, &savedEnvB);
        targetPrimR = evt_get_variable(script, *args++);
        targetPrimG = evt_get_variable(script, *args++);
        targetPrimB = evt_get_variable(script, *args++);
        targetEnvR = evt_get_variable(script, *args++);
        targetEnvG = evt_get_variable(script, *args++);
        targetEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        elapsed = 0;
    }

    if (duration > 0) {
        elapsed++;
        blendPrimR = savedPrimR + ((targetPrimR - savedPrimR) * elapsed) / duration;
        blendPrimG = savedPrimG + ((targetPrimG - savedPrimG) * elapsed) / duration;
        blendPrimB = savedPrimB + ((targetPrimB - savedPrimB) * elapsed) / duration;
        blendEnvR = savedEnvR + ((targetEnvR - savedEnvR) * elapsed) / duration;
        blendEnvG = savedEnvG + ((targetEnvG - savedEnvG) * elapsed) / duration;
        blendEnvB = savedEnvB + ((targetEnvB - savedEnvB) * elapsed) / duration;

        mdl_set_remap_tint_params(blendPrimR, blendPrimG, blendPrimB, blendEnvR, blendEnvG, blendEnvB);
        if (elapsed >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        mdl_set_remap_tint_params(targetPrimR, targetPrimG, targetPrimB, targetEnvR, targetEnvG, targetEnvB);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

s32 N(PedestalKeyList)[] = {
    ITEM_PULSE_STONE,
    ITEM_NONE
};

EvtScript N(EVS_Pedestal_Sink) = {
    PlayEffect(EFFECT_SMOKE_IMPACT, 0, 0, 0, 0, 20, 10, 0, 60)
    PlayEffect(EFFECT_DUST, 2, 0, 0, 0, 60)
    Call(PlaySoundAtCollider, COLLIDER_iwa, SOUND_SBK_RUINS_PEDESTAL_SINK, SOUND_SPACE_DEFAULT)
    Set(LVar2, 0)
    Call(MakeLerp, 0, -50, 50, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_point_iwa, LVar2, 0, 1, 0)
        Call(TranslateModel, MODEL_point_iwa, 0, LVar0, 0)
        Sub(LVar2, 10)
        AddF(LVar3, Float(0.2))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_iwa, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_point_iwa, FALSE)
    Call(PlaySound, SOUND_LOOP_SBK_RUINS_WHIRLWIND)
    Return
    End
};

s32 N(ModelList_Solid)[] = {
    MODEL_ruins, MODEL_step, 0xFFFF
};

s32 N(ModelList_Translucent)[] = {
    MODEL_upper_light, MODEL_o225, 0xFFFF
};

EvtScript N(EVS_DarkenEnvironment) = {
    Call(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, Ref(N(ModelList_Solid)), ENV_TINT_NONE)
    Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(ModelList_Translucent)), ENV_TINT_NONE)
    Call(N(InterpWorldEnvColor), 255, 255, 255, 0, 0, 0, 0)
    Wait(1)
    Call(N(InterpWorldEnvColor), 44, 32, 177, 0, 0, 0, 60)
    Return
    End
};

EvtScript N(EVS_TexPan_SandRing) = {
    Call(SetRenderMode, MODEL_o225, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(EnableTexPanning, MODEL_o225, TRUE)
    Call(EnableTexPanning, CLONED_MODEL(0), TRUE)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Loop(0)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX, LVar1, LVar2)
        Add(LVar0, 6000)
        Add(LVar1, 5000)
        Add(LVar2, 4000)
        IfGt(LVar0, 0x20000)
            Sub(LVar0, 0x20000)
        EndIf
        IfGt(LVar1, 0x20000)
            Sub(LVar1, 0x20000)
        EndIf
        IfGt(LVar2, 0x20000)
            Sub(LVar2, 0x20000)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SandRing_Appear) = {
    Call(EnableModel, MODEL_o225, TRUE)
    Set(LVar2, 0)
    Set(LVar0, -100)
    Loop(100)
        Set(LVar3, LVar2)
        DivF(LVar3, 80)
        Call(ScaleModel, MODEL_o225, LVar3, Float(1.0), LVar3)
        Call(TranslateModel, MODEL_o225, 0, LVar0, 0)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Wait(1)
    EndLoop
    Loop(0)
        Call(ScaleModel, MODEL_o225, LVar3, Float(1.0), LVar3)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SandRingClone_Appear) = {
    Wait(10)
    Call(EnableModel, CLONED_MODEL(0), TRUE)
    Set(LVar2, 0)
    Set(LVar0, -100)
    Loop(100)
        Set(LVar3, LVar2)
        DivF(LVar3, 110)
        Call(ScaleModel, CLONED_MODEL(0), LVar3, Float(1.0), LVar3)
        Call(TranslateModel, CLONED_MODEL(0), 0, LVar0, 0)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Wait(1)
    EndLoop
    Loop(0)
        Call(ScaleModel, CLONED_MODEL(0), LVar3, Float(1.0), LVar3)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SandRing_Vanish) = {
    Call(EnableModel, MODEL_o225, TRUE)
    Set(LVar0, 0)
    Set(LVar2, 100)
    SetF(LVar3, Float(1.25))
    Loop(20)
        Call(ScaleModel, MODEL_o225, LVar3, Float(1.0), LVar3)
        Wait(1)
    EndLoop
    Loop(70)
        Set(LVar3, LVar2)
        DivF(LVar3, 80)
        Call(ScaleModel, MODEL_o225, LVar3, LVar3, LVar3)
        Call(TranslateModel, MODEL_o225, 0, LVar0, 0)
        Sub(LVar0, 2)
        Add(LVar2, 5)
        Wait(1)
    EndLoop
    Call(EnableModel, MODEL_o225, FALSE)
    Return
    End
};

EvtScript N(EVS_SandRingClone_Vanish) = {
    Wait(10)
    Call(EnableModel, CLONED_MODEL(0), TRUE)
    Set(LVar0, 0)
    Set(LVar2, 100)
    SetF(LVar3, Float(0.909))
    Loop(20)
        Call(ScaleModel, CLONED_MODEL(0), LVar3, Float(1.0), LVar3)
        Wait(1)
    EndLoop
    Loop(70)
        Set(LVar3, LVar2)
        DivF(LVar3, 110)
        Call(ScaleModel, CLONED_MODEL(0), LVar3, LVar3, LVar3)
        Call(TranslateModel, CLONED_MODEL(0), 0, LVar0, 0)
        Sub(LVar0, 2)
        Add(LVar2, 5)
        Wait(1)
    EndLoop
    Call(EnableModel, CLONED_MODEL(0), FALSE)
    Return
    End
};

EvtScript N(EVS_LightRays_Appear) = {
    ChildThread
        Call(EnableTexPanning, MODEL_upper_light, TRUE)
        Set(LVar0, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Add(LVar0, 2500)
            IfGt(LVar0, 0x8000)
                Sub(LVar0, 0x8000)
            EndIf
            Wait(1)
        EndLoop
    EndChildThread
    Call(EnableModel, MODEL_upper_light, TRUE)
    Set(LVar0, -200)
    Set(LVar1, 0)
    Loop(200)
        Call(TranslateModel, MODEL_upper_light, 0, LVar0, 0)
        Add(LVar0, 1)
        Wait(1)
    EndLoop
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_LightRays_Vanish) = {
    ChildThread
        Call(EnableTexPanning, MODEL_upper_light, TRUE)
        Set(LVar0, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Add(LVar0, 2500)
            IfGt(LVar0, 0x8000)
                Sub(LVar0, 0x8000)
            EndIf
            Wait(1)
        EndLoop
    EndChildThread
    Call(EnableModel, MODEL_upper_light, TRUE)
    Set(LVar0, 0)
    Call(TranslateModel, MODEL_upper_light, 0, LVar0, 0)
    Wait(10)
    Loop(100)
        Call(TranslateModel, MODEL_upper_light, 0, LVar0, 0)
        Sub(LVar0, 2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Ruins_Arise) = {
    Call(MakeTransformGroup, MODEL_ruins)
    Call(EnableGroup, MODEL_ruins, TRUE)
    Thread
        Call(EnableTexPanning, MODEL_o232, TRUE)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(600)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar1, LVar2)
            Add(LVar0,  200)
            Add(LVar1, -200)
            Add(LVar2,  700)
            Wait(1)
        EndLoop
        Call(EnableModel, MODEL_o232, FALSE)
    EndThread
    Thread
        Wait(20)
        Loop(30)
            Call(RandInt, 290, LVar0)
            Add(LVar0, -110)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -35, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, LVar0, 0, -35, 60)
            Wait(10)
        EndLoop
    EndThread
    Thread
        Wait(20)
        Loop(15)
            Call(RandInt, 180, LVar0)
            Add(LVar0, 170)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -300, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, LVar0, 0, -300, 60)
            Wait(20)
        EndLoop
    EndThread
    Thread
        Wait(100)
        Loop(5)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, -180, 0, 260, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, -180, 0, 260, 60)
            Wait(40)
        EndLoop
    EndThread
    Thread
        Wait(110)
        Loop(4)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, 180, 0, 260, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, 180, 0, 260, 60)
            Wait(50)
        EndLoop
    EndThread
    Call(PlaySound, SOUND_LOOP_SBK_RUINS_RISING)
    Call(MakeLerp, -310, 0, 310, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_ruins, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Ruins_FinishRising) = {
    Call(MakeTransformGroup, MODEL_ruins)
    Call(EnableGroup, MODEL_ruins, TRUE)
    Thread
        Call(EnableTexPanning, MODEL_o232, TRUE)
        Set(LVar0,  60000)
        Set(LVar1, -60000)
        Set(LVar2, 210000)
        Loop(300)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
            Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX, LVar1, LVar2)
            Add(LVar0,  200)
            Add(LVar1, -200)
            Add(LVar2,  700)
            Wait(1)
        EndLoop
        Call(EnableModel, MODEL_o232, FALSE)
    EndThread
    Thread
        Loop(10)
            Call(RandInt, 290, LVar0)
            Add(LVar0, -110)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -35, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, LVar0, 0, -35, 60)
            Wait(10)
        EndLoop
    EndThread
    Thread
        Wait(10)
        Loop(5)
            Call(RandInt, 180, LVar0)
            Add(LVar0, 170)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -300, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, LVar0, 0, -300, 60)
            Wait(20)
        EndLoop
    EndThread
    Thread
        Loop(3)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, -180, 0, 260, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, -180, 0, 260, 60)
            Wait(40)
        EndLoop
    EndThread
    Thread
        Wait(10)
        Loop(2)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, 180, 0, 260, 20, 10, 0, 60)
            PlayEffect(EFFECT_DUST, 2, 180, 0, 260, 60)
            Wait(50)
        EndLoop
    EndThread
    Call(MakeLerp, -20, 0, 20, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_ruins, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetChompStatueRotation) = {
    Call(RotateGroup, MODEL_c_wang, LVar0, 0, 1, 0)
    Call(RotateGroup, MODEL_d_wang, LVar0, 0, 1, 0)
    Set(LVar2, 0)
    Sub(LVar2, LVar0)
    Call(RotateGroup, MODEL_a_wang, LVar2, 0, 1, 0)
    Call(RotateGroup, MODEL_b_wang, LVar2, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_InterpChompStatueRotation) = {
    Call(MakeLerp, 180, 0, 60, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        ExecWait(N(EVS_SetChompStatueRotation))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Doors_Open) = {
    Call(MakeLerp, 0, 60, 180, EASING_QUADRATIC_IN)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o177, LVar0, 0, 1, 0)
        Call(TranslateModel, MODEL_o169, -20, 0, 0)
        Call(TranslateModel, MODEL_o178, -20, 0, 0)
        Call(RotateModel, MODEL_o169, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o178, LVar0, 0, 1, 0)
        Call(TranslateModel, MODEL_o169, 20, 0, 0)
        Call(TranslateModel, MODEL_o178, 20, 0, 0)
        Call(RotateModel, MODEL_o130, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o176, LVar0, 0, 1, 0)
        Call(TranslateModel, MODEL_o175, -20, 0, 0)
        Call(TranslateModel, MODEL_o129, -20, 0, 0)
        Call(RotateModel, MODEL_o175, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o129, LVar0, 0, 1, 0)
        Call(TranslateModel, MODEL_o175, 20, 0, 0)
        Call(TranslateModel, MODEL_o129, 20, 0, 0)
        Set(LVar2, 0)
        Sub(LVar2, LVar0)
        Call(RotateModel, MODEL_o141, LVar2, 0, 1, 0)
        Call(RotateModel, MODEL_o174, LVar2, 0, 1, 0)
        Call(TranslateModel, MODEL_o140, 20, 0, 0)
        Call(TranslateModel, MODEL_o173, 20, 0, 0)
        Call(RotateModel, MODEL_o140, LVar2, 0, 1, 0)
        Call(RotateModel, MODEL_o173, LVar2, 0, 1, 0)
        Call(TranslateModel, MODEL_o140, -20, 0, 0)
        Call(TranslateModel, MODEL_o173, -20, 0, 0)
        Call(RotateModel, MODEL_o157, LVar2, 0, 1, 0)
        Call(RotateModel, MODEL_o171, LVar2, 0, 1, 0)
        Call(TranslateModel, MODEL_o158, 20, 0, 0)
        Call(TranslateModel, MODEL_o172, 20, 0, 0)
        Call(RotateModel, MODEL_o158, LVar2, 0, 1, 0)
        Call(RotateModel, MODEL_o172, LVar2, 0, 1, 0)
        Call(TranslateModel, MODEL_o158, -20, 0, 0)
        Call(TranslateModel, MODEL_o172, -20, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(MakeLerp, 0, 60, 180, EASING_QUADRATIC_OUT)
    Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o169, -20, 0, 0)
        Call(TranslateModel, MODEL_o178, -20, 0, 0)
        Call(RotateModel, MODEL_o169, 60, 0, 1, 0)
        Call(RotateModel, MODEL_o178, 60, 0, 1, 0)
        Call(TranslateModel, MODEL_o169, 20, 0, 0)
        Call(TranslateModel, MODEL_o178, 20, 0, 0)
        Call(RotateModel, MODEL_o169, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o178, LVar0, 0, 1, 0)
        Call(TranslateModel, MODEL_o175, -20, 0, 0)
        Call(TranslateModel, MODEL_o129, -20, 0, 0)
        Call(RotateModel, MODEL_o175, 60, 0, 1, 0)
        Call(RotateModel, MODEL_o129, 60, 0, 1, 0)
        Call(TranslateModel, MODEL_o175, 20, 0, 0)
        Call(TranslateModel, MODEL_o129, 20, 0, 0)
        Call(RotateModel, MODEL_o175, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o129, LVar0, 0, 1, 0)
        Set(LVar2, 0)
        Sub(LVar2, LVar0)
        Call(TranslateModel, MODEL_o140, 20, 0, 0)
        Call(TranslateModel, MODEL_o173, 20, 0, 0)
        Call(RotateModel, MODEL_o140, -60, 0, 1, 0)
        Call(RotateModel, MODEL_o173, -60, 0, 1, 0)
        Call(TranslateModel, MODEL_o140, -20, 0, 0)
        Call(TranslateModel, MODEL_o173, -20, 0, 0)
        Call(RotateModel, MODEL_o140, LVar2, 0, 1, 0)
        Call(RotateModel, MODEL_o173, LVar2, 0, 1, 0)
        Call(TranslateModel, MODEL_o158, 20, 0, 0)
        Call(TranslateModel, MODEL_o172, 20, 0, 0)
        Call(RotateModel, MODEL_o158, -60, 0, 1, 0)
        Call(RotateModel, MODEL_o172, -60, 0, 1, 0)
        Call(TranslateModel, MODEL_o158, -20, 0, 0)
        Call(TranslateModel, MODEL_o172, -20, 0, 0)
        Call(RotateModel, MODEL_o158, LVar2, 0, 1, 0)
        Call(RotateModel, MODEL_o172, LVar2, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Return
    End
};

EvtScript N(EVS_Steps_Arise) = {
    Call(EnableGroup, MODEL_step, TRUE)
    Call(MakeLerp, -310, 0, 310, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_step, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Steps_FinishRising) = {
    Call(EnableGroup, MODEL_step, TRUE)
    Call(MakeLerp, -20, 0, 20, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_step, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Steps_Unfold) = {
    Call(PlaySoundAt, SOUND_SBK_RUINS_STEPS_UNFOLD, SOUND_SPACE_DEFAULT, 0, 39, -80)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.2))
    EndThread
    Call(MakeLerp, 0, -180, 180, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o106, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o107, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o100, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o105, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    PlayEffect(EFFECT_SMOKE_IMPACT, 0, 61, 2, -83, 20, 10, 0, 60)
    PlayEffect(EFFECT_DUST, 2, 61, 2, -83, 60)
    Wait(3)
    PlayEffect(EFFECT_SMOKE_IMPACT, 0, -61, 2, -83, 20, 10, 0, 60)
    PlayEffect(EFFECT_DUST, 2, -61, 2, -83, 60)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Return
    End
};

EvtScript N(EVS_OnInteract_Pedestal) = {
    Call(DisablePulseStone, TRUE)
    Call(ShowKeyChoicePopup)
    IfLe(LVar0, 0)
        Call(CloseChoicePopup)
        Call(DisablePulseStone, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(func_802CF56C, 1)
    Call(RemoveKeyItemAt, LVar1)
    Call(CloseChoicePopup)
    Set(GB_StoryProgress, STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
    Call(N(HideSun))
    Call(SetMusicTrack, 0, SONG_DRY_DRY_RUINS_APPEAR, 1, 8)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 210, 0, 137)
    Call(SetCamPosA, CAM_DEFAULT, Float(150.0), Float(500.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-450.0), Float(-500.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.2))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(10)
    Set(LVar0, 180)
    ExecWait(N(EVS_SetChompStatueRotation))
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 120, Float(0.2))
        Call(ShakeCam, CAM_DEFAULT, 0, 300, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 300, Float(0.2))
    EndThread
    Exec(N(EVS_Pedestal_Sink))
    Wait(30)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 0)
        Set(LVar0, -80)
        Set(LFlag0, FALSE)
    Else
        Set(LVar0, 80)
        Set(LFlag0, TRUE)
    EndIf
    Thread
        Wait(10)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, LVar0, 80, 0)
        Call(FacePlayerTowardPoint, 0, 0, 0)
    EndThread
    Exec(N(EVS_DarkenEnvironment))
    Wait(30)
    Call(CloneModel, MODEL_o225, CLONED_MODEL(0))
    Exec(N(EVS_TexPan_SandRing))
    Exec(N(EVS_SandRing_Appear))
    Exec(N(EVS_SandRingClone_Appear))
    Wait(100)
    Exec(N(EVS_LightRays_Appear))
    Wait(150)
    Exec(N(EVS_Ruins_Arise))
    Exec(N(EVS_Steps_Arise))
    Wait(100)
    Call(SetCamPitch, CAM_DEFAULT, Float(8.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.2))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(80)
    Exec(N(EVS_InterpChompStatueRotation))
    Wait(60)
    Wait(50)
    IfEq(LFlag0, FALSE)
        Call(GotoMap, Ref("sbk_30"), sbk_30_ENTRY_4)
    Else
        Call(GotoMap, Ref("sbk_30"), sbk_30_ENTRY_5)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_SetupRuins) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_GOT_PULSE_STONE)
            Call(EnableGroup, MODEL_day_version, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ruin, COLLIDER_FLAGS_UPPER_MASK)
        CaseLt(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            Call(EnableGroup, MODEL_day_version, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ruin, COLLIDER_FLAGS_UPPER_MASK)
            BindPadlock(Ref(N(EVS_OnInteract_Pedestal)), TRIGGER_WALL_PRESS_A, COLLIDER_iwa, Ref(N(PedestalKeyList)), 0, 1)
        CaseDefault
            Call(EnableModel, MODEL_point_iwa, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_pikapika, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Call(EnableGroup, MODEL_ruins, FALSE)
    Call(EnableGroup, MODEL_step, FALSE)
    Call(EnableModel, MODEL_upper_light, FALSE)
    Call(EnableModel, MODEL_o225, FALSE)
    Return
    End
};

EvtScript N(EVS_Ruins_Arise_Continued) = {
    Call(PlaySound, SOUND_SBK_RUINS_FINISH_RISING)
    Call(DisablePlayerInput, TRUE)
    Call(func_802CF56C, 1)
    Call(FacePlayerTowardPoint, 0, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_iwa, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_point_iwa, FALSE)
    Call(EnableGroup, MODEL_day_version, FALSE)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 400, Float(0.2))
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 210, 0, 137)
    Call(SetCamPosA, CAM_DEFAULT, Float(150.0), Float(500.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-450.0), Float(-500.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(8.0), Float(-9.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    Call(N(SetModelTintMode), APPLY_TINT_GROUPS, Ref(N(ModelList_Solid)), ENV_TINT_NONE)
    Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(ModelList_Translucent)), ENV_TINT_NONE)
    Call(N(InterpWorldEnvColor), 44, 32, 177, 0, 0, 0, 0)
    Exec(N(EVS_Ruins_FinishRising))
    Exec(N(EVS_Steps_FinishRising))
    Call(CloneModel, MODEL_o225, CLONED_MODEL(0))
    Exec(N(EVS_TexPan_SandRing))
    Exec(N(EVS_SandRing_Vanish))
    Exec(N(EVS_SandRingClone_Vanish))
    Wait(20)
    Exec(N(EVS_LightRays_Vanish))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(4.0), Float(-6.5))
    Call(SetCamDistance, CAM_DEFAULT, Float(790.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.2))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(100)
    Exec(N(EVS_Doors_Open))
    Wait(100)
    ExecWait(N(EVS_Steps_Unfold))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ruin, COLLIDER_FLAGS_UPPER_MASK)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(60)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(func_802CF56C, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
