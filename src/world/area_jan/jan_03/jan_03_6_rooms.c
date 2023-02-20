#include "jan_03.h"

EvtScript N(EVS_SetDoorRot_Shop) = {
    EVT_CALL(RotateGroup, MODEL_g48, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Shop) = {
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.328125))
    EVT_CALL(RotateGroup, MODEL_g109, LVar1, 0, 0, 1)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(1.0))
    EVT_CALL(RotateGroup, MODEL_g110, LVar1, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Shop) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(EnableGroup, MODEL_g126, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(EnableGroup, MODEL_g126, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Yoshi_01,
    -1
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    EVT_CALL(RotateGroup, MODEL_g111, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_g73, MODEL_GROUP_HIDDEN)
            EVT_CALL(SetGroupVisibility, MODEL_g97, MODEL_GROUP_HIDDEN)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_g73, MODEL_GROUP_VISIBLE)
            EVT_CALL(SetGroupVisibility, MODEL_g97, MODEL_GROUP_VISIBLE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_Toad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // shop
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_IN),
        EVT_PTR(N(EVS_SetDoorRot_Shop)),
        EVT_PTR(N(EVS_SetWallRot_Shop)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Shop)),
        COLLIDER_o156,
        COLLIDER_o161,
        MODEL_g41,
        EVT_PTR(N(InteriorNPCs_Shop)))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC(N(EVS_RoomListener_Shop))
    // toad house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_ToadHouse)),
        EVT_PTR(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_o199,
        COLLIDER_o200,
        MODEL_o2,
        EVT_PTR(N(InteriorNPCs_ToadHouse)))
    EVT_RETURN
    EVT_END
};
