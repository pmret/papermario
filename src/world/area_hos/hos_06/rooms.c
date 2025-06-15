#include "hos_06.h"

// unused, makes sense to be in this source file
API_CALLABLE(N(GetEntryID)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetDoorRot_House) = {
    Call(RotateGroup, MODEL_g10, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_House) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g12, LVar1, 0, 0, 1)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g54, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g55, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g56, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g57, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g58, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateGroup, MODEL_g86, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_House) = {
    Call(RotateGroup, MODEL_g10, LVar0, 1, 0, 1)
    Return
    End
};

EvtScript N(EVS_RoomListener_House) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g29, MODEL_GROUP_VISIBLE)
            Call(SetGroupVisibility, MODEL_g81, MODEL_GROUP_VISIBLE)
            Call(SetGroupVisibility, MODEL_g51, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            Call(SetGroupVisibility, MODEL_g1, MODEL_GROUP_HIDDEN)
            Call(SetGroupVisibility, MODEL_g35, MODEL_GROUP_HIDDEN)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            Call(SetGroupVisibility, MODEL_g1, MODEL_GROUP_VISIBLE)
            Call(SetGroupVisibility, MODEL_g35, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g29, MODEL_GROUP_HIDDEN)
            Call(SetGroupVisibility, MODEL_g81, MODEL_GROUP_HIDDEN)
            Call(SetGroupVisibility, MODEL_g31, MODEL_GROUP_HIDDEN)
            Call(SetGroupVisibility, MODEL_g51, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Downstairs) = {
    Call(RotateGroup, MODEL_g32, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Upstairs) = {
    Call(RotateGroup, MODEL_g61, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_ManageUpstairsVisibility) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar1, 100)
        Call(SetGroupVisibility, MODEL_g31, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g50, MODEL_GROUP_VISIBLE)
    Else
        Call(SetGroupVisibility, MODEL_g31, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_g50, MODEL_GROUP_HIDDEN)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupRooms) = {
    Call(SetGroupVisibility, MODEL_g29, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_g81, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_g31, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_g51, MODEL_GROUP_HIDDEN)
    BindPadlock(Ref(N(EVS_ManageUpstairsVisibility)), TRIGGER_FLOOR_TOUCH, COLLIDER_o92, 0, 0, 1)
    // front door
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_House)),
        Ref(N(EVS_SetWallRot_House)),
        Ref(N(EVS_DropDoor_House)),
        Ref(N(EVS_RoomListener_House)),
        COLLIDER_o158,
        COLLIDER_o159,
        MODEL_g2,
        nullptr)
    // staircase
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Downstairs)),
        nullptr,
        nullptr,
        nullptr,
        COLLIDER_o161,
        COLLIDER_o160,
        MODEL_o1,
        nullptr)
    // loft
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_IN),
        Ref(N(EVS_SetDoorRot_Upstairs)),
        nullptr,
        nullptr,
        nullptr,
        COLLIDER_o163,
        COLLIDER_o162,
        MODEL_o1,
        nullptr)
    Return
    End
};
