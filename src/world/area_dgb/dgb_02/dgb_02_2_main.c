#include "dgb_02.h"

EvtScript N(EVS_ExitDoors_dgb_03_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, dgb_02_ENTRY_0)
    Set(LVar1, COLLIDER_deilittw)
    Set(LVar2, MODEL_o30)
    Set(LVar3, MODEL_o31)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_03"), dgb_03_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_dgb_01_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, dgb_02_ENTRY_1)
    Set(LVar1, COLLIDER_deilitte)
    Set(LVar2, MODEL_o102)
    Set(LVar3, MODEL_o101)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_01"), dgb_01_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_dgb_07_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, dgb_02_ENTRY_2)
    Set(LVar1, COLLIDER_deilittnw)
    Set(LVar2, MODEL_o76)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_07"), dgb_07_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_dgb_11_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, dgb_02_ENTRY_3)
    Set(LVar1, COLLIDER_deilittne)
    Set(LVar2, MODEL_o123)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_11"), dgb_11_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_02_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_o30)
            Set(LVar3, MODEL_o31)
            ExecWait(EnterDoubleDoor)
        CaseEq(dgb_02_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_o102)
            Set(LVar3, MODEL_o101)
            ExecWait(EnterDoubleDoor)
        CaseEq(dgb_02_ENTRY_2)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            Set(LVar2, MODEL_o76)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(dgb_02_ENTRY_3)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            Set(LVar2, MODEL_o123)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_dgb_03_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_dgb_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_dgb_07_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_dgb_11_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Return
    End
};
