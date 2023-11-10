#include "kpa_100.h"
#include "sprite.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "kpa_117_shape");
    sprintf(wMapHitName, "kpa_117_hit");
    return FALSE;
}

EvtScript N(EVS_ExitWalk_kpa_08_1) = EVT_EXIT_WALK(60, kpa_100_ENTRY_0, "kpa_08", kpa_08_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_08_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
