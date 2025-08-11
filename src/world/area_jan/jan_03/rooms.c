#include "jan_03.h"

EvtScript N(EVS_SetDoorRot_Shop) = {
    Call(RotateGroup, MODEL_g48, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Shop) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-1.328125))
    Call(RotateGroup, MODEL_g109, LVar1, 0, 0, 1)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(1.0))
    Call(RotateGroup, MODEL_g110, LVar1, 0, 0, 1)
    Return
    End
};

EvtScript N(EVS_RoomListener_Shop) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(EnableGroup, MODEL_g126, true)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(EnableGroup, MODEL_g126, false)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Yoshi_01,
    -1
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateGroup, MODEL_g111, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Return
    End
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g73, MODEL_GROUP_HIDDEN)
            Call(SetGroupVisibility, MODEL_g97, MODEL_GROUP_HIDDEN)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g73, MODEL_GROUP_VISIBLE)
            Call(SetGroupVisibility, MODEL_g97, MODEL_GROUP_VISIBLE)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_Toad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // shop
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_IN),
        Ref(N(EVS_SetDoorRot_Shop)),
        Ref(N(EVS_SetWallRot_Shop)),
        nullptr,
        Ref(N(EVS_RoomListener_Shop)),
        COLLIDER_o156,
        COLLIDER_o161,
        MODEL_g41,
        Ref(N(InteriorNPCs_Shop)))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_Shop))
    // toad house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        nullptr,
        Ref(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_o199,
        COLLIDER_o200,
        MODEL_o2,
        Ref(N(InteriorNPCs_ToadHouse)))
    Return
    End
};
