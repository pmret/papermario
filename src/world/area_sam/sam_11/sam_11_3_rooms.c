#include "sam_11.h"

EvtScript N(D_80243330_D3D900) = {
    EVT_CALL(RotateModel, MODEL_o541, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243360_D3D930) = {
    EVT_CALL(RotateGroup, MODEL_g_ue, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_g_sita, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_g_ue, 0)
        EVT_CALL(SetGroupEnabled, MODEL_g_sita, 0)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_g_ue, 1)
        EVT_CALL(SetGroupEnabled, MODEL_g_sita, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243430_D3DA00) = {
    EVT_CALL(RotateModel, MODEL_o541, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243490_D3DA60) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupEnabled, MODEL_g_naiso, 1)
            EVT_IF_LT(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_ELSE
                EVT_CALL(EnableModel, MODEL_ana, FALSE)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
                EVT_IF_EQ(GF_SAM11_LeftHerringwaysHouse, FALSE)
                    EVT_THREAD
                        EVT_WAIT(30)
                        EVT_CALL(MakeLerp, 0, 255, 20, EASING_LINEAR)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_CALL(func_802CFD30, 2, 7, LVar0, 0, 0, 0)
                            EVT_WAIT(1)
                            EVT_IF_EQ(LVar1, 0)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_WAIT(10)
                        EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Walk)
                        EVT_CALL(PlayerFaceNpc, NPC_Herringway, FALSE)
                        EVT_CALL(NpcMoveTo, NPC_Herringway, -500, 0, 50)
                        EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_GRAVITY, FALSE)
                        EVT_CALL(SetNpcPos, NPC_Herringway, 0, -1000, 0)
                    EVT_END_THREAD
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupEnabled, MODEL_g_naiso, 0)
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

EvtScript N(D_80243714_D3DCE4) = {
    EVT_CALL(RotateModel, MODEL_o540, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243744_D3DD14) = {
    EVT_CALL(RotateGroup, MODEL_s_ue, LVar0, 1, 0, 0)
    EVT_CALL(RotateGroup, MODEL_s_sita, LVar0, 1, 0, 0)
    EVT_IF_GT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_s_ue, 0)
        EVT_CALL(SetGroupEnabled, MODEL_s_sita, 0)
    EVT_END_IF
    EVT_IF_LT(LVar0, 89)
        EVT_CALL(SetGroupEnabled, MODEL_s_ue, 1)
        EVT_CALL(SetGroupEnabled, MODEL_s_sita, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243814_D3DDE4) = {
    EVT_CALL(RotateModel, MODEL_o540, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(D_80243844_D3DE14)[] = {
    ITEM_WAREHOUSE_KEY,
    ITEM_NONE
};

EvtScript N(D_8024384C_D3DE1C) = {
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
    EVT_CALL(N(GetEntityPosition), MV_Unk_06, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_269, 0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_Unk_06)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802439A0_D3DF70) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(AF_SAM_Snowing, FALSE)
            EVT_CALL(SetGroupEnabled, MODEL_s_naiso, 1)
        EVT_CASE_EQ(3)
            EVT_SET(AF_SAM_Snowing, TRUE)
            EVT_CALL(SetGroupEnabled, MODEL_s_naiso, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80243A24_D3DFF4)[] = {
    NPC_Herringway,
    NPC_0B,
    -1
};

s32 N(D_80243A30_D3E000)[] = {
    NPC_Herringway,
    -1
};

EvtScript N(D_80243A38_D3E008) = {
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80243714_D3DCE4)), EVT_PTR(N(D_80243744_D3DD14)), EVT_PTR(N(D_80243814_D3DDE4)), EVT_PTR(N(D_802439A0_D3DF70)), COLLIDER_o540, COLLIDER_o591, MODEL_sou, EVT_PTR(N(D_80243A30_D3E000)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80243A78) = {
    EVT_CALL(SetGroupEnabled, MODEL_g_naiso, 0)
    EVT_CALL(EnableModel, MODEL_gn_dan1, TRUE)
    EVT_CALL(MakeDoorAdvanced, 2, EVT_PTR(N(D_80243330_D3D900)), EVT_PTR(N(D_80243360_D3D930)), EVT_PTR(N(D_80243430_D3DA00)), EVT_PTR(N(D_80243490_D3DA60)), COLLIDER_o541, COLLIDER_o590, MODEL_gon, EVT_PTR(N(D_80243A24_D3DFF4)))
    EVT_CALL(SetGroupEnabled, MODEL_s_naiso, 0)
    EVT_IF_EQ(GF_SAM11_UnlockedDoor, TRUE)
        EVT_EXEC_WAIT(N(D_80243A38_D3E008))
    EVT_ELSE
        EVT_BIND_PADLOCK(EVT_PTR(N(D_8024384C_D3DE1C)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(D_80243844_D3DE14)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243B40_D3E110) = {
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_80243814_D3DDE4))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_80243744_D3DD14))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_80243714_D3DCE4))
    EVT_SET(LVar0, 3)
    EVT_EXEC_WAIT(N(D_802439A0_D3DF70))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243BC0_D3E190) = {
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_802439A0_D3DF70))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_80243714_D3DCE4))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(D_80243744_D3DD14))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(D_80243814_D3DDE4))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243C40_D3E210) = {
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_80243490_D3DA60))
    EVT_SET(LVar0, 0)
    EVT_EXEC_WAIT(N(D_80243330_D3D900))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(D_80243360_D3D930))
    EVT_SET(LVar0, 90)
    EVT_EXEC_WAIT(N(D_80243430_D3DA00))
    EVT_RETURN
    EVT_END
};
