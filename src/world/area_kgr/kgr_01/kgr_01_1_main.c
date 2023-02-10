#include "kgr_01.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_StartTongueWiggle);
extern EvtScript N(EVS_MonitorFriendlyFire);

EntryList N(Entrances) = {
    [kgr_01_ENTRY_0]    {   -4.0,    8.0,    0.0,   90.0 },
    [kgr_01_ENTRY_1]    {   80.0,    0.0,   10.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kgr_01 },
};

#include "world/common/atomic/CreateDarkness.inc.c"

EvtScript N(EVS_ExitWalk_kgr_02_0) = EVT_EXIT_WALK(60, kgr_01_ENTRY_1, "kgr_02", kgr_02_ENTRY_0);
EvtScript N(EVS_ExitWalk_mac_05_3) = EVT_EXIT_WALK(60, kgr_01_ENTRY_0, "mac_05", mac_05_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kgr_02_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_mac_05_3), TRIGGER_WALL_PUSH, COLLIDER_o50, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_EXEC(N(EVS_StartTongueWiggle))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_CreateDarkness))
    EVT_EXEC(N(EVS_MonitorFriendlyFire))
    EVT_RETURN
    EVT_END
};
