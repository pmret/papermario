#include "tst_10.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [tst_10_ENTRY_0]    {    0.0,    0.0, -480.0,  180.0 },
    [tst_10_ENTRY_1]    { -480.0,    0.0,    0.0,   90.0 },
    [tst_10_ENTRY_2]    {    0.0,    0.0,  480.0,    0.0 },
    [tst_10_ENTRY_3]    {  480.0,    0.0,    0.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_2) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseExitHeading, 60, tst_10_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("tst_10"), tst_10_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_3) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseExitHeading, 60, tst_10_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("tst_10"), tst_10_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseExitHeading, 60, tst_10_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("tst_10"), tst_10_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_1) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseExitHeading, 60, tst_10_ENTRY_3)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("tst_10"), tst_10_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DisableExitCameraZones) = {
    EVT_CALL(SetZoneEnabled, ZONE_north, FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_west,  FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_east,  FALSE)
    EVT_SET(AF_TST_00, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tst_10_2)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tst_10_3)), TRIGGER_FLOOR_TOUCH, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tst_10_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tst_10_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TESTING)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(AF_TST_00, TRUE)
        EVT_CALL(SetZoneEnabled, ZONE_north, FALSE)
        EVT_CALL(SetZoneEnabled, ZONE_west,  FALSE)
        EVT_CALL(SetZoneEnabled, ZONE_south, FALSE)
        EVT_CALL(SetZoneEnabled, ZONE_east,  FALSE)
        EVT_SET(AF_TST_00, FALSE)
    EVT_ELSE
        EVT_SET(AF_TST_00, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DisableExitCameraZones)), TRIGGER_FLOOR_TOUCH, COLLIDER_change, 1, 0)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

TweesterPath N(DefaultTweesterPath) = {
    -65, 0, 217,
    -262, 0, -64,
    57, 0, -286,
    327, 0, 8,
    TWEESTER_PATH_LOOP
 };

 TweesterPath* N(UnusedTweesterPaths)[] = {
    &N(DefaultTweesterPath),
    &N(DefaultTweesterPath),
    &N(DefaultTweesterPath),
    &N(DefaultTweesterPath),
    PTR_LIST_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -13, 60, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -111, 0, -55, 0, MODEL_o137, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
