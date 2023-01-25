#include "flo_10.h"
#include "effects.h"

#include "../common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_24_1) = EVT_EXIT_WALK(60, flo_10_ENTRY_0, "flo_24", flo_24_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_24_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupWaterStoneSocket))
    EVT_EXEC(N(EVS_SetupFountain))
    EVT_EXEC(N(EVS_SetupWaterEffect))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o80, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o93, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -265,  247,  199,  313,  0)
    EVT_FLOWER_SPAWN_REGION( -300, -275, -140, -185,  0)
    EVT_FLOWER_SPAWN_REGION(  263, -248,  362,  146,  0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(flo_10_ENTRY_1)
            EVT_EXEC(N(EVS_Scene_SunReturns))
        EVT_CASE_EQ(flo_10_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_PostReleaseFountain))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
