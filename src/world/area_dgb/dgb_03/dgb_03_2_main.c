#include "dgb_03.h"

EvtScript N(EVS_ExitDoors_dgb_02_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_03_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_SET(LVar2, MODEL_o102)
    EVT_SET(LVar3, MODEL_o101)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), dgb_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_09_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_03_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_SET(LVar2, MODEL_o106)
    EVT_SET(LVar3, MODEL_o105)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), dgb_09_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_04_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_03_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, MODEL_o30)
    EVT_SET(LVar3, MODEL_o31)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_04"), dgb_04_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_dgb_13_0) = EVT_EXIT_WALK(26, dgb_03_ENTRY_2, "dgb_13", dgb_13_ENTRY_0);

EvtScript N(EVS_ExitDoors_dgb_05_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, dgb_03_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_deilitts)
    EVT_SET(LVar2, MODEL_o76)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_05"), dgb_05_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_14_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_03_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_SET(LVar2, MODEL_o103)
    EVT_SET(LVar3, MODEL_o104)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_14"), dgb_14_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_dgb_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_03_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_o30)
            EVT_SET(LVar3, MODEL_o31)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(dgb_03_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_o102)
            EVT_SET(LVar3, MODEL_o101)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(dgb_03_ENTRY_2)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_SET(LVar2, MODEL_o76)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(dgb_03_ENTRY_3)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_o103)
            EVT_SET(LVar3, MODEL_o104)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(dgb_03_ENTRY_4)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_o106)
            EVT_SET(LVar3, MODEL_o105)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(dgb_03_ENTRY_5)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalkShort)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(KeyList_UpperDoor)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupClock))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_04_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitts, 1, 0)
    EVT_IF_EQ(GF_DGB03_UnlockedThirdFloor, FALSE)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_UpperDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList_UpperDoor)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
