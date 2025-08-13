#include "nok_01.h"

API_CALLABLE(N(OnEnterShop)) {
    status_bar_always_show_on();
    status_bar_ignore_changes();
    open_status_bar_slowly();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(OnExitShop)) {
    status_bar_always_show_off();
    status_bar_respond_to_changes();
    close_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateSwingingSigns) = {
    Label(9)
        Call(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o287, LVar0, 1, 0, 0)
            Call(RotateModel, MODEL_o201, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        Label(11)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o287, LVar0, 1, 0, 0)
            Call(RotateModel, MODEL_o201, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(11)
            EndIf
        Goto(9)
    Return
    End
};

EvtScript N(EVS_SpinCeilingFan) = {
    Label(0)
        Set(LVar0, 35)
        Loop(LVar0)
            Set(LVar1, LVar0)
            Mul(LVar1, 10)
            Call(RotateModel, MODEL_o247, LVar1, 0, -1, 0)
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateModel, MODEL_o200, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallsRot_ToadHouse) = {
    Call(RotateModel, MODEL_o197, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o196, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o195, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o199, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o194, LVar0, 0, 1, 0)
    Call(RotateModel, MODEL_o193, LVar0, 0, 1, 0)
    Call(RotateModel, MODEL_o190, LVar0, 0, 1, 0)
    Call(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Switch(LVar0)
        CaseEq(0)
            Wait(20)
            Set(LVar0, 0)
            Loop(18)
                Add(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_ToadHouse))
            EndLoop
        CaseEq(3)
            Set(LVar0, 90)
            Loop(18)
                Sub(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_ToadHouse))
            EndLoop
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    Call(RotateModel, MODEL_o226, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallsRot_Shop) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 45)
    Call(TranslateModel, MODEL_o225, 0, LVar1, 0)
    Call(RotateModel, MODEL_o225, LVar0, 0, 0, -1)
    Call(RotateModel, MODEL_o224, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o223, LVar0, 0, 0, 1)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Shop) = {
    Switch(LVar0)
        CaseEq(0)
            Wait(20)
            Call(N(OnEnterShop))
            Set(LVar0, 0)
            Loop(18)
                Add(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_Shop))
            EndLoop
        CaseEq(3)
            Call(N(OnExitShop))
            Set(LVar0, 90)
            Loop(18)
                Sub(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_Shop))
            EndLoop
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_BeachHouse) = {
    Call(RotateModel, MODEL_o246, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallsRot_BeachHouse) = {
    SetF(LVar1, LVar0)
    DivF(LVar1, 2)
    Call(RotateModel, MODEL_o243, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o244, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o242, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o245, LVar1, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_BeachHouse) = {
    Switch(LVar0)
        CaseEq(0)
            Set(LVar0, 0)
            Loop(18)
                Add(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_BeachHouse))
            EndLoop
        CaseEq(3)
            Set(LVar0, 90)
            Loop(18)
                Sub(LVar0, 5)
                ExecWait(N(EVS_SetWallsRot_BeachHouse))
            EndLoop
    EndSwitch
    Return
    End
};

EvtScript N(EVS_DropDoor_BeachHouse) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 45)
    Call(TranslateModel, MODEL_o246, 0, LVar1, 0)
    Call(RotateModel, MODEL_o246, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g111, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g111, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_Shop) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g114, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g114, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_BeachHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_g79, MODEL_GROUP_VISIBLE)
            Call(N(SetRadioVolumeMax), AB_NOK_0)
            Exec(N(EVS_FadeOutMusic))
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            Call(N(SetRadioVolumeMute), AB_NOK_0)
            Exec(N(EVS_FadeInMusic))
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_g79, MODEL_GROUP_HIDDEN)
            Call(N(MuteAllRadioStations))
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_MortT,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Koopa_ShopOwner,
    -1
};

s32 N(InteriorNPCs_BeachHouse_Before)[] = {
    NPC_RelaxedKoopa,
    NPC_Bobomb_01,
    NPC_Bobomb_02,
    -1
};

s32 N(InteriorNPCs_BeachHouse_After)[] = {
    NPC_RelaxedKoopa,
    -1
};

EvtScript N(EVS_MakeRooms) = {
    // toad house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        nullptr,
        Ref(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_o200,
        COLLIDER_o284,
        MODEL_aka,
        Ref(N(InteriorNPCs_ToadHouse)))
    // shop
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
        Ref(N(EVS_SetDoorRot_Shop)),
        Ref(N(EVS_SetWallRot_Shop)),
        nullptr,
        Ref(N(EVS_RoomListener_Shop)),
        COLLIDER_o226,
        COLLIDER_o286,
        MODEL_ki,
        Ref(N(InteriorNPCs_Shop)))
    // beach house
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            Ref(N(EVS_SetDoorRot_BeachHouse)),
            Ref(N(EVS_SetWallRot_BeachHouse)),
            Ref(N(EVS_DropDoor_BeachHouse)),
            Ref(N(EVS_RoomListener_BeachHouse)),
            COLLIDER_o246,
            COLLIDER_o291,
            MODEL_ao,
            Ref(N(InteriorNPCs_BeachHouse_Before)))
    Else
        Call(CreateMapRoom,
            PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT | ROOM_FLAG_CUSTOM_ANIM_WALL_ROT),
            Ref(N(EVS_SetDoorRot_BeachHouse)),
            Ref(N(EVS_SetWallRot_BeachHouse)),
            Ref(N(EVS_DropDoor_BeachHouse)),
            Ref(N(EVS_RoomListener_BeachHouse)),
            COLLIDER_o246,
            COLLIDER_o291,
            MODEL_ao,
            Ref(N(InteriorNPCs_BeachHouse_After)))
    EndIf
    Call(N(InitializeRadio))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_ToadHouse))
    Exec(N(EVS_RoomListener_Shop))
    Exec(N(EVS_RoomListener_BeachHouse))
    Exec(N(EVS_AnimateSwingingSigns))
    Exec(N(EVS_SpinCeilingFan))
    Return
    End
};
