#include "obk_01.h"

EvtScript N(EVS_ExitDoors_mim_11_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, obk_01_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_door1_2)
    EVT_SET(LVar3, MODEL_door1_1)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("mim_11"), mim_11_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_02_0) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_WEIGHED_DOWN_CHANDELIER)
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, obk_01_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tt2)
    EVT_SET(LVar2, MODEL_door2)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_02"), obk_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_05_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
        EVT_EXEC(N(EVS_Scene_JumpScareBoo))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, obk_01_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_tt3)
    EVT_SET(LVar2, MODEL_door3)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_05"), obk_05_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_07_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
        EVT_EXEC(N(EVS_Scene_JumpScareBoo))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, obk_01_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_tt4)
    EVT_SET(LVar2, MODEL_door4)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_07"), obk_07_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_08_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
        EVT_EXEC(N(EVS_Scene_JumpScareBoo))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, obk_01_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_tt5)
    EVT_SET(LVar2, MODEL_door5)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_08"), obk_08_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_09_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, obk_01_ENTRY_5)
    EVT_SET(LVar1, COLLIDER_tt6)
    EVT_SET(LVar2, MODEL_door6_1)
    EVT_SET(LVar3, MODEL_door6_2)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_09"), obk_09_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_09_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, obk_01_ENTRY_6)
    EVT_SET(LVar1, COLLIDER_tt6_1)
    EVT_SET(LVar2, MODEL_door7_1)
    EVT_SET(LVar3, MODEL_door7_2)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_09"), obk_09_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_mim_11_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_07_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt4, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt6, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_09_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt6_1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_01_ENTRY_0)
            EVT_IF_EQ(GF_OBK01_Visited, FALSE)
                EVT_SET(GF_OBK01_Visited, TRUE)
                EVT_SET(GB_StoryProgress, STORY_CH3_ENTERED_BOOS_MANSION)
            EVT_END_IF
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_door1_2)
            EVT_SET(LVar3, MODEL_door1_1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(obk_01_ENTRY_1)
            EVT_SET(LVar2, MODEL_door2)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(obk_01_ENTRY_2)
            EVT_SET(LVar2, MODEL_door3)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(obk_01_ENTRY_3)
            EVT_SET(LVar2, MODEL_door4)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(obk_01_ENTRY_4)
            EVT_SET(LVar2, MODEL_door5)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(obk_01_ENTRY_5)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_door6_1)
            EVT_SET(LVar3, MODEL_door6_2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(obk_01_ENTRY_6)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_door7_1)
            EVT_SET(LVar3, MODEL_door7_2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_BoosMansion, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupChandelier))
    EVT_EXEC(N(EVS_SetupPortrait))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
