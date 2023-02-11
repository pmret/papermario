#include "kkj_02.h"

EvtScript N(EVS_ExitDoors_kkj_01_1) = EVT_EXIT_DOUBLE_DOOR(kkj_02_ENTRY_0, "kkj_01", kkj_01_ENTRY_1,
    COLLIDER_deilit1, MODEL_door1, MODEL_door2);
EvtScript N(EVS_ExitDoors_kkj_03_0) = EVT_EXIT_DOUBLE_DOOR(kkj_02_ENTRY_1, "kkj_03", kkj_03_ENTRY_0,
    COLLIDER_deilit2, MODEL_door4, MODEL_door3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_02_ENTRY_0)
            EVT_SET(LVar2, MODEL_door1)
            EVT_SET(LVar3, MODEL_door2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_02_ENTRY_1)
            EVT_SET(LVar2, MODEL_door4)
            EVT_SET(LVar3, MODEL_door3)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
