#include "dgb_08.h"

EvtScript N(EVS_ExitDoors_dgb_01_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_08_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_SET(LVar2, MODEL_o142)
    EVT_SET(LVar3, MODEL_o143)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_01_4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_08_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_SET(LVar2, MODEL_o140)
    EVT_SET(LVar3, MODEL_o141)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_08_ENTRY_0)
            EVT_SET(LVar2, MODEL_o142)
            EVT_SET(LVar3, MODEL_o143)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_08_ENTRY_1)
            EVT_SET(LVar2, MODEL_o140)
            EVT_SET(LVar3, MODEL_o141)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_SMASHED_THE_BRIDGES)
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(BeforeNPCs)))
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(TubbaNPCs)))
        EVT_CASE_LT(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(AfterNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_01_4)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
