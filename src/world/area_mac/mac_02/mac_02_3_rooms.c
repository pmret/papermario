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
    EVT_CALL(RotateModel, MODEL_c_door, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_TayceT) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_ck1, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ck2, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_ck3, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_cy1, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_cy2, LVar1, -1, 0, 0)
    EVT_CALL(RotateModel, MODEL_cy3, LVar1, -1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_TayceT) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_cook_in, MODEL_GROUP_VISIBLE)
            EVT_SET(MF_MusicMixTrigger1, TRUE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_cook_in, MODEL_GROUP_HIDDEN)
            EVT_SET(MF_MusicMixTrigger1, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_BlueHouse) = {
    EVT_CALL(RotateModel, MODEL_sk_door, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_BlueHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_sk1, LVar1, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_sk2, LVar1, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_BlueHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_IF_EQ(GF_MAC02_UnlockedHouse, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_LockedFromInside, 160, 40)
                EVT_SET(LVar0, -1)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetGroupVisibility, MODEL_souko_in, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_IF_EQ(GF_MAC02_UnlockedHouse, FALSE)
                EVT_SET(LVar0, -1)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_souko_in, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_TayceT)),
        EVT_PTR(N(EVS_SetWallRot_TayceT)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_TayceT)),
        COLLIDER_deilit1u,
        COLLIDER_deilit1,
        MODEL_cooking,
        EVT_PTR(N(InsideNPCs_TayceT)))
    // blue house on the left
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_BlueHouse)),
        EVT_PTR(N(EVS_SetWallRot_BlueHouse)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_BlueHouse)),
        COLLIDER_deilit2,
        COLLIDER_deilit2u,
        MODEL_souko,
        EVT_PTR(N(InsideNPCs_BlueHouse)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_02_ENTRY_5)
        EVT_SET(LVar0, 3)
        EVT_EXEC(N(EVS_RoomListener_TayceT))
        EVT_CALL(SetGroupVisibility, MODEL_souko_in, MODEL_GROUP_VISIBLE)
        EVT_CALL(N(InitEntryFromTunnels))
        EVT_SET(LVar0, 90)
        EVT_CALL(RotateModel, MODEL_sk1, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_sk2, LVar0, 0, 0, 1)
    EVT_ELSE
        EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
        EVT_EXEC(N(EVS_RoomListener_TayceT))
        EVT_EXEC(N(EVS_RoomListener_BlueHouse))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
