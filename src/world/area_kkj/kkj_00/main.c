#include "kkj_00.h"

EvtScript N(D_80241140_ABC3D0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, kkj_00_ENTRY_1)
    Set(LVar1, COLLIDER_ttn)
    Set(LVar2, MODEL_door3)
    Set(LVar3, MODEL_door4)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_01"), kkj_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(D_802411F4_ABC484) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, kkj_00_ENTRY_3)
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

EvtScript N(EVS_ShowMessage_CantOpen) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_DoesntOpen, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(D_802412F0_ABC580) = {
    Call(DisablePlayerInput, TRUE)
    Call(EnableNpcAI, NPC_Luigi, FALSE)
    Call(EnableNpcAI, NPC_Toad_01, FALSE)
    Call(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    Call(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 16, MSG_Intro_0026)
    Call(EnableNpcAI, NPC_Luigi, TRUE)
    Call(EnableNpcAI, NPC_Toad_01, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(D_802413C4_ABC654) = {
    BindTrigger(Ref(N(D_802412F0_ABC580)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(D_80241140_ABC3D0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    BindTrigger(Ref(N(D_802411F4_ABC484)), TRIGGER_WALL_PRESS_A, COLLIDER_ttne, 1, 0)
    Return
    End
};

EvtScript N(D_80241460_ABC6F0) = {
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_00_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door2)
            Set(LVar3, MODEL_door1)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_00_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_door3)
            Set(LVar3, MODEL_door4)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_00_ENTRY_2)
            Set(LVar2, MODEL_door5)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_00_ENTRY_3)
            Set(LVar2, MODEL_door8)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_00_ENTRY_4)
            Set(LVar2, MODEL_door7)
            Set(LVar3, DOOR_SWING_OUT)
            ExecWait(EnterSingleDoor)
        CaseEq(kkj_00_ENTRY_5)
            Exec(N(EVS_Scene_Intro))
        CaseEq(kkj_00_ENTRY_6)
            Exec(N(EVS_Scene_Ending))
    EndSwitch
    Return
    End
};

SlideParams N(SlideData1) = {
    .heading = 358.5f,
    .maxDescendAccel = 0.5f,
    .launchVel = 20.0f,
    .maxDescendVel = 0.0f,
    .integrator = { 0.0, 0.0, 0.0, 0.0 },
};

SlideParams N(SlideData2) = {
    .heading = 1.5f,
    .maxDescendAccel = 0.5f,
    .launchVel = 20.0f,
    .maxDescendVel = 0.0f,
    .integrator = { 0.0, 0.0, 0.0, 0.0 },
};

API_CALLABLE(N(func_80240040_ABB2D0)) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* status = &gPlayerStatus;

    if (evt_get_variable(script, *args++) == 0) {
        status->slideParams = &N(SlideData1);
    } else {
        status->slideParams = &N(SlideData2);
    }

    status->flags |= PS_FLAG_SLIDING;
    return ApiStatus_DONE2;
}

EvtScript N(D_8024164C_ABC8DC) = {
    Call(N(func_80240040_ABB2D0), 0)
    Return
    End
};

EvtScript N(EVS_8024166C) = {
    Call(N(func_80240040_ABB2D0), 1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(MakeNpcs, FALSE, Ref(N(IntroNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(EndingNPCs)))
    EndIf
    Call(EnableGroup, MODEL_g2, FALSE)
    Call(EnableGroup, MODEL_g51, FALSE)
    IfEq(GB_StoryProgress, STORY_INTRO)
        Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    Else
        Thread
            Wait(90)
            Call(FadeOutMusic, 0, 3000)
        EndThread
    EndIf
    Exec(N(D_802413C4_ABC654))
    Exec(N(D_80241460_ABC6F0))
    Wait(1)
    Return
    End
};
