#include "jan_04.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_GotoMap_kmr_24_0) = {
    Call(FadeOutMusic, 0, 1500)
    Call(GotoMapSpecial, Ref("kmr_24"), kmr_24_ENTRY_0, TRANSITION_MARIO_WHITE)
    Wait(100)
}; //@bug script not terminated

EvtScript N(EVS_ExitWalk_jan_05_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, jan_04_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("jan_05"), jan_05_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_05_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(jan_04_ENTRY_0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseRange(jan_04_ENTRY_1, jan_04_ENTRY_2)
            Exec(N(EVS_Scene_TreasureChest))
        CaseEq(jan_04_ENTRY_3)
            Exec(N(EVS_Scene_Epilogue))
        CaseEq(jan_04_ENTRY_4)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(jan_04_ENTRY_0)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        CaseEq(jan_04_ENTRY_3)
            Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
    EndSwitch
    Exec(N(EVS_MakeEntities))
    Exec(N(EVS_SetupTrees))
    Exec(N(EVS_SetupBushes))
    Exec(N(EVS_SetupUnused))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o52, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o53, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o54, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o52, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o53, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o54, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1, SURFACE_TYPE_WATER)
    Call(MakeTransformGroup, MODEL_g12)
    Call(EnableTexPanning, MODEL_o61, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  -80,  140,   80, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_PlayDemoScene))
        Return
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
