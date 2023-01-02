#include "kpa_96.h"

EvtScript N(EVS_ExitDoors_kpa_32_3) = EVT_EXIT_DOUBLE_DOOR(kpa_96_ENTRY_0, "kpa_32", kpa_32_ENTRY_3, COLLIDER_deilittw, MODEL_o881, MODEL_o882);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_32_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(LVar0, kpa_96_ENTRY_0)
    EVT_SET(LVar2, MODEL_o881)
    EVT_SET(LVar3, MODEL_o882)
    EVT_EXEC(EnterDoubleDoor)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupShop))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
