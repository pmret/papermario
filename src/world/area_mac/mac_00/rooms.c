#include "mac_00.h"

EvtScript N(EVS_SetDoorRot_RussHouse) = {
    Call(RotateModel, MODEL_o210, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_RussHouse) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-2.0))
    Call(RotateModel, MODEL_o201, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o467, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o466, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-1.11))
    Call(RotateModel, MODEL_o194, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o463, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o469, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o335, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-0.328125))
    Call(RotateModel, MODEL_o198, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o460, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o461, LVar1, 0, 1, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.218))
    Call(RotateModel, MODEL_o213, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o215, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_RussHouse) = {
    Call(RotateModel, MODEL_o210, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_RussHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_VISIBLE)
            Set(MF_MusicMixTrigger1, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_intel_inn, MODEL_GROUP_HIDDEN)
            Set(MF_MusicMixTrigger1, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Shop) = {
    Call(RotateModel, MODEL_o121, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Shop) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_o370, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o371, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o373, LVar1, 1, 0, 0)
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_o396, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o397, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o155, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o146, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_o398, LVar1, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_Shop) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_shop_in, MODEL_GROUP_VISIBLE)
            Call(EnableModel, MODEL_o375, FALSE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_shop_in, MODEL_GROUP_HIDDEN)
            Call(EnableModel, MODEL_o375, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Dojo) = {
    Call(RotateModel, MODEL_o168, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Dojo) = {
    Set(LVar1, LVar0)
    MulF(LVar1, Float(2.0))
    Call(RotateModel, MODEL_o159, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o169, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o164, LVar1, 0, 1, 0)
    Call(RotateModel, MODEL_o162, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_Dojo) = {
    Call(RotateModel, MODEL_o168, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_Dojo) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_minka_inn, MODEL_GROUP_VISIBLE)
            Set(MF_MusicMixTrigger2, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_minka_inn, MODEL_GROUP_HIDDEN)
            Call(EnableMusicProximityMix, 0)
            Set(MF_MusicMixTrigger2, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Waterfront) = {
    Call(RotateModel, MODEL_o228, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Waterfront) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_o437, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o453, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o454, LVar1, 1, 0, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-0.671875))
    Call(RotateModel, MODEL_o242, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o239, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o243, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o245, LVar1, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_Waterfront) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Switch(GB_StoryProgress)
                CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_BEGAN_PEACH_MISSION)
                    Exec(N(EVS_WaterfrontHouse_DoorLocked))
                    Set(LVar0, -1)
                CaseDefault
                    Call(SetGroupVisibility, MODEL_minka2_inn, MODEL_GROUP_VISIBLE)
            EndSwitch
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_minka2_inn, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_RussHouse)[] = {
    NPC_RussT,
    -1
};

s32 N(InteriorNPCs_Shop)[] = {
    NPC_Toad_01,
    NPC_ShyGuy_02,
    NPC_HarryT,
    -1
};

s32 N(InteriorNPCs_Dojo)[] = {
    NPC_TheMaster,
    NPC_Chan,
    NPC_Lee,
    -1
};

s32 N(InteriorNPCs_WaterfrontHouse)[] = {
    NPC_Waterfront_Dad,
    NPC_Waterfront_Mom,
    NPC_Waterfront_Kid1,
    NPC_Waterfront_Kid2,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // RussT's house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_RussHouse)),
        Ref(N(EVS_SetWallRot_RussHouse)),
        Ref(N(EVS_DropDoor_RussHouse)),
        Ref(N(EVS_RoomListener_RussHouse)),
        COLLIDER_deilit3,
        COLLIDER_deilit3u,
        MODEL_intel_house,
        Ref(N(InteriorNPCs_RussHouse)))
    // harry's shop
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_1, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Shop)),
        Ref(N(EVS_SetWallRot_Shop)),
        NULL,
        Ref(N(EVS_RoomListener_Shop)),
        COLLIDER_deilit5, COLLIDER_deilit5u, MODEL_omise, Ref(N(InteriorNPCs_Shop)))
    // the dojo
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Dojo)),
        Ref(N(EVS_SetWallRot_Dojo)),
        Ref(N(EVS_DropDoor_Dojo)),
        Ref(N(EVS_RoomListener_Dojo)),
        COLLIDER_deilit6,
        COLLIDER_deilit6u,
        MODEL_minka_1,
        Ref(N(InteriorNPCs_Dojo)))
    // the waterfront house
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Waterfront)),
        Ref(N(EVS_SetWallRot_Waterfront)),
        NULL,
        Ref(N(EVS_RoomListener_Waterfront)),
        COLLIDER_deilit4,
        COLLIDER_deilit4u,
        MODEL_minka2,
        Ref(N(InteriorNPCs_WaterfrontHouse)))
    // initial visibility
    Set(LVar0, VIS_GROUP_3)
    Exec(N(EVS_RoomListener_RussHouse))
    Exec(N(EVS_RoomListener_Waterfront))
    Exec(N(EVS_RoomListener_Shop))
    Exec(N(EVS_RoomListener_Dojo))
    Return
    End
};
