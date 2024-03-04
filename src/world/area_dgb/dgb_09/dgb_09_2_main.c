#include "dgb_09.h"

EvtScript N(exitDoubleDoor_80243920) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, dgb_09_ENTRY_0)
    Set(LVar1, COLLIDER_deilittw)
    Set(LVar2, MODEL_o30)
    Set(LVar3, MODEL_o31)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_03"), dgb_03_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(exitDoubleDoor_802439D4) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, dgb_09_ENTRY_1)
    Set(LVar1, COLLIDER_deilitte)
    Set(LVar2, MODEL_o102)
    Set(LVar3, MODEL_o101)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_01"), dgb_01_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(exitSingleDoor_80243A88) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, dgb_09_ENTRY_2)
    Set(LVar1, COLLIDER_deilittnw)
    Set(LVar2, MODEL_o76)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_12"), dgb_12_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(exitWalk_80243B3C) = EVT_EXIT_WALK(40, dgb_09_ENTRY_3, "dgb_10", dgb_10_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(exitWalk_80243B3C)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    Return
    End
};

EvtScript N(enterWalk_80243BC4) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_09_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_o30)
            Set(LVar3, MODEL_o31)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(dgb_09_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_o102)
            Set(LVar3, MODEL_o101)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(dgb_09_ENTRY_2)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            Set(LVar2, MODEL_o76)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(dgb_09_ENTRY_3)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    EndIf
    Exec(N(EVS_SetupBreakable))
    BindTrigger(Ref(N(exitDoubleDoor_80243920)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    BindTrigger(Ref(N(exitDoubleDoor_802439D4)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    BindTrigger(Ref(N(exitSingleDoor_80243A88)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Exec(N(EVS_SetupMusic))
    Exec(N(enterWalk_80243BC4))
    Return
    End
};
