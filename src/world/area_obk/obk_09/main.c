#include "obk_09.h"

EvtScript N(EVS_EnterMap) = {
    Call(DisablePlayerInput, TRUE)
    Call(EnableGroup, MODEL_ori, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ori, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(obk_09_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_d1_2)
            Set(LVar3, MODEL_d1_1)
            ExecWait(EnterDoubleDoor)
        CaseEq(obk_09_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            Set(LVar2, MODEL_d2_2)
            Set(LVar3, MODEL_d2_1)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Exec(N(EVS_Scene_MeetBow))
    Wait(1)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ExitDoors_obk_01_5) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, obk_09_ENTRY_0)
    Set(LVar1, COLLIDER_tt1)
    Set(LVar2, MODEL_d1_2)
    Set(LVar3, MODEL_d1_1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_01"), obk_01_ENTRY_5)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_obk_01_6) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, obk_09_ENTRY_1)
    Set(LVar1, COLLIDER_tt2)
    Set(LVar2, MODEL_d2_2)
    Set(LVar3, MODEL_d2_1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("obk_01"), obk_01_ENTRY_6)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetEntryID, LVar0)
    IfEq(LVar0, obk_09_ENTRY_2)
        Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
        Exec(N(EVS_Scene_Epilogue))
        Call(FadeInMusic, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 3000, 0, 127)
        Wait(1)
        Return
    EndIf
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    BindTrigger(Ref(N(EVS_ExitDoors_obk_01_5)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_obk_01_6)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    Return
    End
};
