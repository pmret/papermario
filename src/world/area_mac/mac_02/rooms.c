#include "mac_02.h"
#include "model.h"

API_CALLABLE(N(InitEntryFromTunnels)) {
    Npc* npc;
    s32 i;

    mdl_group_set_custom_gfx(MODEL_souko, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
    mdl_set_shroud_tint_params(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = get_npc_by_index(i);
        if (npc != NULL) {
            if (npc->flags != 0 && npc->npcID != NPC_PARTNER) {
                npc->flags |= NPC_FLAG_HIDING;
            }
        }
    }

    return ApiStatus_DONE2;
}


EvtScript N(EVS_SetDoorRot_TayceT) = {
    Call(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_TayceT) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_ck1, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_ck2, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_ck3, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_cy1, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_cy2, LVar1, -1, 0, 0)
    Call(RotateModel, MODEL_cy3, LVar1, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_RoomListener_TayceT) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_cook_in, MODEL_GROUP_VISIBLE)
            Set(MF_MusicMixTrigger1, TRUE)
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_cook_in, MODEL_GROUP_HIDDEN)
            Set(MF_MusicMixTrigger1, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_BlueHouse) = {
    Call(RotateModel, MODEL_sk_door, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_BlueHouse) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_sk1, LVar1, 0, 0, 1)
    Call(RotateModel, MODEL_sk2, LVar1, 0, 0, 1)
    Return
    End
};

EvtScript N(EVS_RoomListener_BlueHouse) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            IfEq(GF_MAC02_UnlockedHouse, FALSE)
                Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_LockedFromInside, 160, 40)
                Set(LVar0, -1)
                Return
            EndIf
            Call(SetGroupVisibility, MODEL_souko_in, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            IfEq(GF_MAC02_UnlockedHouse, FALSE)
                Set(LVar0, -1)
                Return
            EndIf
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_souko_in, MODEL_GROUP_HIDDEN)
    EndSwitch
    Return
    End
};

s32 N(InsideNPCs_TayceT)[] = {
    NPC_TayceT,
    -1
};

s32 N(InsideNPCs_BlueHouse)[] = {
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // tayce T's house on the right
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_TayceT)),
        Ref(N(EVS_SetWallRot_TayceT)),
        NULL,
        Ref(N(EVS_RoomListener_TayceT)),
        COLLIDER_deilit1u,
        COLLIDER_deilit1,
        MODEL_cooking,
        Ref(N(InsideNPCs_TayceT)))
    // blue house on the left
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_BlueHouse)),
        Ref(N(EVS_SetWallRot_BlueHouse)),
        NULL,
        Ref(N(EVS_RoomListener_BlueHouse)),
        COLLIDER_deilit2,
        COLLIDER_deilit2u,
        MODEL_souko,
        Ref(N(InsideNPCs_BlueHouse)))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_02_ENTRY_5)
        Set(LVar0, 3)
        Exec(N(EVS_RoomListener_TayceT))
        Call(SetGroupVisibility, MODEL_souko_in, MODEL_GROUP_VISIBLE)
        Call(N(InitEntryFromTunnels))
        Set(LVar0, 90)
        Call(RotateModel, MODEL_sk1, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_sk2, LVar0, 0, 0, 1)
    Else
        Set(LVar0, ROOM_UPDATE_EXIT_END)
        Exec(N(EVS_RoomListener_TayceT))
        Exec(N(EVS_RoomListener_BlueHouse))
    EndIf
    Return
    End
};
