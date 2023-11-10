#include "kpa_114.h"
#include "sprite.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "kpa_112_shape");
    sprintf(wMapHitName, "kpa_112_hit");
    return FALSE;
}

EvtScript N(EVS_ExitWalk_kpa_113_2) = EVT_EXIT_WALK(60, kpa_114_ENTRY_0, "kpa_113", kpa_113_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_115_0) = EVT_EXIT_WALK(40, kpa_114_ENTRY_1, "kpa_115", kpa_115_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_113_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_115_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar0)
    EVT_IF_EQ(LVar0, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalkShort)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
