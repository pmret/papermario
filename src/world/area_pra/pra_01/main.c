#include "pra_01.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

s32 N(NearDoorModelsL)[] = { MODEL_o946, -1 };
s32 N(NearDoorModelsR)[] = { MODEL_o948, -1 };
s32 N(FarDoorModelsL)[]  = { MODEL_o952, -1 };
s32 N(FarDoorModelsR)[]  = { MODEL_o950, -1 };
s32 N(BothDoorModelsL)[] = { MODEL_o946, MODEL_o952, -1 };
s32 N(BothDoorModelsR)[] = { MODEL_o948, MODEL_o950, -1 };

EvtScript N(EVS_ExitWalk_sam_10_1) = EVT_EXIT_WALK(60, pra_01_ENTRY_0, "sam_10", sam_10_ENTRY_1);
EvtScript N(EVS_ExitWalk_pra_15_0) = EVT_EXIT_WALK(60, pra_01_ENTRY_3, "pra_15", pra_15_ENTRY_0);

EvtScript N(EVS_ExitDoor_pra_02_0) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_01_ENTRY_1)
    Set(LVar1, COLLIDER_deilittse)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothDoorModelsL)))
        Set(LVar3, Ref(N(BothDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearDoorModelsL)))
        Set(LVar3, Ref(N(NearDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_pra_02_5) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, true)
    Set(LVar0, pra_01_ENTRY_2)
    Set(LVar1, COLLIDER_deilittse)
    IfEq(GF_PRA_BrokeIllusion, false)
        Set(LVar2, Ref(N(BothDoorModelsL)))
        Set(LVar3, Ref(N(BothDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarDoorModelsL)))
        Set(LVar3, Ref(N(FarDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_5)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_10_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_pra_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_pra_02_5)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_01_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(pra_01_ENTRY_1)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothDoorModelsL)))
                Set(LVar3, Ref(N(BothDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearDoorModelsL)))
                Set(LVar3, Ref(N(NearDoorModelsR)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_01_ENTRY_2)
            IfEq(GF_PRA_BrokeIllusion, false)
                Set(LVar2, Ref(N(BothDoorModelsL)))
                Set(LVar3, Ref(N(BothDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarDoorModelsL)))
                Set(LVar3, Ref(N(FarDoorModelsR)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_01_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(pra_01_ENTRY_4)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

API_CALLABLE(N(SetupFog)) {
    set_world_fog_dist(980, 1000);
    set_world_fog_color(15, 5, 55, 255);
    enable_world_fog();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DisableFloorReflection)) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_MOUNTAIN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Set(GF_MAP_CrystalPalace, true)
    IfEq(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
        Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    Call(N(SetupFog))
    Call(N(DisableFloorReflection))
    Set(LVar0, MODEL_o549)
    Set(LVar1, MODEL_o549)
    Set(LVar2, TEX_PANNER_0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_WALL_ONLY)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1328, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1368, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1338, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1389, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilinw, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1327, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1373, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1337, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1386, SURFACE_TYPE_SNOW)
    Exec(N(EVS_EnterMap))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, pra_01_ENTRY_4)
        Wait(65)
    Else
        Wait(1)
    EndIf
    Return
    End
};
