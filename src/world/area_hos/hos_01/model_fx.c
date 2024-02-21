#include "hos_01.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

s32 N(GlowingStarAlpha) = 255;
s32 N(GivingPowerAlpha) = 255;

API_CALLABLE(N(func_80240AAC_A1132C)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_78 = 190.0f;
    effect->data.unk_75->unk_7C = 220.0f;
    effect->data.unk_75->unk_68 = 0.7f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240B10_A11390)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->unk_78 = 170.0f;
    effect->data.unk_75->unk_7C = 170.0f;
    effect->data.unk_75->unk_68 = 2.0f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetStarBeamMasterAlpha)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.unk_75->masterAlpha = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(setup_gfx_glowing_star)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(GlowingStarAlpha));
}

API_CALLABLE(N(SetGlowingStarAlpha)) {
    Bytecode* args = script->ptrReadPos;

    N(GlowingStarAlpha) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(setup_gfx_giving_power)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(GivingPowerAlpha));
}

API_CALLABLE(N(SetGivingPowerAlpha)) {
    Bytecode* args = script->ptrReadPos;

    N(GivingPowerAlpha) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateGivingPower) = {
    Loop(0)
        Call(MakeLerp, 180, 80, 45, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(N(SetGivingPowerAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 80, 180, 35, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(N(SetGivingPowerAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupModelFX) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(    0,    0, -170,  -70)
        TEX_PAN_PARAMS_FREQ(    0,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,    0,  200, -100)
        TEX_PAN_PARAMS_FREQ(    0,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o178, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o179, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o208, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o211, TEX_PANNER_5)
    IfLt(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Call(EnableModel, MODEL_7, FALSE)
        IfLt(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(EnableModel, MODEL_6, FALSE)
            IfLt(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                Call(EnableModel, MODEL_5, FALSE)
                IfLt(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
                    Call(EnableModel, MODEL_4, FALSE)
                    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
                        Call(EnableModel, MODEL_3, FALSE)
                        IfLt(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
                            Call(EnableModel, MODEL_2, FALSE)
                            IfLt(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
                                Call(EnableModel, MODEL_1, FALSE)
                            EndIf
                        EndIf
                    EndIf
                EndIf
            EndIf
        EndIf
    EndIf
    IfLt(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        Call(EnableModel, MODEL_power, FALSE)
    Else
        PlayEffect(EFFECT_75, 0, -30, 250, -160, 1, -1)
        Set(MV_StarBeamFXPtr, LVarF)
        Set(LVar0, 255)
        Call(N(SetStarBeamMasterAlpha), MV_StarBeamFXPtr, LVar0)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, hos_01_ENTRY_1)
            Call(N(func_80240B10_A11390), MV_StarBeamFXPtr)
        Else
            Call(N(func_80240AAC_A1132C), MV_StarBeamFXPtr)
        EndIf
    EndIf
    Call(SetRenderMode, MODEL_1, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_2, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_3, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_4, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_5, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_6, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetRenderMode, MODEL_7, RENDER_MODE_SURFACE_XLU_LAYER2)
    Call(SetModelCustomGfx, MODEL_1, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_2, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_3, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_4, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_5, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_6, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_7, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(setup_gfx_glowing_star)), NULL)
    Call(TranslateModel, MODEL_power, 0, 2, 0)
    Call(SetModelCustomGfx, MODEL_power, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(setup_gfx_giving_power)), NULL)
    Thread
        Loop(0)
            Call(MakeLerp, 255, 100, 60, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(N(SetGlowingStarAlpha), LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 100, 255, 35, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(N(SetGlowingStarAlpha), LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Thread
        IfGe(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            ExecWait(N(EVS_UpdateGivingPower))
        Else
            Call(N(SetGivingPowerAlpha), 0)
            Label(10)
                IfNe(MV_StarBeamState, 1)
                    Wait(1)
                    Goto(10)
                EndIf
            Call(MakeLerp, 0, 180, 55, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(N(SetGivingPowerAlpha), LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Set(MV_StarBeamState, 2)
            ExecWait(N(EVS_UpdateGivingPower))
        EndIf
    EndThread
    Return
    End
};
