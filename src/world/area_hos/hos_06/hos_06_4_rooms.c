#include "hos_06.h"

// unused, makes sense to be in this source file
API_CALLABLE(N(GetEntryID)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetDoorRot_House) = {
    EVT_CALL(RotateGroup, MODEL_g10, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveWalls_House) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g12, LVar1, 0, 0, 1)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g54, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g55, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g56, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g57, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g58, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(2.0))
    EVT_CALL(RotateGroup, MODEL_g86, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_House) = {
    EVT_CALL(RotateGroup, MODEL_g10, LVar0, 1, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToggleVis_House) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_g29, 1)
            EVT_CALL(SetGroupEnabled, MODEL_g81, 1)
            EVT_CALL(SetGroupEnabled, MODEL_g51, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetGroupEnabled, MODEL_g1, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g35, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetGroupEnabled, MODEL_g1, 1)
            EVT_CALL(SetGroupEnabled, MODEL_g35, 1)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_g29, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g81, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g31, 0)
            EVT_CALL(SetGroupEnabled, MODEL_g51, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Downstairs) = {
    EVT_CALL(RotateGroup, MODEL_g32, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Upstairs) = {
    EVT_CALL(RotateGroup, MODEL_g61, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageUpstairsVisibility) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, 100)
        EVT_CALL(SetGroupEnabled, MODEL_g31, 0)
        EVT_CALL(SetGroupEnabled, MODEL_g50, 1)
    EVT_ELSE
        EVT_CALL(SetGroupEnabled, MODEL_g31, 1)
        EVT_CALL(SetGroupEnabled, MODEL_g50, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(SetGroupEnabled, MODEL_g29, 0)
    EVT_CALL(SetGroupEnabled, MODEL_g81, 0)
    EVT_CALL(SetGroupEnabled, MODEL_g31, 0)
    EVT_CALL(SetGroupEnabled, MODEL_g51, 0)
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ManageUpstairsVisibility)), TRIGGER_FLOOR_TOUCH, COLLIDER_o92, 0, 0, 1)
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_0),
        EVT_PTR(N(EVS_SetDoorRot_House)),
        EVT_PTR(N(EVS_MoveWalls_House)),
        EVT_PTR(N(EVS_DropDoor_House)),
        EVT_PTR(N(EVS_ToggleVis_House)),
        COLLIDER_o158,
        COLLIDER_o159,
        MODEL_g2,
        NULL)
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_0),
        EVT_PTR(N(EVS_SetDoorRot_Downstairs)),
        NULL,
        NULL,
        NULL,
        COLLIDER_o161,
        COLLIDER_o160,
        MODEL_o1,
        NULL)
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_1),
        EVT_PTR(N(EVS_SetDoorRot_Upstairs)),
        NULL,
        NULL,
        NULL,
        COLLIDER_o163,
        COLLIDER_o162,
        MODEL_o1,
        NULL)
    EVT_RETURN
    EVT_END
};
