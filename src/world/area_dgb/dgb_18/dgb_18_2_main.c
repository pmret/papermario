#include "dgb_18.h"

EvtScript N(EVS_ExitDoors_dgb_01_6) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, dgb_18_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittw)
    EVT_SET(LVar2, MODEL_o140)
    EVT_SET(LVar3, MODEL_o141)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), dgb_01_ENTRY_6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(dgb_18_ENTRY_0)
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
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_01_6)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
