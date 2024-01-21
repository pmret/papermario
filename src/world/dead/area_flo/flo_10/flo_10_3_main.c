#include "flo_10.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_24_1) = EVT_EXIT_WALK(60, flo_10_ENTRY_0, "flo_24", flo_24_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_24_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupWaterStoneSocket))
    Exec(N(EVS_SetupFountain))
    Exec(N(EVS_SetupWaterEffect))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o80, SURFACE_TYPE_FLOWERS)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o93, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -265,  247,  199,  313,  0)
    EVT_FLOWER_SPAWN_REGION( -300, -275, -140, -185,  0)
    EVT_FLOWER_SPAWN_REGION(  263, -248,  362,  146,  0)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(flo_10_ENTRY_1)
            Exec(N(EVS_Scene_SunReturns))
        CaseEq(flo_10_ENTRY_2)
            Exec(N(EVS_Scene_PostReleaseFountain))
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    Return
    End
};
