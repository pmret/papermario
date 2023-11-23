#include "hos_05.h"
#include "effects.h"
#include "model.h"

extern u16 StarShrineLightBeamAlpha;

MAP_RODATA_PAD(1,unk);

#define NAME_SUFFIX _Starship
#include "world/common/atomic/ApplyTint.inc.c"
#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SetWorldColorParams)) {
    Bytecode* args;
    static u8 oldPrimR, oldPrimG, oldPrimB;
    static u8 oldEnvR, oldEnvG, oldEnvB;
    static s32 newPrimR, newPrimG, newPrimB;
    static s32 newEnvR, newEnvG, newEnvB;
    static s32 duration, time;

    args = script->ptrReadPos;
    if (isInitialCall) {
        mdl_get_remap_tint_params(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
        newPrimR = evt_get_variable(script, *args++);
        newPrimG = evt_get_variable(script, *args++);
        newPrimB = evt_get_variable(script, *args++);
        newEnvR = evt_get_variable(script, *args++);
        newEnvG = evt_get_variable(script, *args++);
        newEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        time = 0;
    }

    if (duration > 0) {
        time++;
        mdl_set_remap_tint_params(
            oldPrimR + ((newPrimR - oldPrimR) * time) / duration,
            oldPrimG + ((newPrimG - oldPrimG) * time) / duration,
            oldPrimB + ((newPrimB - oldPrimB) * time) / duration,
            oldEnvR  + ( (newEnvR - oldEnvR)  * time) / duration,
            oldEnvG  + ( (newEnvG - oldEnvG)  * time) / duration,
            oldEnvB  + ( (newEnvB - oldEnvB)  * time) / duration);
        if (time >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        mdl_set_remap_tint_params(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#define NAME_SUFFIX

void N(setup_gfx_light_beam)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, StarShrineLightBeamAlpha & 0xFF);
}

API_CALLABLE(N(SetLightBeamAlpha)) {
    Bytecode* args = script->ptrReadPos;

    StarShrineLightBeamAlpha = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

s32 N(StarshipShimmerAmt) = 255;

void N(setup_gfx_starship_shimmer)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(StarshipShimmerAmt));
}

API_CALLABLE(N(SetStarshipShimmerAmt)) {
    Bytecode* args = script->ptrReadPos;

    N(StarshipShimmerAmt) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

s32 N(UnusedAlphaParam) = 255;

void N(setup_gfx_unused)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_05, PM_CC_05);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(UnusedAlphaParam));
}

API_CALLABLE(N(SetUnusedAlphaParam)) {
    Bytecode* args = script->ptrReadPos;

    N(UnusedAlphaParam) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Starship_Update) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, 60, 30, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(0.1))
            EVT_ADDF(LVar2, MV_Starship_PosY)
            EVT_CALL(TranslateGroup, MODEL_g279, 0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g277, 0, LVar2, 0)
            EVT_CALL(RotateGroup, MODEL_g277, MV_Starship_Yaw, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 60, 0, 30, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(0.1))
            EVT_ADDF(LVar2, MV_Starship_PosY)
            EVT_CALL(TranslateGroup, MODEL_g279, 0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g277, 0, LVar2, 0)
            EVT_CALL(RotateGroup, MODEL_g277, MV_Starship_Yaw, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateStarshipCollision) = {
    EVT_LOOP(0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o630)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o627)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStarship) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o630, MODEL_o637)
    EVT_CALL(ParentColliderToModel, COLLIDER_o627, MODEL_o637)
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        EVT_EXEC(N(EVS_UpdateStarshipCollision))
        EVT_SET(MV_Starship_Yaw, -110)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, hos_05_ENTRY_3)
            EVT_SET(MV_Starship_PosY, 900)
        EVT_ELSE
            EVT_SET(MV_Starship_PosY, -85)
        EVT_END_IF
        EVT_EXEC(N(EVS_Starship_Update))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(MostSolidGeometry)[] = {
    MODEL_g283, MODEL_o4, MODEL_o6, MODEL_g5, MODEL_g97, MODEL_g157, 0xFFFF
};

EvtScript N(EVS_SetupLightBeam) = {
    EVT_CALL(EnableGroup, MODEL_g268, FALSE)
    EVT_CALL(EnableGroup, MODEL_g178, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        EVT_CALL(EnableModel, MODEL_o8, FALSE)
    EVT_ELSE
        EVT_CALL(SetModelCustomGfx, MODEL_o8, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
        EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_light_beam)), NULL)
        EVT_CALL(EnableModel, MODEL_o8, TRUE)
        EVT_CALL(N(SetLightBeamAlpha), 127)
        EVT_CALL(EnableGroup, MODEL_g277, TRUE)
        EVT_CALL(EnableModel, MODEL_o362, FALSE)
        EVT_CALL(EnableModel, MODEL_o397, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o616, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetZoneEnabled, ZONE_o622, FALSE)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Starship_Summon) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(N(SetModelTintMode_Starship), 2, NULL, ENV_TINT_REMAP)
        EVT_CALL(N(SetModelTintMode_Starship), 1, EVT_PTR(N(MostSolidGeometry)), ENV_TINT_REMAP)
        EVT_CALL(N(SetWorldColorParams_Starship), 255, 255, 255, 0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(N(SetWorldColorParams_Starship), 102, 102, 102, 0, 0, 0, 60)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_UpdateStarshipCollision))
    EVT_SET(MV_Starship_Yaw, 0)
    EVT_SET(MV_Starship_PosY, 0)
    EVT_EXEC(N(EVS_Starship_Update))
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_9)
        TEX_PAN_PARAMS_STEP(  -90,   70,  -60,   90)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan_Starship))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o646, 9)
    EVT_CALL(PlaySoundAt, SOUND_STARSHIP_APPEARS, SOUND_SPACE_DEFAULT, 0, 250, 0)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, 0, 250, 0, 10, LVar9)
    EVT_WAIT(20)
    EVT_CALL(SetModelCustomGfx, MODEL_o646, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_starship_shimmer)), NULL)
    EVT_CALL(EnableGroup, MODEL_g279, TRUE)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 200, 75, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetStarshipShimmerAmt), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(SetModelCustomGfx, MODEL_o8, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_light_beam)), NULL)
    EVT_CALL(EnableModel, MODEL_o8, TRUE)
    EVT_CALL(MakeLerp, 0, 127, 60, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetLightBeamAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_STARSHIP_APPEARS | SOUND_ID_TRIGGER_CHANGE_SOUND, 0, 0, 250, 0)
    EVT_CALL(DismissEffect, LVar9)
    EVT_CALL(EnableGroup, MODEL_g277, TRUE)
    EVT_CALL(MakeLerp, 200, 0, 45, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetStarshipShimmerAmt), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableGroup, MODEL_g279, FALSE)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -110, 90, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Starship_Yaw, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -85, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_Starship_PosY, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(N(SetWorldColorParams_Starship), 255, 255, 255, 0, 0, 0, 60)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
