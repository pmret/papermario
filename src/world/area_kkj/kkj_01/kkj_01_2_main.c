#include "kkj_01.h"

EvtScript N(EVS_ExitDoors_kkj_00_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_01_ENTRY_0)
    Set(LVar1, COLLIDER_tts)
    Set(LVar2, MODEL_door2)
    Set(LVar3, MODEL_door1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_00"), kkj_00_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_02_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_01_ENTRY_1)
    Set(LVar1, COLLIDER_ttn)
    Set(LVar2, MODEL_door3)
    Set(LVar3, MODEL_door4)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_02"), kkj_02_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_14_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_01_ENTRY_4)
    Set(LVar1, COLLIDER_ttn2)
    Set(LVar2, MODEL_door7)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ShowMessage_CantOpen) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_DoesntOpen, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    IfEq(AF_KKJ_01, TRUE)
        BindTrigger(Ref(N(EVS_ExitDoors_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_ttsw, 1, 0)
    BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_00_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_01_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door2)
            Set(LVar3, MODEL_door1)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_01_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door3)
            Set(LVar3, MODEL_door4)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_01_ENTRY_2)
            Set(LVar2, MODEL_door5)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_01_ENTRY_3)
            Set(LVar2, MODEL_door6)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_01_ENTRY_4)
            Set(LVar2, MODEL_door7)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_01_ENTRY_5)
            Set(LVar2, MODEL_door8)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_01_ENTRY_6)
            Set(LVar2, MODEL_door9)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    IfNe(GB_StoryProgress, STORY_INTRO)
        Call(EnableModel, MODEL_g74, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g77, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableModel, MODEL_o321, FALSE)
        Call(EnableModel, MODEL_o337, FALSE)
        Call(EnableModel, MODEL_o330, FALSE)
    EndIf
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_BindExitTriggers))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};

MAP_RODATA_PAD(1, exits);
