#include "kgr_02.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Dummy);
extern EvtScript N(EVS_StartTongueWiggle);
extern EvtScript N(EVS_MonitorFriendlyFire);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [kgr_02_ENTRY_0]    { -175.0,   10.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kgr_02 },
};

#include "world/common/atomic/CreateDarkness.inc.c"

EvtScript N(EVS_ExitWalk_kgr_01_1) = EVT_EXIT_WALK(60, kgr_02_ENTRY_0, "kgr_01", kgr_01_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kgr_01_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_Dummy))
    EVT_EXEC(N(EVS_CreateDarkness))
    EVT_EXEC(N(EVS_MonitorFriendlyFire))
    EVT_RETURN
    EVT_END
};
