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
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, kkj_10_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tts)
    EVT_SET(LVar2, MODEL_door2)
    EVT_SET(LVar3, MODEL_door1)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("osr_02"), osr_02_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kkj_11_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, kkj_10_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_ttn)
    EVT_SET(LVar2, MODEL_door3)
    EVT_SET(LVar3, MODEL_door4)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kkj_21_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_10_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_door5)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_21"), kkj_21_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kkj_19_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_10_ENTRY_3)
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

EvtScript N(EVS_ExitDoors_kkj_20_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_10_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_door7)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_20"), kkj_20_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kkj_29_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_10_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_door5)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_29"), kkj_29_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_IF_GT(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_osr_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_29_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
        EVT_CASE_DEFAULT
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_21_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_END_SWITCH
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_11_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_19_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_20_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_10_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_door2)
            EVT_SET(LVar3, MODEL_door1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_10_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_door3)
            EVT_SET(LVar3, MODEL_door4)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_10_ENTRY_2)
            EVT_SET(LVar2, MODEL_door5)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_10_ENTRY_3)
            EVT_SET(LVar2, MODEL_door8)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_10_ENTRY_4)
            EVT_SET(LVar2, MODEL_door7)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_10)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_OR_EQ(STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EarlyNPCs)))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(STORY_CH6_BEGAN_PEACH_MISSION)
            EVT_CALL(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(LaterNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(EnableModel, MODEL_o273, FALSE)
            EVT_CALL(EnableModel, MODEL_o274, FALSE)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        EVT_CALL(N(DisableAllLightSources))
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 1, 8)
    EVT_END_IF
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
