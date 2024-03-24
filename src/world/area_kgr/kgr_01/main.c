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
    BindTrigger(N(EVS_ExitWalk_kgr_02_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(N(EVS_ExitWalk_mac_05_3), TRIGGER_WALL_PUSH, COLLIDER_o50, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(HidePlayerShadow, TRUE)
    Call(EnableNpcShadow, NPC_PARTNER, FALSE)
    Exec(N(EVS_StartTongueWiggle))
    Call(GetEntryID, LVar0)
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Exec(N(EVS_CreateDarkness))
    Exec(N(EVS_MonitorFriendlyFire))
    Return
    End
};
