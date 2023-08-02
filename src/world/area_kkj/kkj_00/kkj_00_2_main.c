#include "kkj_00.h"

EvtScript N(D_80241140_ABC3D0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, kkj_00_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_ttn)
    EVT_SET(LVar2, MODEL_door3)
    EVT_SET(LVar3, MODEL_door4)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_01"), kkj_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802411F4_ABC484) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_00_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_ttne)
    EVT_SET(LVar2, MODEL_door8)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_19"), kkj_19_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowMessage_CantOpen) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_DoesntOpen, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802412F0_ABC580) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(EnableNpcAI, NPC_Luigi, FALSE)
    EVT_CALL(EnableNpcAI, NPC_Toad_01, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_Toad_Red_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 16, MSG_Intro_0026)
    EVT_CALL(EnableNpcAI, NPC_Luigi, TRUE)
    EVT_CALL(EnableNpcAI, NPC_Toad_01, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802413C4_ABC654) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_802412F0_ABC580)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShowMessage_CantOpen)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80241140_ABC3D0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_802411F4_ABC484)), TRIGGER_WALL_PRESS_A, COLLIDER_ttne, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241460_ABC6F0) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_00_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_door2)
            EVT_SET(LVar3, MODEL_door1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_00_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_door3)
            EVT_SET(LVar3, MODEL_door4)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_00_ENTRY_2)
            EVT_SET(LVar2, MODEL_door5)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_00_ENTRY_3)
            EVT_SET(LVar2, MODEL_door8)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_00_ENTRY_4)
            EVT_SET(LVar2, MODEL_door7)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_00_ENTRY_5)
            EVT_EXEC(N(EVS_Scene_Intro))
        EVT_CASE_EQ(kkj_00_ENTRY_6)
            EVT_EXEC(N(EVS_Scene_Ending))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
    EVT_CALL(N(func_80240040_ABB2D0), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024166C) = {
    EVT_CALL(N(func_80240040_ABB2D0), 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_IF_EQ(GB_StoryProgress, STORY_INTRO)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(IntroNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EndingNPCs)))
    EVT_END_IF
    EVT_CALL(EnableGroup, MODEL_g2, FALSE)
    EVT_CALL(EnableGroup, MODEL_g51, FALSE)
    EVT_IF_EQ(GB_StoryProgress, STORY_INTRO)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    EVT_ELSE
        EVT_THREAD
            EVT_WAIT(90)
            EVT_CALL(FadeOutMusic, 0, 3000)
        EVT_END_THREAD
    EVT_END_IF
    EVT_EXEC(N(D_802413C4_ABC654))
    EVT_EXEC(N(D_80241460_ABC6F0))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
