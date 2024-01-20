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
    Call(DisablePlayerInput, TRUE)
    Call(UseExitHeading, 60, tst_10_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("tst_10"), tst_10_ENTRY_2)
    Wait(100)
    Return
    End
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_3) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseExitHeading, 60, tst_10_ENTRY_1)
    Exec(ExitWalk)
    Call(GotoMap, Ref("tst_10"), tst_10_ENTRY_3)
    Wait(100)
    Return
    End
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_0) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseExitHeading, 60, tst_10_ENTRY_2)
    Exec(ExitWalk)
    Call(GotoMap, Ref("tst_10"), tst_10_ENTRY_0)
    Wait(100)
    Return
    End
};

// note: sets DisablePlayerInput, but does not use EVT_GROUP_1B
EvtScript N(EVS_ExitWalk_tst_10_1) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseExitHeading, 60, tst_10_ENTRY_3)
    Exec(ExitWalk)
    Call(GotoMap, Ref("tst_10"), tst_10_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_DisableExitCameraZones) = {
    Call(SetZoneEnabled, ZONE_north, FALSE)
    Call(SetZoneEnabled, ZONE_west,  FALSE)
    Call(SetZoneEnabled, ZONE_south, FALSE)
    Call(SetZoneEnabled, ZONE_east,  FALSE)
    Set(AF_TST_00, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tst_10_2)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tst_10_3)), TRIGGER_FLOOR_TOUCH, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tst_10_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tst_10_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TESTING)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    IfEq(AF_TST_00, TRUE)
        Call(SetZoneEnabled, ZONE_north, FALSE)
        Call(SetZoneEnabled, ZONE_west,  FALSE)
        Call(SetZoneEnabled, ZONE_south, FALSE)
        Call(SetZoneEnabled, ZONE_east,  FALSE)
        Set(AF_TST_00, FALSE)
    Else
        Set(AF_TST_00, TRUE)
        BindTrigger(Ref(N(EVS_DisableExitCameraZones)), TRIGGER_FLOOR_TOUCH, COLLIDER_change, 1, 0)
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
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
    Call(MakeEntity, Ref(Entity_HeartBlock), -13, 60, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), -111, 0, -55, 0, MODEL_o137, MAKE_ENTITY_END)
    Return
    End
};
