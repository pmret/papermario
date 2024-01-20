#include "kkj_10.h"

API_CALLABLE(N(DisableAllLightSources)) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gSpriteShadingProfile->sources); i++) {
        gSpriteShadingProfile->sources[i].flags = LIGHT_SOURCE_DISABLED;
    }

    return ApiStatus_DONE2;
}

#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_ExitDoors_osr_02_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_10_ENTRY_0)
    Set(LVar1, COLLIDER_tts)
    Set(LVar2, MODEL_door2)
    Set(LVar3, MODEL_door1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("osr_02"), osr_02_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_11_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_10_ENTRY_1)
    Set(LVar1, COLLIDER_ttn)
    Set(LVar2, MODEL_door3)
    Set(LVar3, MODEL_door4)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_11"), kkj_11_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_21_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_10_ENTRY_2)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_door5)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_21"), kkj_21_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_19_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_10_ENTRY_3)
    Set(LVar1, COLLIDER_ttne)
    Set(LVar2, MODEL_door8)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_19"), kkj_19_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_20_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_10_ENTRY_4)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_door7)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_20"), kkj_20_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_29_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_10_ENTRY_2)
    Set(LVar1, COLLIDER_ttw)
    Set(LVar2, MODEL_door5)
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_29"), kkj_29_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    IfGt(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        BindTrigger(Ref(N(EVS_ExitDoors_osr_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EndIf
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH5_BEGAN_PEACH_MISSION)
            BindTrigger(Ref(N(EVS_ExitDoors_kkj_29_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
        CaseDefault
            BindTrigger(Ref(N(EVS_ExitDoors_kkj_21_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EndSwitch
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_11_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_19_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttne, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_20_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_10_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door2)
            Set(LVar3, MODEL_door1)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_10_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door3)
            Set(LVar3, MODEL_door4)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_10_ENTRY_2)
            Set(LVar2, MODEL_door5)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_10_ENTRY_3)
            Set(LVar2, MODEL_door8)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_10_ENTRY_4)
            Set(LVar2, MODEL_door7)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_10)
    SetUP_CAMERA_NO_LEAD()
    Switch(GB_StoryProgress)
        CaseOrEq(STORY_CH4_BEGAN_PEACH_MISSION)
        CaseOrEq(STORY_CH5_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(EarlyNPCs)))
        EndCaseGroup
        CaseEq(STORY_CH6_BEGAN_PEACH_MISSION)
            Call(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
            Call(MakeNpcs, FALSE, Ref(N(LaterNPCs)))
        CaseDefault
            Call(EnableModel, MODEL_o273, FALSE)
            Call(EnableModel, MODEL_o274, FALSE)
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        Call(N(DisableAllLightSources))
    EndIf
    IfLt(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        Call(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 1, 8)
    EndIf
    Exec(N(EVS_BindExitTriggers))
    Exec(N(EVS_EnterMap))
    Return
    End
};
