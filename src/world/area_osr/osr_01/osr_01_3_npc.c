
#include "osr_01.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

EvtScript N(EVS_Scene_Wishing) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 400)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 400)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(3.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_HOS_006F)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("mac_04"), mac_04_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(LetterList)[] = {
    ITEM_LETTER_CHAIN_MUSS_T,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Toad) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_OSR_0000)
        EVT_CASE_LT(STORY_CH1_SPOKE_WITH_MERLIN)
            EVT_SET(LVar0, MSG_OSR_0001)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_OSR_0002)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_OSR_0003)
            EVT_ELSE
                EVT_SET(LVar0, MSG_OSR_0004)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_OSR_0005)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_OSR_0006)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_OSR_0007)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_OSR_0008)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_OSR_0009)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_OSR_000A)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_OSR_000B)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_OSR_000C)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_OSR_000D)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_OSR_000E)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_OSR_000F)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar0)
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle,
        ITEM_LETTER_CHAIN_MUSS_T, ITEM_LETTER_CHAIN_KOOVER_1,
        MSG_OSR_0010, MSG_OSR_0011, MSG_OSR_0012, MSG_OSR_0013,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_IF_EQ(LVarC, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(osr_01_ENTRY_3)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 400)
            EVT_CALL(SetNpcYaw, NPC_SELF, 90)
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Toad) = {
    .id = NPC_Toad,
    .pos = { 25.0f, 0.0f, 130.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_OSR_LovesToClean,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad)),
    {}
};
