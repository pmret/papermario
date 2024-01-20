#include "kkj_26.h"

#include "../common/RestoreFromPeachState.inc.c"

EvtScript N(EVS_GotoMap_hos_00_1) = {
    Set(LVar0, GB_KKJ_LastPartner)
    Call(N(RestoreFromPeachState))
    Call(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    Call(GotoMapSpecial, Ref("hos_00"), hos_00_ENTRY_1, TRANSITION_END_PEACH_INTERLUDE)
    Wait(100)
};

EvtScript N(EVS_ExitDoors_kkj_14_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kkj_26_ENTRY_0)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_o85)
    Set(LVar3, MODEL_o83)
    Set(LVar4, MODEL_o86)
    Set(LVar5, MODEL_o84)
    Exec(ExitSplitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_14_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_26_ENTRY_0)
            Set(LVar2, MODEL_o85)
            Set(LVar3, MODEL_o83)
            Set(LVar4, MODEL_o86)
            Set(LVar5, MODEL_o84)
            ExecWait(EnterSplitDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kkj_26_ENTRY_1)
            Exec(N(EVS_Scene_AfterAllSpiritsRescued))
        CaseEq(kkj_26_ENTRY_2)
            Exec(N(EVS_Scene_WhereIsMario))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_26)
    SetUP_CAMERA_DEFAULT()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_26_ENTRY_1)
        Set(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_DOOR)
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_PlayDemoScene))
        Return
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
