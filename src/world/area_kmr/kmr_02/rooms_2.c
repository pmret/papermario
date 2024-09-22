#include "kmr_02.h"

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateModel, MODEL_o275, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Set(LVar1, LVar0)
    Add(LVar1, LVar0)
    Call(RotateModel, MODEL_k_k_1, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_k_k_2, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_k_k_3, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o272, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_kino_in, MODEL_GROUP_VISIBLE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o767, COLLIDER_FLAGS_UPPER_MASK)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            Thread
                Wait(5)
            EndThread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_kino_in, MODEL_GROUP_HIDDEN)
            Call(EnableModel, MODEL_o422, TRUE)
            Call(EnableModel, MODEL_o424, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetWallsDown_ToadHouse) = {
    Call(SetGroupVisibility, MODEL_kino_in, MODEL_GROUP_VISIBLE)
    Call(RotateModel, MODEL_k_k_1, 180, 0, 1, 0)
    Call(RotateModel, MODEL_k_k_2, 180, 0, 1, 0)
    Call(RotateModel, MODEL_k_k_3, 180, 0, 1, 0)
    Call(RotateModel, MODEL_o272, 180, 0, 1, 0)
    Call(EnableModel, MODEL_o561, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o767, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_ToadSignSwinging) = {
    Label(9)
        Call(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_kanban, LVar0, Float(35.498), 0, Float(-9.511))
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        Label(11)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_kanban, LVar0, Float(35.498), 0, Float(-9.511))
            Wait(1)
            IfEq(LVar1, 1)
                Goto(11)
            EndIf
        Goto(9)
    Return
    End
};

s32 N(InsideNPCs_ToadHouse)[] = {
    NPC_Toad,
    -1
};

EvtScript N(EVS_SetupToadHouse) = {
    Call(RotateModel, MODEL_o320, 180, 0, 1, 0)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kmr_02_ENTRY_5)
        Call(SetGroupVisibility, MODEL_kino_in, MODEL_GROUP_HIDDEN)
    EndIf
    // toad house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        Ref(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_deilit7,
        COLLIDER_deilit8,
        MODEL_kinopi,
        Ref(N(InsideNPCs_ToadHouse)))
    Exec(N(EVS_ToadSignSwinging))
    Return
    End
};
