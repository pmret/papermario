#include "flo_03.h"
#include "effects.h"

#include "../common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_09_1) = EVT_EXIT_WALK(60, flo_03_ENTRY_0, "flo_09", flo_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_flo_22_0) = EVT_EXIT_WALK(60, flo_03_ENTRY_1, "flo_22", flo_22_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_09_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_22_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    SetUP_CAMERA_DEFAULT()
    Set(AF_FLO_TreeDrop_RedBerry1, FALSE)
    Set(AF_FLO_TreeDrop_RedBerry2, FALSE)
    Set(AB_FLO_PetuniaDialogue, 0)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMoles))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_EmptyEntityHandler))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o160, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -145, -335,  182, -180, 0)
    EVT_FLOWER_SPAWN_REGION(  200, -170,  310,  150, 0)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_03_ENTRY_2)
        Exec(N(EVS_Scene_SunReturns))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
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
