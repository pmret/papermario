#include "kmr_03.h"

EvtScript N(EVS_ExitWalk_kmr_04_0) = EVT_EXIT_WALK(60, kmr_03_ENTRY_0, "kmr_04", kmr_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_kmr_05_0) = EVT_EXIT_WALK(60, kmr_03_ENTRY_1, "kmr_05", kmr_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(AF_KMR_08, FALSE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kmr_03_ENTRY_2)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_EXEC(N(EVS_Scene_FallingDown))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
