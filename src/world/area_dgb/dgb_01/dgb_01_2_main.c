#include "dgb_01.h"

EvtScript N(EVS_ExitDoors_dgb_00_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilitts)
    EVT_SET(LVar2, MODEL_o380)
    EVT_SET(LVar3, MODEL_o381)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_00"), dgb_00_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_02_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, MODEL_o163)
    EVT_SET(LVar3, MODEL_o164)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), dgb_02_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_08_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_SET(LVar2, MODEL_o168)
    EVT_SET(LVar3, MODEL_o167)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_08"), dgb_08_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_09_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_deilittw)
    EVT_SET(LVar2, MODEL_o165)
    EVT_SET(LVar3, MODEL_o166)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), dgb_09_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_08_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_deilitte)
    EVT_SET(LVar2, MODEL_o299)
    EVT_SET(LVar3, MODEL_o298)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_08"), dgb_08_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_17_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_5)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_SET(LVar2, MODEL_o161)
    EVT_SET(LVar3, MODEL_o162)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_17"), dgb_17_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_18_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_01_ENTRY_6)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_SET(LVar2, MODEL_o301)
    EVT_SET(LVar3, MODEL_o300)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_18"), dgb_18_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_01_ENTRY_0)
            EVT_IF_EQ(GF_DGB01_Visited, FALSE)
                EVT_SET(GF_DGB01_Visited, TRUE)
                EVT_SET(GB_StoryProgress, STORY_CH3_ARRIVED_AT_TUBBAS_MANOR)
            EVT_END_IF
            EVT_SET(LVar2, MODEL_o380)
            EVT_SET(LVar3, MODEL_o381)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_01_ENTRY_1)
            EVT_SET(LVar2, MODEL_o163)
            EVT_SET(LVar3, MODEL_o164)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_01_ENTRY_2)
            EVT_SET(LVar2, MODEL_o168)
            EVT_SET(LVar3, MODEL_o167)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_01_ENTRY_3)
            EVT_SET(LVar2, MODEL_o165)
            EVT_SET(LVar3, MODEL_o166)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_01_ENTRY_4)
            EVT_SET(LVar2, MODEL_o299)
            EVT_SET(LVar3, MODEL_o298)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_01_ENTRY_5)
            EVT_SET(LVar2, MODEL_o161)
            EVT_SET(LVar3, MODEL_o162)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_01_ENTRY_6)
            EVT_SET(LVar2, MODEL_o301)
            EVT_SET(LVar3, MODEL_o300)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(KeyList)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_TubbasManor, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupBridges))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_00_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitts, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_08_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_17_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_18_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_IF_EQ(GF_DGB01_UnlockedEastWing, FALSE)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_Door)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_WOKE_UP)
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(GetEntryID, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(dgb_01_ENTRY_2)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(FirstFloorEscapeNPCs)))
                EVT_CASE_EQ(dgb_01_ENTRY_4)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(SecondFloorEscapeNPCs)))
                EVT_CASE_EQ(dgb_01_ENTRY_6)
                    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(ThirdFloorEscapeNPCs)))
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
