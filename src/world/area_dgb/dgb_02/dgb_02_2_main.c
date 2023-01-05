#include "dgb_02.h"

EvtScript N(EVS_ExitDoors_dgb_03_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_02_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittw)
    EVT_SET(LVar2, MODEL_o30)
    EVT_SET(LVar3, MODEL_o31)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), dgb_03_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_01_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_02_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilitte)
    EVT_SET(LVar2, MODEL_o102)
    EVT_SET(LVar3, MODEL_o101)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_dgb_07_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, dgb_02_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_SET(LVar2, MODEL_o76)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_07"), dgb_07_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_dgb_11_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, dgb_02_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_SET(LVar2, MODEL_o123)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_11"), dgb_11_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_02_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_o30)
            EVT_SET(LVar3, MODEL_o31)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_02_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_o102)
            EVT_SET(LVar3, MODEL_o101)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_02_ENTRY_2)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_SET(LVar2, MODEL_o76)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(dgb_02_ENTRY_3)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_SET(LVar2, MODEL_o123)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_03_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_dgb_07_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_dgb_11_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
