#include "kzn_08.h"
#include "model.h"

#include "../common/LavaGlowLighting.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

// can't use kzn_SmokeTexPanners include in this file because of this function
API_CALLABLE(func_80240718_C71B98) {
    Bytecode* args = script->ptrReadPos;
    s32 dist = evt_get_variable(script, *args++);

    if (dist != 0) {
        enable_world_fog();
        set_world_fog_dist(995 - dist, 1000);
    } else {
        disable_world_fog();
        set_world_fog_dist(995, 1000);
    }
    set_world_fog_color(0, 0, 0, 0);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_StartTexPanner_SmokeLeft) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, LVar0, TEX_PANNER_3)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -200,    0,  600, -400)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_StartTexPanner_SmokeRight) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, LVar0, TEX_PANNER_4)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP( 500,    0,    0, -400)
        TEX_PAN_PARAMS_FREQ(   1,    0,    0,    1)
        TEX_PAN_PARAMS_INIT(   0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

ModelIDList N(LavaModelIDs) = {
    .count = 1,
    .list = { MODEL_yougan }
};

EvtScript N(EVS_ExitWalk_kzn_06) = EVT_EXIT_WALK_FIXED(60, kzn_08_ENTRY_0, "kzn_06", kzn_06_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_06), TRIGGER_FLOOR_TOUCH, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_StartTexPanner0) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_yougan1, TEX_PANNER_0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   0, -800,   0,   0)
        TEX_PAN_PARAMS_FREQ(   0,    1,   0,   0)
        TEX_PAN_PARAMS_INIT(   0,    0,   0,   0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_StartTexPanner1) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_yougan, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o640, TEX_PANNER_1)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 800,   0, 1600,   0)
        TEX_PAN_PARAMS_FREQ(   1,   0,    1,   0)
        TEX_PAN_PARAMS_INIT(   0,   0,    0,   0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o468, .pos = { -230.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o470, .pos = { -230.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o322, .pos = {  -10.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o446, .pos = {  -10.0, 0.0, 100.0 }},
    { .colliderID = COLLIDER_o454, .pos = {  -90.0, 0.0, -45.0 }},
    { .colliderID = -1 }
};

// unused
EvtScript N(EVS_AnimateLavaScale) = {
    Call(DisablePlayerInput, TRUE)
    Call(MakeLerp, 1, 100, 200, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        DivF(LVar0, Float(10.0))
        Call(ScaleModel, MODEL_yougan1, LVar0, Float(1.0), Float(1.0))
        MulF(LVar0, Float(-5.0))
        AddF(LVar0, Float(100.0))
        Set(MV_GlowIntensity, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(MakeLerp, 0, 35, 100, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_yougan, 0, LVar0, 0)
        MulF(LVar0, Float(-1.25))
        AddF(LVar0, Float(50.0))
        Set(MV_GlowIntensity, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS,  COLLIDER_yougan_atari, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan_atari, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_08)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_802455A0))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yougan_atari, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Call(ScaleModel, MODEL_yougan1, Float(10.0), Float(1.0), Float(1.0))
    Call(TranslateModel, MODEL_yougan, 0, 40, 0)
    Set(MV_GlowIntensity, 0)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(N(ApplyLavaGlowLighting), LAVA_GLOW_MODE_2, NULL)
    EndThread
    Thread
        Call(N(ClearLavaGlowLighting), Ref(N(LavaModelIDs)))
    EndThread
    Exec(N(EVS_StartTexPanner0))
    Exec(N(EVS_StartTexPanner1))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Return
    End
};
