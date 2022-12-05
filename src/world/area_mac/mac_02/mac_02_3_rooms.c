#include "mac_02.h"
#include "model.h"

API_CALLABLE(N(InitEntryFromTunnels)) {
    Npc* npc;
    s32 i;

    func_8011B950(MODEL_souko, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = get_npc_by_index(i);
        if (npc != NULL) {
            if (npc->flags != 0 && npc->npcID != NPC_PARTNER) {
                npc->flags |= NPC_FLAG_NO_DROPS;
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

EvtScript N(EVS_MoveWalls_TayceT) = {
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

EvtScript N(EVS_ToggleVis_TayceT) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_cook_in, 1)
            EVT_SET(MF_MusicMixTrigger1, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_cook_in, 0)
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

EvtScript N(EVS_MoveWalls_BlueHouse) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_sk1, LVar1, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_sk2, LVar1, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToggleVis_BlueHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(GF_MAC02_UnlockedHouse, FALSE)
                EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_LockedFromInside, 160, 40)
                EVT_SET(LVar0, -1)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetGroupEnabled, MODEL_souko_in, 1)
        EVT_CASE_EQ(2)
            EVT_IF_EQ(GF_MAC02_UnlockedHouse, FALSE)
                EVT_SET(LVar0, -1)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_souko_in, 0)
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
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_2),
        EVT_PTR(N(EVS_SetDoorRot_TayceT)),
        EVT_PTR(N(EVS_MoveWalls_TayceT)),
        NULL,
        EVT_PTR(N(EVS_ToggleVis_TayceT)),
        COLLIDER_deilit1u,
        COLLIDER_deilit1,
        MODEL_cooking,
        EVT_PTR(N(InsideNPCs_TayceT)))
    // blue house on the left
    EVT_CALL(MakeDoorAdvanced,
        VIS_GROUP_PAIR(VIS_GROUP_0, VIS_GROUP_2),
        EVT_PTR(N(EVS_SetDoorRot_BlueHouse)),
        EVT_PTR(N(EVS_MoveWalls_BlueHouse)),
        NULL,
        EVT_PTR(N(EVS_ToggleVis_BlueHouse)),
        COLLIDER_deilit2,
        COLLIDER_deilit2u,
        MODEL_souko,
        EVT_PTR(N(InsideNPCs_BlueHouse)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_02_ENTRY_5)
        EVT_SET(LVar0, 3)
        EVT_EXEC(N(EVS_ToggleVis_TayceT))
        EVT_CALL(SetGroupEnabled, MODEL_souko_in, 1)
        EVT_CALL(N(InitEntryFromTunnels))
        EVT_SET(LVar0, 90)
        EVT_CALL(RotateModel, MODEL_sk1, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_sk2, LVar0, 0, 0, 1)
    EVT_ELSE
        EVT_SET(LVar0, 3)
        EVT_EXEC(N(EVS_ToggleVis_TayceT))
        EVT_EXEC(N(EVS_ToggleVis_BlueHouse))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
