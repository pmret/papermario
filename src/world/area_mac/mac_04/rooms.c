#include "mac_04.h"

s32 mdl_set_shroud_tint_params(s32, s32, s32, s32);

API_CALLABLE(N(InitEntryFromToybox)) {
    mdl_group_set_custom_gfx(MODEL_heiho_house, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, true);
    mdl_set_shroud_tint_params(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetDoorRot_Shop) = {
    Call(RotateModel, MODEL_msdoor, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Shop) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_my1, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_my2, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_my3, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_my4, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_my5, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_mk1, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_mk2, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_mk3, LVar1, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_Shop) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(EnableGroup, MODEL_mise_in, true)
            Exec(N(EVS_OnEnterShop))
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(EnableGroup, MODEL_mise_in, false)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_NiceHouse) = {
    Call(RotateModel, MODEL_rndoor, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_NiceHouse) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_rnk1, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_rnk2, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_rnk3, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_rnk4, LVar1, 1, 0, 0)
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_rnk5, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_rnk6, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_NiceHouse) = {
    Call(RotateModel, MODEL_rndoor, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_NiceHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(EnableGroup, MODEL_rin_in, true)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(EnableGroup, MODEL_rin_in, false)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Storeroom) = {
    Call(RotateModel, MODEL_skd, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Storeroom) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.781))
    Call(TranslateModel, MODEL_skk1, 0, 0, LVar1)
    Call(TranslateModel, MODEL_skk2, 0, 0, LVar1)
    Call(TranslateModel, MODEL_skk3, 0, 0, LVar1)
    Call(TranslateModel, MODEL_skk4, 0, 0, LVar1)
    Call(TranslateModel, MODEL_skk5, 0, 0, LVar1)
    Call(TranslateModel, MODEL_skk6, 0, 0, LVar1)
    Call(TranslateModel, MODEL_skk7, 0, 0, LVar1)
    Return
    End
};

EvtScript N(EVS_DropDoor_Storeroom) = {
    Call(RotateModel, MODEL_skd, LVar0, 0, 0, -1)
    Return
    End
};

EvtScript N(EVS_RoomListener_Storeroom) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Warehouse) = {
    Call(RotateModel, MODEL_hh_door, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Warehouse) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_hk1, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_hk2, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_hk3, LVar1, 0, 0, -1)
    Return
    End
};

EvtScript N(EVS_RoomListener_Warehouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(EnableGroup, MODEL_heiho_in, true)
            Set(MF_MusicMixTrigger, true)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            Exec(N(EVS_HiddenRoom_WaitForOuttaSight))
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(EnableGroup, MODEL_heiho_in, false)
            Call(EnableGroup, MODEL_hi_soto, true)
            Set(MF_MusicMixTrigger, false)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_HiddenRoom) = {
    Call(RotateModel, MODEL_hkai1, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_hkai2, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_HiddenRoom) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_hk4, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_hk5, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_hk6, LVar1, 0, 0, -1)
    Return
    End
};

EvtScript N(EVS_RoomListener_HiddenRoom) = {
    Return
    End
};

s32 N(InsideNPCs_Shop)[] = {
    NPC_HarryT,
    NPC_ShyGuy_02,
    -1
};

s32 N(InsideNPCs_NiceHouse)[] = {
    NPC_NewResident1,
    NPC_NewResident2,
    -1
};

s32 N(InsideNPCs_Warehouse)[] = {
    NPC_ShyGuy_01,
    -1
};

EvtScript N(EVS_MakeHiddenRoom) = {
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_HiddenRoom)),
        Ref(N(EVS_SetWallRot_HiddenRoom)),
        nullptr,
        Ref(N(EVS_RoomListener_HiddenRoom)),
        COLLIDER_deilit_hk,
        COLLIDER_deilit_hku,
        MODEL_o13,
        nullptr)
    Return
    End
};

EvtScript N(EVS_MakeStoreroom) = {
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_2, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Storeroom)),
        Ref(N(EVS_SetWallRot_Storeroom)),
        Ref(N(EVS_DropDoor_Storeroom)),
        Ref(N(EVS_RoomListener_Storeroom)),
        COLLIDER_deilit_sku,
        COLLIDER_deilit_sk,
        MODEL_o13,
        nullptr)
    Return
    End
};

EvtScript N(EVS_SetupRooms) = {
    // harry's shop on the right
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Shop)),
        Ref(N(EVS_SetWallRot_Shop)),
        nullptr,
        Ref(N(EVS_RoomListener_Shop)),
        COLLIDER_deilit_m,
        COLLIDER_deilit_mu,
        MODEL_mise,
        Ref(N(InsideNPCs_Shop)))
    // nice house in the middle
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_NiceHouse)),
        Ref(N(EVS_SetWallRot_NiceHouse)),
        Ref(N(EVS_DropDoor_NiceHouse)),
        Ref(N(EVS_RoomListener_NiceHouse)),
        COLLIDER_deilit_r,
        COLLIDER_deilit_ru,
        MODEL_rinjin,
        Ref(N(InsideNPCs_NiceHouse)))
    // warehouse on the left
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Warehouse)),
        Ref(N(EVS_SetWallRot_Warehouse)),
        nullptr,
        Ref(N(EVS_RoomListener_Warehouse)),
        COLLIDER_deilit_h,
        COLLIDER_deilit_hu,
        MODEL_heiho_house,
        Ref(N(InsideNPCs_Warehouse)))
    IfGe(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
        ExecWait(N(EVS_MakeStoreroom))
    EndIf
    IfGe(GB_StoryProgress, STORY_CH4_FOUND_HIDDEN_DOOR)
        ExecWait(N(EVS_MakeHiddenRoom))
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(mac_04_ENTRY_2, mac_04_ENTRY_3)
            Call(SetGroupVisibility, MODEL_heiho_in, MODEL_GROUP_VISIBLE)
            Call(N(InitEntryFromToybox))
            Set(LVar0, 90)
            Call(RotateModel, MODEL_hk1, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_hk2, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_hk3, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_hk4, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_hk5, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_hk6, LVar0, 0, 0, -1)
        CaseDefault
            Set(LVar0, ROOM_UPDATE_EXIT_END)
            Exec(N(EVS_RoomListener_Shop))
            Exec(N(EVS_RoomListener_NiceHouse))
    EndSwitch
    Return
    End
};
