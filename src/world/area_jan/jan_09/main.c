#include "jan_09.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_jan_10_0) = EVT_EXIT_WALK(60, jan_09_ENTRY_2, "jan_10", jan_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_08_2) = EVT_EXIT_WALK(60, jan_09_ENTRY_0, "jan_08", jan_08_ENTRY_2);
EvtScript N(EVS_ExitWalk_jan_06_3) = EVT_EXIT_WALK(60, jan_09_ENTRY_1, "jan_06", jan_06_ENTRY_3);

EvtScript N(EVS_GotoMap_jan_11_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(GotoMap, Ref("jan_11"), jan_11_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_TouchFloor_Pipe) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    ExecWait(N(EVS_Pipe_ExitVertical))
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_o245, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_08_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_06_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Set(LVar0, jan_09_ENTRY_3)
    Set(LVar1, COLLIDER_o208)
    Set(LVar2, Ref(N(EVS_GotoMap_jan_11_0)))
    BindTrigger(Ref(N(EVS_TouchFloor_Pipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(SetZoneEnabled, ZONE_o79, false)
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupBushes))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o97, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o99, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o97, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o99, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1, SURFACE_TYPE_WATER)
    Exec(N(EVS_SetupTrees))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, jan_09_ENTRY_3)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        Set(LVarA, Ref(N(EVS_BindExitTriggers)))
        Exec(N(EVS_Pipe_EnterVertical))
        Wait(1)
    EndIf
    Call(SetMusic, 0, SONG_JADE_JUNGLE, 0, VOL_LEVEL_FULL)
    Call(ClearAmbientSounds, 250)
    Call(MakeTransformGroup, MODEL_g51)
    Call(EnableTexPanning, MODEL_o180, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  -80,  140,   80, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
