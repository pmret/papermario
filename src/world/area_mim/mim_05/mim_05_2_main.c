#include "mim_05.h"

#include "../common/SetForeverForestFog.inc.c"

EvtScript N(EVS_ExitWalk_n) = EVT_EXIT_WALK(60, mim_05_ENTRY_0, "mim_01", mim_01_ENTRY_1);
EvtScript N(EVS_ExitWalk_w) = EVT_EXIT_WALK(60, mim_05_ENTRY_1, "mim_06", mim_06_ENTRY_3);
EvtScript N(EVS_ExitWalk_s) = EVT_EXIT_WALK(60, mim_05_ENTRY_2, "mim_04", mim_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_e) = EVT_EXIT_WALK(60, mim_05_ENTRY_3, "mim_08", mim_08_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_n)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_w)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_s)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_e)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FOREVER_FOREST)
    EVT_CALL(SetSpriteShading, SHADING_MIM_05)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 650)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SET(AB_MIM_2, GB_MIM_CurrentMapID)
    EVT_CALL(GetMapID, GB_MIM_CurrentMapID)
    EVT_EXEC_WAIT(N(EVS_SetupGates))
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupExitHint))
    EVT_CALL(N(SetForeverForestFog))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_RETURN
    EVT_END
};
