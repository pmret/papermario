#include "kzn_11.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_10_1) = EVT_EXIT_WALK(60, kzn_11_ENTRY_0, "kzn_10", kzn_10_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_17_0) = EVT_EXIT_WALK(60, kzn_11_ENTRY_1, "kzn_17", kzn_17_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_10_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_StartTexPanners_Lava) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_yougan1_1, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_toro, TRUE)
    Call(EnableTexPanning, MODEL_poko, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  200,    0,  400, -100)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(  300, -500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        // animate lava bubbles (real ones, not the enemies)
        Set(LVar0, 0)
        Loop(0)
            Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
            Add(LVar0, 0x8000)
            Wait(6)
        EndLoop
    EndThread
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o80,  .pos = { -760.0,   20.0,    0.0 }},
    { .colliderID = COLLIDER_o211, .pos = { -400.0,   20.0,    0.0 }},
    { .colliderID = COLLIDER_o212, .pos = {  230.0,   20.0,    0.0 }},
    { .colliderID = COLLIDER_o83,  .pos = {  790.0,   20.0,    0.0 }},
    { .colliderID = NO_COLLIDER }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_11)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o175, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o176, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o177, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o178, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o156, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o179, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o180, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o181, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_pp1, SURFACE_TYPE_LAVA)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_pp2, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Exec(N(EVS_StartTexPanners_Lava))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Exec(N(EVS_UpdateLeftPlatform))
    Exec(N(EVS_UpdateRightPlatform))
    Return
    End
};
