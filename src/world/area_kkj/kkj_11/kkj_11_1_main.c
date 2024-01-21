#include "kkj_11.h"

API_CALLABLE(N(DisableAllLightSources)) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gSpriteShadingProfile->sources); i++) {
        gSpriteShadingProfile->sources[i].flags = LIGHT_SOURCE_DISABLED;
    }

    return ApiStatus_DONE2;
}

#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_ExitDoors_kkj_10_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_11_ENTRY_0)
    Set(LVar1, COLLIDER_tts)
    Set(LVar2, MODEL_door2)
    Set(LVar3, MODEL_door1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_10"), kkj_10_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_12_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_11_ENTRY_1)
    Set(LVar1, COLLIDER_ttn)
    Set(LVar2, MODEL_door3)
    Set(LVar3, MODEL_door4)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_12"), kkj_12_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kkj_14_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_11_ENTRY_4)
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

EvtScript N(EVS_ExitDoor_kkj_16_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_11_ENTRY_2)
    Set(LVar1, COLLIDER_ttsw)
    Set(LVar2, MODEL_door5)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_16"), kkj_16_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kkj_15_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_11_ENTRY_3)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_door6)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_15"), kkj_15_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kkj_17_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_11_ENTRY_5)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_door8)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_17"), kkj_17_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kkj_18_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_11_ENTRY_6)
    Set(LVar1, COLLIDER_ttse)
    Set(LVar2, MODEL_door9)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_18"), kkj_18_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    IfGt(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        BindTrigger(Ref(N(EVS_ExitDoors_kkj_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EndIf
    IfGt(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
        BindTrigger(Ref(N(EVS_ExitDoors_kkj_12_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
        BindTrigger(Ref(N(EVS_ExitDoor_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_17_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_16_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_15_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_18_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_11_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door2)
            Set(LVar3, MODEL_door1)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_11_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door3)
            Set(LVar3, MODEL_door4)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_11_ENTRY_2)
            Set(LVar2, MODEL_door5)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_11_ENTRY_3)
            Set(LVar2, MODEL_door6)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_11_ENTRY_4)
            Set(LVar2, MODEL_door7)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_11_ENTRY_5)
            Set(LVar2, MODEL_door8)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_11_ENTRY_6)
            Set(LVar2, MODEL_door9)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_11_ENTRY_7)
            ExecWait(N(EVS_FirstTimeEnterHall))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_11)
    SetUP_CAMERA_NO_LEAD()
    Switch(GB_StoryProgress)
        CaseOrEq(STORY_CH1_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH2_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH3_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH4_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH5_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(EarlyNPCs)))
        EndCaseGroup
        CaseEq(STORY_CH6_BEGAN_PEACH_MISSION)
            Call(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
            Call(EnableModel, MODEL_o364, FALSE)
            Call(EnableModel, MODEL_o365, FALSE)
            Call(EnableModel, MODEL_o366, FALSE)
            Call(N(DisableAllLightSources))
            Call(MakeNpcs, FALSE, Ref(N(LaterNPCs)))
        CaseDefault
            Call(EnableModel, MODEL_o364, FALSE)
            Call(EnableModel, MODEL_o365, FALSE)
            Call(EnableModel, MODEL_o366, FALSE)
            Call(N(DisableAllLightSources))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_PlayDemoScene))
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
    EndIf
    Exec(N(EVS_BindExitTriggers))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
