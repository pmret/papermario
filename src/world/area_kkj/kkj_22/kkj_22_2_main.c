#include "kkj_22.h"

EvtScript N(EVS_ExitDoor_kkj_13_1) = EVT_EXIT_DOUBLE_DOOR(kkj_22_ENTRY_0, "kkj_13", kkj_13_ENTRY_1, COLLIDER_ttw, MODEL_o51, MODEL_o52);
EvtScript N(EVS_ExitDoor_kkj_23_0) = EVT_EXIT_DOUBLE_DOOR(kkj_22_ENTRY_1, "kkj_23", kkj_23_ENTRY_0, COLLIDER_ttnw, MODEL_o94, MODEL_o95);

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_22_ENTRY_0)
            EVT_SET(LVar2, MODEL_o51)
            EVT_SET(LVar3, MODEL_o52)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_22_ENTRY_1)
            EVT_SET(LVar2, MODEL_o94)
            EVT_SET(LVar3, MODEL_o95)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_22)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_13_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_23_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttnw, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
