#include "hos_03.h"

EvtScript N(EVS_SetDoorRot_House) = {
    EVT_CALL(RotateGroup, MODEL_g54, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_House) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.0))
    EVT_CALL(RotateGroup, MODEL_g71, LVar1, 0, 0, 1)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.5))
    EVT_CALL(RotateGroup, MODEL_g72, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(0.5))
    EVT_CALL(RotateGroup, MODEL_g73, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_House) = {
    EVT_CALL(RotateGroup, MODEL_g54, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    EVT_CALL(RotateGroup, MODEL_g42, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Shop) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.0))
    EVT_CALL(RotateGroup, MODEL_g64, LVar1, 0, 0, 1)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.5))
    EVT_CALL(RotateGroup, MODEL_g65, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(0.5))
    EVT_CALL(RotateGroup, MODEL_g66, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_StarMan_ShopOwner,
    -1
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateGroup, MODEL_g33, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.0))
    EVT_CALL(RotateGroup, MODEL_g58, LVar1, 0, 0, 1)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-0.5))
    EVT_CALL(RotateGroup, MODEL_g55, LVar1, 0, 1, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(0.5))
    EVT_CALL(RotateGroup, MODEL_g56, LVar1, 0, 1, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(90)
            EVT_CALL(EnableModel, MODEL_o177, FALSE)
        EVT_CASE_DEFAULT
            EVT_CALL(EnableModel, MODEL_o177, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_StarMan_ToadHouse,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_House)),
        EVT_PTR(N(EVS_SetWallRot_House)),
        EVT_PTR(N(EVS_DropDoor_House)),
        NULL,
        COLLIDER_o99,
        COLLIDER_o184,
        MODEL_o76,
        NULL)
    // shop
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Shop)),
        EVT_PTR(N(EVS_SetWallRot_Shop)),
        NULL,
        NULL,
        COLLIDER_o72,
        COLLIDER_o185,
        MODEL_o76,
        EVT_PTR(N(InteriorNPCs_Shop)))
    // toad house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        NULL,
        COLLIDER_o100,
        COLLIDER_o186,
        MODEL_o76,
        EVT_PTR(N(InteriorNPCs_ToadHouse)))
    EVT_RETURN
    EVT_END
};
