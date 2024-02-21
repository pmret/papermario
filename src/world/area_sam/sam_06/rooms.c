#include "sam_06.h"

EvtScript N(EVS_SetDoorRot_ToadHouse) = {
    Call(RotateModel, MODEL_khm_doa, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_ToadHouse) = {
    Call(RotateGroup, MODEL_khm_yane, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_khm_sita, LVar0, 0, 0, -1)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_khm_sita, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_khm_sita, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_ToadHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_kh_naiso, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_kh_naiso, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_MerleHouse) = {
    Call(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_MerleHouse) = {
    Call(RotateGroup, MODEL_km_yane, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_km_sita, LVar0, 0, 0, -1)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_HIDDEN)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_VISIBLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_MerleHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
            Call(EnableModel, MODEL_k_naiso, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            IfLt(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
                Call(DisablePlayerInput, TRUE)
            EndIf
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
            IfLt(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
                ExecWait(N(EVS_Scene_Merle_OneLastThing))
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_CookHouse) = {
    Call(RotateModel, MODEL_o122, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_CookHouse) = {
    Call(RotateGroup, MODEL_hm_yane, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_hm_sita, LVar0, 0, 0, -1)
    IfGt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_hm_sita, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_hm_yane, MODEL_GROUP_HIDDEN)
        Call(EnableModel, MODEL_h_yuki1, FALSE)
        Call(EnableModel, MODEL_h_yuki2, FALSE)
        Call(EnableModel, MODEL_hm_entotu, FALSE)
        Call(EnableModel, MODEL_hm_ento2, FALSE)
    EndIf
    IfLt(LVar0, 89)
        Call(SetGroupVisibility, MODEL_hm_sita, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_hm_yane, MODEL_GROUP_VISIBLE)
        Call(EnableModel, MODEL_h_yuki1, TRUE)
        Call(EnableModel, MODEL_h_yuki2, TRUE)
        Call(EnableModel, MODEL_hm_entotu, TRUE)
        Call(EnableModel, MODEL_hm_ento2, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_RoomListener_CookHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Set(AF_SAM_Snowing, FALSE)
            Call(SetGroupVisibility, MODEL_h_naiso, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Set(AF_SAM_Snowing, TRUE)
            Call(SetGroupVisibility, MODEL_h_naiso, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_ToadHouse)[] = {
    NPC_ShiverToad_04,
    -1
};

s32 N(InteriorNPCs_MerleHouse)[] = {
    NPC_Merle,
    -1
};

s32 N(InteriorNPCs_CookHouse)[] = {
    NPC_Ninji_04,
    NPC_StarKid_04,
    NPC_StarKid_05,
    NPC_StarKid_06,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // toad house
    Call(SetGroupVisibility, MODEL_kh_naiso, MODEL_GROUP_HIDDEN)
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_ToadHouse)),
        Ref(N(EVS_SetWallRot_ToadHouse)),
        NULL,
        Ref(N(EVS_RoomListener_ToadHouse)),
        COLLIDER_kh_d1,
        COLLIDER_kh_d2,
        MODEL_kinohuse,
        Ref(N(InteriorNPCs_ToadHouse)))
    // merle's house
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_MerleHouse)),
        Ref(N(EVS_SetWallRot_MerleHouse)),
        NULL,
        Ref(N(EVS_RoomListener_MerleHouse)),
        COLLIDER_k_d1,
        COLLIDER_k_d2,
        MODEL_k,
        Ref(N(InteriorNPCs_MerleHouse)))
    // cooking house
    Call(SetGroupVisibility, MODEL_h_naiso, MODEL_GROUP_HIDDEN)
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_CookHouse)),
        Ref(N(EVS_SetWallRot_CookHouse)),
        NULL,
        Ref(N(EVS_RoomListener_CookHouse)),
        COLLIDER_h_doa1,
        COLLIDER_h_doa2,
        MODEL_hakun,
        Ref(N(InteriorNPCs_CookHouse)))
    Return
    End
};
