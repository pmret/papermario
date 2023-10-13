#include "sam_11.h"

EvtScript N(EVS_SetDoorRot_LeftHouse) = {
    EVT_CALL(RotateModel, MODEL_o541, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_LeftHouse) = {
    EVT_CALL(RotateGroup, MODEL_g_ue, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_g_sita, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_g_ue, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_g_ue, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_g_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_LeftHouse) = {
    EVT_CALL(RotateModel, MODEL_o541, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_LeftHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_g_naiso, MODEL_GROUP_VISIBLE)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_ELSE
                EVT_CALL(EnableModel, MODEL_ana, FALSE)
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
                EVT_IF_EQ(GF_SAM11_LeftHerringwaysHouse, FALSE)
                    EVT_THREAD
                        EVT_WAIT(30 * DT)
                        EVT_CALL(MakeLerp, 0, 255, 20, EASING_LINEAR)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_CALL(SetNpcImgFXParams, NPC_Herringway, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                            EVT_WAIT(1)
                            EVT_IF_EQ(LVar1, 0)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_WAIT(10 * DT)
                        EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Walk)
                        EVT_CALL(PlayerFaceNpc, NPC_Herringway, FALSE)
                        EVT_CALL(NpcMoveTo, NPC_Herringway, -500, 0, 50 * DT)
                        EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_GRAVITY, FALSE)
                        EVT_CALL(SetNpcPos, NPC_Herringway, NPC_DISPOSE_LOCATION)
                    EVT_END_THREAD
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_g_naiso, MODEL_GROUP_HIDDEN)
            EVT_CALL(EnableModel, MODEL_gn_dan1, TRUE)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
                EVT_IF_EQ(GF_SAM11_LeftHerringwaysHouse, FALSE)
                    EVT_THREAD
                    EVT_END_THREAD
                    EVT_SET(GF_SAM11_LeftHerringwaysHouse, TRUE)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_RightHouse) = {
    EVT_CALL(RotateModel, MODEL_o540, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_RightHouse) = {
    EVT_CALL(RotateGroup, MODEL_s_ue, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_s_sita, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_s_ue, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_s_sita, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupVisibility, MODEL_s_ue, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_s_sita, MODEL_GROUP_VISIBLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_RightHouse) = {
    EVT_CALL(RotateModel, MODEL_o540, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};


s32 N(KeyList)[] = {
    ITEM_WAREHOUSE_KEY,
    ITEM_NONE
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockPrompt_LeftHouse) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_SAM11_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_PadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_RightHouse) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupVisibility, MODEL_s_naiso, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(3)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupVisibility, MODEL_s_naiso, MODEL_GROUP_HIDDEN)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(InteriorNPCs_LeftHouse)[] = {
    NPC_Herringway,
    NPC_0B,
    -1
};

s32 N(InteriorNPCs_RightHouse)[] = {
    NPC_Herringway,
    -1
};

EvtScript N(EVS_SetupLockedHouse) = {
    // lower right house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_RightHouse)),
        EVT_PTR(N(EVS_SetWallRot_RightHouse)),
        EVT_PTR(N(EVS_DropDoor_RightHouse)),
        EVT_PTR(N(EVS_RoomListener_RightHouse)),
        COLLIDER_o540,
        COLLIDER_o591,
        MODEL_sou,
        EVT_PTR(N(InteriorNPCs_RightHouse)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(SetGroupVisibility, MODEL_g_naiso, MODEL_GROUP_HIDDEN)
    EVT_CALL(EnableModel, MODEL_gn_dan1, TRUE)
    // lower left house
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_LeftHouse)),
        EVT_PTR(N(EVS_SetWallRot_LeftHouse)),
        EVT_PTR(N(EVS_DropDoor_LeftHouse)),
        EVT_PTR(N(EVS_RoomListener_LeftHouse)),
        COLLIDER_o541,
        COLLIDER_o590,
        MODEL_gon,
        EVT_PTR(N(InteriorNPCs_LeftHouse)))
    EVT_CALL(SetGroupVisibility, MODEL_s_naiso, MODEL_GROUP_HIDDEN)
    EVT_IF_EQ(GF_SAM11_UnlockedDoor, TRUE)
        EVT_EXEC_WAIT(N(EVS_SetupLockedHouse))
    EVT_ELSE
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_LeftHouse)), TRIGGER_WALL_PRESS_A,
            EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HideRightHouse) = {
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(EVS_DropDoor_RightHouse))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(EVS_SetWallRot_RightHouse))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(EVS_SetDoorRot_RightHouse))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC_WAIT(N(EVS_RoomListener_RightHouse))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RevealRightHouse) = {
    EVT_SET(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    EVT_EXEC_WAIT(N(EVS_RoomListener_RightHouse))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(EVS_SetDoorRot_RightHouse))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(EVS_SetWallRot_RightHouse))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(EVS_DropDoor_RightHouse))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RevealLeftHouse) = {
    EVT_SET(LVar0, ROOM_UPDATE_ENTER_BEGIN)
    EVT_EXEC_WAIT(N(EVS_RoomListener_LeftHouse))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(EVS_SetDoorRot_LeftHouse))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(EVS_SetWallRot_LeftHouse))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(EVS_DropDoor_LeftHouse))
    EVT_RETURN
    EVT_END
};
