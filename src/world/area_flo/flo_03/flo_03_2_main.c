#include "flo_03.h"

#include "world/common/atomic/flo_FlowerSpawnRegion.inc.c"

ApiStatus N(SpawnSunEffect)(Evt* script, s32 isInitialCall) {
    fx_sun_undeclared(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_09_1) = EVT_EXIT_WALK(60, flo_03_ENTRY_0, "flo_09", flo_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_flo_22_0) = EVT_EXIT_WALK(60, flo_03_ENTRY_1, "flo_22", flo_22_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_09_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_22_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(AF_FLO_TreeDrop_RedBerry1, FALSE)
    EVT_SET(AF_FLO_TreeDrop_RedBerry2, FALSE)
    EVT_SET(AB_FLO_PetuniaDialogue, 0)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupMoles))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_EmptyEntityHandler))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o160, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -145, -335,  182, -180, 0)
    EVT_FLOWER_SPAWN_REGION(  200, -170,  310,  150, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, flo_03_ENTRY_2)
        EVT_EXEC(N(EVS_Scene_SunReturns))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
