#include "dgb_14.h"
#include "sprite/player.h"

EvtScript N(EVS_ExitDoors_dgb_03_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_14_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_SET(LVar2, MODEL_o102)
    EVT_SET(LVar3, MODEL_o101)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_03"), dgb_03_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_dgb_15_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_14_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_SET(LVar2, MODEL_o31)
    EVT_SET(LVar3, MODEL_o30)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_15"), dgb_15_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_14_ENTRY_0)
            EVT_SET(LVar2, MODEL_o102)
            EVT_SET(LVar3, MODEL_o101)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(dgb_14_ENTRY_1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_SET(LVar2, MODEL_o31)
            EVT_SET(LVar3, MODEL_o30)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_IF_EQ(AF_DGB_01, TRUE)
                EVT_WAIT(5)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
                EVT_WAIT(20)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_END_IF
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_03_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_15_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
