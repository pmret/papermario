#include "obk_01.h"

EvtScript N(EVS_ExitDoors_mim_11_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, obk_01_ENTRY_0)
    Set(LVar1, COLLIDER_tt1)
    Set(LVar2, MODEL_door1_2)
    Set(LVar3, MODEL_door1_1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("mim_11"), mim_11_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_02_0) = {
    IfLt(GB_StoryProgress, STORY_CH3_WEIGHED_DOWN_CHANDELIER)
        Return
    EndIf
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, obk_01_ENTRY_1)
    Set(LVar1, COLLIDER_tt2)
    Set(LVar2, MODEL_door2)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_02"), obk_02_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_05_0) = {
    SetGroup(EVT_GROUP_1B)
    IfLt(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
        Exec(N(EVS_Scene_JumpScareBoo))
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, obk_01_ENTRY_2)
    Set(LVar1, COLLIDER_tt3)
    Set(LVar2, MODEL_door3)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_05"), obk_05_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_07_0) = {
    SetGroup(EVT_GROUP_1B)
    IfLt(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
        Exec(N(EVS_Scene_JumpScareBoo))
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, obk_01_ENTRY_3)
    Set(LVar1, COLLIDER_tt4)
    Set(LVar2, MODEL_door4)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_07"), obk_07_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_08_0) = {
    SetGroup(EVT_GROUP_1B)
    IfLt(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
        Exec(N(EVS_Scene_JumpScareBoo))
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, obk_01_ENTRY_4)
    Set(LVar1, COLLIDER_tt5)
    Set(LVar2, MODEL_door5)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_08"), obk_08_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_09_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, obk_01_ENTRY_5)
    Set(LVar1, COLLIDER_tt6)
    Set(LVar2, MODEL_door6_1)
    Set(LVar3, MODEL_door6_2)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_09"), obk_09_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_obk_09_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, obk_01_ENTRY_6)
    Set(LVar1, COLLIDER_tt6_1)
    Set(LVar2, MODEL_door7_1)
    Set(LVar3, MODEL_door7_2)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_09"), obk_09_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_mim_11_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_obk_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_obk_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_obk_07_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt4, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_obk_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt5, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_obk_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt6, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_obk_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt6_1, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Exec(N(EVS_BindExitTriggers))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(obk_01_ENTRY_0)
            IfEq(GF_OBK01_Visited, FALSE)
                Set(GF_OBK01_Visited, TRUE)
                Set(GB_StoryProgress, STORY_CH3_ENTERED_BOOS_MANSION)
            EndIf
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_door1_2)
            Set(LVar3, MODEL_door1_1)
            ExecWait(EnterDoubleDoor)
        CaseEq(obk_01_ENTRY_1)
            Set(LVar2, MODEL_door2)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(obk_01_ENTRY_2)
            Set(LVar2, MODEL_door3)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(obk_01_ENTRY_3)
            Set(LVar2, MODEL_door4)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(obk_01_ENTRY_4)
            Set(LVar2, MODEL_door5)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(obk_01_ENTRY_5)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_door6_1)
            Set(LVar3, MODEL_door6_2)
            ExecWait(EnterDoubleDoor)
        CaseEq(obk_01_ENTRY_6)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_door7_1)
            Set(LVar3, MODEL_door7_2)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(GF_MAP_BoosMansion, TRUE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupChandelier))
    Exec(N(EVS_SetupPortrait))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Return
    End
};
