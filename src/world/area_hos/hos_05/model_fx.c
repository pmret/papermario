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
    Loop(0)
        Call(MakeLerp, 0, 60, 30, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            MulF(LVar2, Float(0.1))
            AddF(LVar2, MV_Starship_PosY)
            Call(TranslateGroup, MODEL_g279, 0, LVar2, 0)
            Call(TranslateGroup, MODEL_g277, 0, LVar2, 0)
            Call(RotateGroup, MODEL_g277, MV_Starship_Yaw, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 60, 0, 30, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            MulF(LVar2, Float(0.1))
            AddF(LVar2, MV_Starship_PosY)
            Call(TranslateGroup, MODEL_g279, 0, LVar2, 0)
            Call(TranslateGroup, MODEL_g277, 0, LVar2, 0)
            Call(RotateGroup, MODEL_g277, MV_Starship_Yaw, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_UpdateStarshipCollision) = {
    Loop(0)
        Call(UpdateColliderTransform, COLLIDER_o630)
        Call(UpdateColliderTransform, COLLIDER_o627)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupStarship) = {
    Call(ParentColliderToModel, COLLIDER_o630, MODEL_o637)
    Call(ParentColliderToModel, COLLIDER_o627, MODEL_o637)
    IfGe(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        Exec(N(EVS_UpdateStarshipCollision))
        Set(MV_Starship_Yaw, -110)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, hos_05_ENTRY_3)
            Set(MV_Starship_PosY, 900)
        Else
            Set(MV_Starship_PosY, -85)
        EndIf
        Exec(N(EVS_Starship_Update))
    EndIf
    Return
    End
};

s32 N(MostSolidGeometry)[] = {
    MODEL_g283, MODEL_o4, MODEL_o6, MODEL_g5, MODEL_g97, MODEL_g157, 0xFFFF
};

EvtScript N(EVS_SetupLightBeam) = {
    Call(EnableGroup, MODEL_g268, FALSE)
    Call(EnableGroup, MODEL_g178, FALSE)
    IfLt(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        Call(EnableModel, MODEL_o8, FALSE)
    Else
        Call(SetModelCustomGfx, MODEL_o8, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
        Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(setup_gfx_light_beam)), NULL)
        Call(EnableModel, MODEL_o8, TRUE)
        Call(N(SetLightBeamAlpha), 127)
        Call(EnableGroup, MODEL_g277, TRUE)
        Call(EnableModel, MODEL_o362, FALSE)
        Call(EnableModel, MODEL_o397, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o616, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetZoneEnabled, ZONE_o622, FALSE)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.5))
    EndIf
    Return
    End
};

EvtScript N(EVS_Starship_Summon) = {
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(N(SetModelTintMode_Starship), 2, NULL, ENV_TINT_REMAP)
        Call(N(SetModelTintMode_Starship), 1, Ref(N(MostSolidGeometry)), ENV_TINT_REMAP)
        Call(N(SetWorldColorParams_Starship), 255, 255, 255, 0, 0, 0, 0)
        Wait(1)
        Call(N(SetWorldColorParams_Starship), 102, 102, 102, 0, 0, 0, 60)
    EndThread
    Exec(N(EVS_UpdateStarshipCollision))
    Set(MV_Starship_Yaw, 0)
    Set(MV_Starship_PosY, 0)
    Exec(N(EVS_Starship_Update))
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_9)
        TEX_PAN_PARAMS_STEP(  -90,   70,  -60,   90)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan_Starship))
    EndThread
    Call(SetTexPanner, MODEL_o646, 9)
    Call(PlaySoundAt, SOUND_STARSHIP_APPEARS, SOUND_SPACE_DEFAULT, 0, 250, 0)
    PlayEffect(EFFECT_LIGHT_RAYS, 2, 0, 250, 0, 10, LVar9)
    Wait(20)
    Call(SetModelCustomGfx, MODEL_o646, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(setup_gfx_starship_shimmer)), NULL)
    Call(EnableGroup, MODEL_g279, TRUE)
    Thread
        Call(MakeLerp, 0, 200, 75, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(N(SetStarshipShimmerAmt), LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(60)
    Call(SetModelCustomGfx, MODEL_o8, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(setup_gfx_light_beam)), NULL)
    Call(EnableModel, MODEL_o8, TRUE)
    Call(MakeLerp, 0, 127, 60, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetLightBeamAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(40)
    Call(PlaySoundAt, SOUND_STARSHIP_APPEARS | SOUND_ID_TRIGGER_CHANGE_SOUND, 0, 0, 250, 0)
    Call(DismissEffect, LVar9)
    Call(EnableGroup, MODEL_g277, TRUE)
    Call(MakeLerp, 200, 0, 45, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetStarshipShimmerAmt), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableGroup, MODEL_g279, FALSE)
    Thread
        Call(MakeLerp, 0, -110, 90, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_Starship_Yaw, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(MakeLerp, 0, -85, 60, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_Starship_PosY, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30)
    Call(N(SetWorldColorParams_Starship), 255, 255, 255, 0, 0, 0, 60)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
