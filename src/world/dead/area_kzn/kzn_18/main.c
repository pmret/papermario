#include "kzn_18.h"

extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

#include "world/area_kzn/common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_17_1) = EVT_EXIT_WALK(60, kzn_18_ENTRY_0, "kzn_17", kzn_17_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_19_0) = EVT_EXIT_WALK(60, kzn_18_ENTRY_1, "kzn_19", kzn_19_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_19_1) = EVT_EXIT_WALK(60, kzn_18_ENTRY_2, "kzn_19", kzn_19_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_17_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_19_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_19_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_StartTexPanners_Lava) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(EnableTexPanning, MODEL_yougan1_1, true)
    Call(EnableTexPanning, MODEL_off1, true)
    Call(EnableTexPanning, MODEL_toro, true)
    Call(EnableTexPanning, MODEL_poko, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( 200,    0,  400, -100)
        TEX_PAN_PARAMS_FREQ(   1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(   0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP( 300, -500,    0,    0)
        TEX_PAN_PARAMS_FREQ(   1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(   0,    0,    0,    0)
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
    { .colliderID = COLLIDER_o382, .pos = { 50.0, 200.0, -185.0 }},
    { .colliderID = NO_COLLIDER }
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_18)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Call(SetMusic, 0, SONG_MT_LAVALAVA, 0, VOL_LEVEL_FULL)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    IfLt(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        Call(EnableModel, MODEL_off1, false)
        Call(EnableModel, MODEL_o506, false)
        Call(EnableModel, MODEL_o509, false)
        Call(EnableModel, MODEL_o511, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_off1, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_off2, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_off1, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Exec(N(EVS_StartTexPanners_Lava))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Return
    End
};
