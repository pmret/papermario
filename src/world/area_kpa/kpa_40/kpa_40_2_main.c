
#include "kpa_40.h"

EvtScript N(EVS_ExitDoors_kpa_52_1) = EVT_EXIT_DOUBLE_DOOR(kpa_40_ENTRY_0, "kpa_52", kpa_52_ENTRY_1, COLLIDER_ttw, MODEL_o526, MODEL_o525);
EvtScript N(EVS_ExitWalk_kpa_40_3) = EVT_EXIT_WALK(60, kpa_40_ENTRY_1, "kpa_40", kpa_40_ENTRY_3);

EvtScript N(EVS_ExitWalk_kpa_41_3) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_40_ENTRY_2)
    Exec(ExitWalk)
    Set(AB_KPA_MazeProgress, 1)
    Call(GotoMap, Ref("kpa_41"), kpa_41_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_52_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_40_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_41_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_40_ENTRY_0)
            Set(LVar0, kpa_40_ENTRY_0)
            Set(LVar2, MODEL_o526)
            Set(LVar3, MODEL_o525)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};


