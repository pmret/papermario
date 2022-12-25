#include "obk_09.h"

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(EnableGroup, MODEL_ori, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ori, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_09_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_d1_2)
            EVT_SET(LVar3, MODEL_d1_1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(obk_09_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_SET(LVar2, MODEL_d2_2)
            EVT_SET(LVar3, MODEL_d2_1)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_Scene_MeetBow))
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_obk_01_5) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, obk_09_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_d1_2)
    EVT_SET(LVar3, MODEL_d1_1)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_01"), obk_01_ENTRY_5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_obk_01_6) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, obk_09_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_tt2)
    EVT_SET(LVar2, MODEL_d2_2)
    EVT_SET(LVar3, MODEL_d2_1)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_01"), obk_01_ENTRY_6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, obk_09_ENTRY_2)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
        EVT_EXEC(N(EVS_Scene_Epilogue))
        EVT_CALL(FadeInMusic, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 3000, 0, 127)
        EVT_WAIT(1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_obk_01_5)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_obk_01_6)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
