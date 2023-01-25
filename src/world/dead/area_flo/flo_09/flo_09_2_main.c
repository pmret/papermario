#include "flo_09.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_00_5) = EVT_EXIT_WALK(60, flo_09_ENTRY_0, "flo_00", flo_00_ENTRY_5);
EvtScript N(EVS_ExitWalk_flo_03_0) = EVT_EXIT_WALK(60, flo_09_ENTRY_1, "flo_03", flo_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_00_5)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupVines))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o104, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -511,   -4, -319,   10,  0)
    EVT_FLOWER_SPAWN_REGION( -302,   77,  -32,  116,  0)
    EVT_FLOWER_SPAWN_REGION(   51,   18,  141,  127,  0)
    EVT_FLOWER_SPAWN_REGION(  234,   38,  502,   98,  0)
    EVT_FLOWER_SPAWN_REGION( -525, -163, -400,  -80, 60)
    EVT_FLOWER_SPAWN_REGION( -346, -148,  517,  -91, 60)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
