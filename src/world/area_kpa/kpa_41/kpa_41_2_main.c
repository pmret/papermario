#include "kpa_41.h"

EvtScript N(EVS_ExitWalk_LowerLeft) = EVT_EXIT_WALK(60, kpa_41_ENTRY_0, "kpa_40", kpa_40_ENTRY_1);

EvtScript N(EVS_ExitWalk_LowerRight) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_41_ENTRY_1)
    Exec(ExitWalk)
    Switch(AB_KPA_MazeProgress)
        CaseOrEq(1)
        CaseOrEq(2)
        CaseOrEq(4)
            Add(AB_KPA_MazeProgress, 1)
            Call(GotoMap, Ref("kpa_41"), kpa_41_ENTRY_0)
        EndCaseGroup
        CaseOrEq(0)
        CaseOrEq(3)
        CaseOrEq(5)
            Call(GotoMap, Ref("kpa_40"), kpa_40_ENTRY_3)
        EndCaseGroup
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_UpperLeft) = EVT_EXIT_WALK(60, kpa_41_ENTRY_3, "kpa_40", kpa_40_ENTRY_2);

EvtScript N(EVS_ExitWalk_UpperRight) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_41_ENTRY_2)
    Exec(ExitWalk)
    Switch(AB_KPA_MazeProgress)
        CaseEq(5)
            Set(AB_KPA_MazeProgress, 0)
            Call(GotoMap, Ref("kpa_102"), kpa_102_ENTRY_0)
        CaseEq(3)
            Add(AB_KPA_MazeProgress, 1)
            Call(GotoMap, Ref("kpa_41"), kpa_41_ENTRY_3)
        CaseOrEq(0)
        CaseOrEq(1)
        CaseOrEq(2)
        CaseOrEq(4)
            Call(GotoMap, Ref("kpa_40"), kpa_40_ENTRY_3)
        EndCaseGroup
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_LowerLeft)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_LowerRight)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_UpperLeft)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_UpperRight)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_41_ENTRY_2)
            Set(AB_KPA_MazeProgress, 5)
        CaseDefault
    EndSwitch
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    Return
    End
};

