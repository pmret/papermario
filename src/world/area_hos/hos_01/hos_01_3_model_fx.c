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
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 180, 80, 45, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetGivingPowerAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 80, 180, 35, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetGivingPowerAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupModelFX) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(    0,    0, -170,  -70)
        TEX_PAN_PARAMS_FREQ(    0,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,    0,  200, -100)
        TEX_PAN_PARAMS_FREQ(    0,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o178, TEX_PANNER_4)
    EVT_CALL(SetTexPanner, MODEL_o179, TEX_PANNER_4)
    EVT_CALL(SetTexPanner, MODEL_o208, TEX_PANNER_5)
    EVT_CALL(SetTexPanner, MODEL_o211, TEX_PANNER_5)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(EnableModel, MODEL_7, FALSE)
        EVT_IF_LT(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(EnableModel, MODEL_6, FALSE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_CALL(EnableModel, MODEL_5, FALSE)
                EVT_IF_LT(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
                    EVT_CALL(EnableModel, MODEL_4, FALSE)
                    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
                        EVT_CALL(EnableModel, MODEL_3, FALSE)
                        EVT_IF_LT(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
                            EVT_CALL(EnableModel, MODEL_2, FALSE)
                            EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
                                EVT_CALL(EnableModel, MODEL_1, FALSE)
                            EVT_END_IF
                        EVT_END_IF
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        EVT_CALL(EnableModel, MODEL_power, FALSE)
    EVT_ELSE
        EVT_PLAY_EFFECT(EFFECT_75, 0, -30, 250, -160, 1, -1)
        EVT_SET(MV_StarBeamFXPtr, LVarF)
        EVT_SET(LVar0, 255)
        EVT_CALL(N(SetStarBeamMasterAlpha), MV_StarBeamFXPtr, LVar0)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, hos_01_ENTRY_1)
            EVT_CALL(N(func_80240B10_A11390), MV_StarBeamFXPtr)
        EVT_ELSE
            EVT_CALL(N(func_80240AAC_A1132C), MV_StarBeamFXPtr)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetRenderMode, MODEL_1, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_2, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_3, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_4, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_5, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_6, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetRenderMode, MODEL_7, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(SetModelCustomGfx, MODEL_1, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_2, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_3, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_4, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_5, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_6, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_7, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_glowing_star)), NULL)
    EVT_CALL(TranslateModel, MODEL_power, 0, 2, 0)
    EVT_CALL(SetModelCustomGfx, MODEL_power, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_giving_power)), NULL)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 255, 100, 60, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(N(SetGlowingStarAlpha), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 100, 255, 35, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(N(SetGlowingStarAlpha), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_GE(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
            EVT_EXEC_WAIT(N(EVS_UpdateGivingPower))
        EVT_ELSE
            EVT_CALL(N(SetGivingPowerAlpha), 0)
            EVT_LABEL(10)
                EVT_IF_NE(MV_StarBeamState, 1)
                    EVT_WAIT(1)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_CALL(MakeLerp, 0, 180, 55, EASING_COS_IN_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(N(SetGivingPowerAlpha), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_SET(MV_StarBeamState, 2)
            EVT_EXEC_WAIT(N(EVS_UpdateGivingPower))
        EVT_END_IF
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
