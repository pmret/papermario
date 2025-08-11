#include "flo_24.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_08_1) = EVT_EXIT_WALK(60, flo_24_ENTRY_0, "flo_08", flo_08_ENTRY_1);
EvtScript N(EVS_ExitWalk_flo_10_0) = EVT_EXIT_WALK(60, flo_24_ENTRY_1, "flo_10", flo_10_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_08_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    EVT_SETUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    Call(MakeTransformGroup, MODEL_g58)
    Call(MakeTransformGroup, MODEL_g73)
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupWater))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o177, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o178, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o179, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o177, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o178, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o179, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o176, SURFACE_TYPE_WATER)
    EVT_FLOWER_SPAWN_REGION( -480, -350,  -65, -260,  0)
    EVT_FLOWER_SPAWN_REGION(  100, -350,  480, -260,  0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_24_ENTRY_2)
        Exec(N(EVS_Scene_FillWithWater))
        Exec(N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    Return
    End
};
