#include "hos_03.h"

EvtScript N(EVS_SetDoorRot_House) = {
    Call(RotateGroup, MODEL_g54, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_House) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-1.0))
    Call(RotateGroup, MODEL_g71, LVar1, 0, 0, 1)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-0.5))
    Call(RotateGroup, MODEL_g72, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(0.5))
    Call(RotateGroup, MODEL_g73, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_House) = {
    Call(RotateGroup, MODEL_g54, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    Call(RotateGroup, MODEL_g42, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Shop) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-1.0))
    Call(RotateGroup, MODEL_g64, LVar1, 0, 0, 1)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-0.5))
    Call(RotateGroup, MODEL_g65, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(0.5))
    Call(RotateGroup, MODEL_g66, LVar1, 0, 1, 0)
    Return
    End
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_StarMan_ShopOwner,
    -1
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateGroup, MODEL_g33, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-1.0))
    Call(RotateGroup, MODEL_g58, LVar1, 0, 0, 1)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-0.5))
    Call(RotateGroup, MODEL_g55, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(0.5))
    Call(RotateGroup, MODEL_g56, LVar1, 0, 1, 0)
    Switch(LVar0)
        CaseEq(90)
            Call(EnableModel, MODEL_o177, false)
        CaseDefault
            Call(EnableModel, MODEL_o177, true)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_StarMan_ToadHouse,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_House)),
        Ref(N(EVS_SetWallRot_House)),
        Ref(N(EVS_DropDoor_House)),
        nullptr,
        COLLIDER_o99,
        COLLIDER_o184,
        MODEL_o76,
        nullptr)
    // shop
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Shop)),
        Ref(N(EVS_SetWallRot_Shop)),
        nullptr,
        nullptr,
        COLLIDER_o72,
        COLLIDER_o185,
        MODEL_o76,
        Ref(N(InteriorNPCs_Shop)))
    // toad house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        nullptr,
        nullptr,
        COLLIDER_o100,
        COLLIDER_o186,
        MODEL_o76,
        Ref(N(InteriorNPCs_ToadHouse)))
    Return
    End
};
