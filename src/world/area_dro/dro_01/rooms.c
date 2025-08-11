#include "dro_01.h"

EvtScript N(EVS_SetDoorRot_LeftHouse) = {
    Call(RotateModel, MODEL_doa1, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_LeftHouse) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 50)
    Call(TranslateModel, MODEL_1_m_kabe, 0, LVar1, 0)
    Call(TranslateModel, MODEL_mado1, 0, LVar1, 0)
    Call(RotateModel, MODEL_1_m_kabe, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_mado1, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_1_m_moyou, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_1_m_waku, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_LeftHouse) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 50)
    Call(TranslateModel, MODEL_doa1, 0, LVar1, 0)
    Call(RotateModel, MODEL_doa1, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    Call(RotateModel, MODEL_m_m_doa, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Shop) = {
    Set(LVar1, LVar0)
    DivF(LVar1, 50)
    Call(TranslateModel, MODEL_m_m_kabe, 0, LVar1, 0)
    Call(TranslateModel, MODEL_m_m_mado, 0, LVar1, 0)
    Call(RotateModel, MODEL_m_m_kabe, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_m_m_mado, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_m_m_hari, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_m_m_moyou, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_m_m_waku, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_m_m_mado2, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_m_m_kabe2, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetDoorRot_RightHouse) = {
    Call(RotateModel, MODEL_doa2, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_RightHouse) = {
    Set(LVar1, LVar0)
    Div(LVar1, 45)
    Call(TranslateModel, MODEL_doa2, 0, LVar1, 0)
    Call(RotateModel, MODEL_doa2, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_RightHouse) = {
    IfEq(LVar0, 90)
        Call(EnableModel, MODEL_nuno, false)
    Else
        Call(EnableModel, MODEL_nuno, true)
    EndIf
    Set(LVar1, LVar0)
    Div(LVar1, 45)
    Set(LVar2, LVar0)
    Sub(LVar2, -90)
    Div(LVar2, -90)
    Call(TranslateModel, MODEL_si_ksbe, 0, LVar1, 0)
    Call(RotateModel, MODEL_si_ksbe, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_ue_waku, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_mado2, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_ue_kabe, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_ue_moyou, LVar0, -1, 0, 0)
    Call(RotateModel, MODEL_bou1, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_nuno, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_LeftHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_ie_naka, true)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_ie_naka, false)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_Shop) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH2_SPOKE_WITH_SHEEK)
                    Call(ShowMessageAtScreenPos, MSG_Menus_017B, 160, 40)
                    Set(LVar0, -1)
                    Return
                CaseLt(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
                    Set(LVar0, -1)
                    Return
            EndSwitch
            Call(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            Thread
                Wait(45)
                Call(SetNpcPos, NPC_Mouser_ShopOwner, 33, 0, -375)
                Call(SetNpcYaw, NPC_Mouser_ShopOwner, 180)
            EndThread
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_HIDDEN)
            Set(AB_DRO_SHOP_PREV1, 0)
            Set(AB_DRO_SHOP_PREV2, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_RightHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_ie2_naka, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_ie2_naka, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_LeftHouse)[] = {
    NPC_Dryite_02,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Mouser_ShopOwner,
    -1
};

s32 N(InteriorNPCs_RightHouse)[] = {
    NPC_ArtistToad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_LeftHouse)),
        Ref(N(EVS_SetWallRot_LeftHouse)),
        Ref(N(EVS_DropDoor_LeftHouse)),
        Ref(N(EVS_RoomListener_LeftHouse)),
        COLLIDER_ei1_1,
        COLLIDER_ei1_2,
        MODEL_k_i1,
        Ref(N(InteriorNPCs_LeftHouse)))
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Shop)),
        Ref(N(EVS_SetWallRot_Shop)),
        nullptr,
        Ref(N(EVS_RoomListener_Shop)),
        COLLIDER_em_1,
        COLLIDER_em_2,
        MODEL_k_m1,
        Ref(N(InteriorNPCs_Shop)))
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_RightHouse)),
        Ref(N(EVS_SetWallRot_RightHouse)),
        Ref(N(EVS_DropDoor_RightHouse)),
        Ref(N(EVS_RoomListener_RightHouse)),
        COLLIDER_ei2_1,
        COLLIDER_ei_2,
        MODEL_k_i2,
        Ref(N(InteriorNPCs_RightHouse)))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_LeftHouse))
    Exec(N(EVS_RoomListener_Shop))
    Exec(N(EVS_RoomListener_RightHouse))
    Return
    End
};

EvtScript N(EVS_SwingSign_Shop) = {
    Label(9)
        Call(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o499, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Call(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        Label(11)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o499, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(11)
            EndIf
        Goto(9)
    Return
    End
};

EvtScript N(EVS_OpenShopDoor) = {
    Call(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_VISIBLE)
    Call(PlaySoundAtCollider, COLLIDER_em_1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 100, 15, EASING_QUADRATIC_OUT)
    Label(10)
        Call(UpdateLerp)
        Exec(N(EVS_SetDoorRot_Shop))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Return
    End
};

EvtScript N(EVS_CloseShopDoor) = {
    Call(MakeLerp, 100, 0, 15, EASING_QUADRATIC_OUT)
    Label(10)
        Call(UpdateLerp)
        Exec(N(EVS_SetDoorRot_Shop))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_em_1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(SetGroupVisibility, MODEL_mise_naka, MODEL_GROUP_HIDDEN)
    Return
    End
};
