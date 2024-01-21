#include "flo_12.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_11_1) = EVT_EXIT_WALK(60, flo_12_ENTRY_0, "flo_11", flo_11_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    SetUP_CAMERA_DEFAULT()
    Set(AF_FLO_GivenCrystalBerry, FALSE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o180, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION(  -65, -210,   90, -110,  0)
    EVT_FLOWER_SPAWN_REGION( -200,  130,  -80,  170,  0)
    EVT_FLOWER_SPAWN_REGION( -270,  -80, -225,  125,  0)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_12_ENTRY_1)
        Exec(N(EVS_Scene_SunReturns))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
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
