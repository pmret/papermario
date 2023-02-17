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
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, kkj_11_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tts)
    EVT_SET(LVar2, MODEL_door2)
    EVT_SET(LVar3, MODEL_door1)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_10"), kkj_10_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kkj_12_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_SET(LVar0, kkj_11_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_ttn)
    EVT_SET(LVar2, MODEL_door3)
    EVT_SET(LVar3, MODEL_door4)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_12"), kkj_12_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kkj_14_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_11_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_ttn2)
    EVT_SET(LVar2, MODEL_door7)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kkj_16_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_11_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_ttsw)
    EVT_SET(LVar2, MODEL_door5)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_16"), kkj_16_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kkj_15_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_11_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_door6)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_15"), kkj_15_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kkj_17_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_11_ENTRY_5)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_door8)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_17"), kkj_17_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kkj_18_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, kkj_11_ENTRY_6)
    EVT_SET(LVar1, COLLIDER_ttse)
    EVT_SET(LVar2, MODEL_door9)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_18"), kkj_18_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_IF_GT(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EVT_END_IF
    EVT_IF_GT(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_12_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_17_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_16_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_15_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_18_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttse, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_11_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_door2)
            EVT_SET(LVar3, MODEL_door1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
            EVT_SET(LVar2, MODEL_door3)
            EVT_SET(LVar3, MODEL_door4)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_2)
            EVT_SET(LVar2, MODEL_door5)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_3)
            EVT_SET(LVar2, MODEL_door6)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_4)
            EVT_SET(LVar2, MODEL_door7)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_5)
            EVT_SET(LVar2, MODEL_door8)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_6)
            EVT_SET(LVar2, MODEL_door9)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(kkj_11_ENTRY_7)
            EVT_EXEC_WAIT(N(EVS_FirstTimeEnterHall))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_11)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_OR_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH3_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EarlyNPCs)))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(STORY_CH6_BEGAN_PEACH_MISSION)
            EVT_CALL(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
            EVT_CALL(EnableModel, MODEL_o364, FALSE)
            EVT_CALL(EnableModel, MODEL_o365, FALSE)
            EVT_CALL(EnableModel, MODEL_o366, FALSE)
            EVT_CALL(N(DisableAllLightSources))
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(LaterNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(EnableModel, MODEL_o364, FALSE)
            EVT_CALL(EnableModel, MODEL_o365, FALSE)
            EVT_CALL(EnableModel, MODEL_o366, FALSE)
            EVT_CALL(N(DisableAllLightSources))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_PlayDemoScene))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
    EVT_END_IF
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
