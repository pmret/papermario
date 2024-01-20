#include "kpa_121.h"

EvtScript N(EVS_ExitDoors_kpa_83_1) = EVT_EXIT_DOUBLE_DOOR(kpa_121_ENTRY_0, "kpa_83", kpa_83_ENTRY_1, COLLIDER_deilitw, MODEL_o348, MODEL_o356);

EvtScript N(EVS_ExitDoor_osr_02_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Set(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
    EndIf
    Set(LVar0, kpa_121_ENTRY_1)
    Set(LVar1, COLLIDER_deilitte)
    Set(LVar2, MODEL_o340)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("osr_02"), osr_02_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_83_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_osr_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_121_ENTRY_0)
            Set(LVar0, 0)
            Set(LVar2, MODEL_o356)
            Set(LVar3, MODEL_o348)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_121_ENTRY_1)
            Set(LVar0, 1)
            Set(LVar2, MODEL_o340)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
