#include "flo_12.h"
#include "sprite/player.h"

#include "world/common/npc/Rosie.inc.c"
#include "world/common/npc/Dummy.inc.c"

#include "common/foliage.inc.c"

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"

s32 N(KeyList)[] = {
    ITEM_CRYSTAL_BERRY,
    ITEM_NONE
};

EvtScript N(EVS_Scene_SunReturns) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetNpcPos, NPC_Rosie, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-9.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Rosie, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_00C7)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_03"), flo_03_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayerApproachRosie) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(PlayerMoveTo, -5, 20, 20)
    EVT_CALL(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(PlayerFaceNpc, NPC_Rosie, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayerApproachRosieAndItem) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(PlayerMoveTo, -5, 20, 20)
    EVT_CALL(SetNpcFlagBits, NPC_Rosie, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(PlayerFaceNpc, NPC_Rosie, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rosie) = {
    EVT_EXEC_WAIT(N(EVS_PushFlowerSong))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_CRYSTAL_BERRY)
            EVT_SWITCH(GF_FLO12_Met_Rosie)
                EVT_CASE_EQ(0)
                    EVT_EXEC(N(EVS_PlayerApproachRosie))
                    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), LVar0, LVar1, LVar2, 325, EVT_FLOAT(19.0), EVT_FLOAT(-9.5))
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_Talk, ANIM_Rosie_Idle, 5, MSG_CH6_008C)
                    EVT_CALL(ShowChoice, MSG_Choice_0011)
                    EVT_WAIT(10)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(0)
                            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Rosie_Talk, ANIM_Rosie_Idle, 5, MSG_CH6_008D)
                        EVT_CASE_EQ(1)
                            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Rosie_Talk, ANIM_Rosie_Idle, 5, MSG_CH6_008E)
                    EVT_END_SWITCH
                    EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rosie_TakeOut)
                    EVT_WAIT(10)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
                    EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
                    EVT_WAIT(10)
                    EVT_SWITCH(GF_FLO10_LilyRequestedWaterStone)
                        EVT_CASE_EQ(0)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_008F)
                        EVT_CASE_EQ(1)
                            EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_CarryRun)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_008F)
                            EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0091)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Pray)
                            EVT_WAIT(40)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0092)
                            EVT_SET(GF_FLO12_RosieRequestedSomethingBeautiful, TRUE)
                    EVT_END_SWITCH
                    EVT_SET(GF_FLO12_Met_Rosie, TRUE)
                EVT_CASE_EQ(1)
                    EVT_SWITCH(GF_FLO12_RosieRequestedSomethingBeautiful)
                        EVT_CASE_EQ(0)
                            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, TRUE)
                                EVT_EXEC(N(EVS_PlayerApproachRosieAndItem))
                                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_0090)
                                EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
                                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0091)
                                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Pray)
                                EVT_WAIT(40)
                                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0092)
                                EVT_SET(GF_FLO12_RosieRequestedSomethingBeautiful, TRUE)
                            EVT_ELSE
                                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_TalkHold, 5, MSG_CH6_0090)
                            EVT_END_IF
                        EVT_CASE_EQ(1)
                            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0093)
                    EVT_END_SWITCH
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH6_GOT_WATER_STONE)
            EVT_CALL(FindKeyItem, ITEM_CRYSTAL_BERRY, LVar0)
            EVT_IF_NE(LVar0, -1)
                EVT_EXEC(N(EVS_PlayerApproachRosieAndItem))
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 30)
                EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), LVar0, LVar1, LVar2, 325, EVT_FLOAT(19.0), EVT_FLOAT(-9.5))
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0094)
            EVT_CHOOSE_KEY_ITEM_FROM(N(KeyList))
            EVT_SWITCH(LVar0)
                EVT_CASE_LE(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0093)
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0095)
                    EVT_CALL(RemoveItemEntity, LVar7)
                    EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
                    EVT_GIVE_KEY_REWARD(ITEM_WATER_STONE)
                    EVT_WAIT(10)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0096)
                    EVT_SET(AF_FLO_GivenCrystalBerry, TRUE)
                    EVT_SET(GB_StoryProgress, STORY_CH6_GOT_WATER_STONE)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_SWITCH(AF_FLO_GivenCrystalBerry)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0097)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0096)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0098)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Rosie_TalkHold, ANIM_Rosie_IdleHold, 5, MSG_CH6_0099)
    EVT_END_SWITCH
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_EXEC_WAIT(N(EVS_PopMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Rosie) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rosie)))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 35)
    EVT_CALL(SetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_HAS_SHADOW, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_CRYSTAL_BERRY)
            EVT_IF_EQ(GF_FLO12_Met_Rosie, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
                EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
                EVT_SET(LVarA, LVar0)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_GOT_WATER_STONE)
            EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
            EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
            EVT_SET(LVarA, LVar0)
        EVT_CASE_DEFAULT
            EVT_CALL(SetNpcFlagBits, NPC_Dummy, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rosie_IdleHold)
            EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -33, 14, 19, ITEM_SPAWN_MODE_DECORATION, EVT_INDEX_OF_GAME_FLAG(GF_FLO12_HeldItemPickup))
            EVT_SET(LVarA, LVar0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Rosie)[] = {
    {
        .id = NPC_Rosie,
        .pos = { -70.0f, 0.0f, 20.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Rosie),
        .settings = &N(NpcSettings_Rosie),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ROSIE_ANIMS,
        .tattle = MSG_NpcTattle_Rosie,
    },
    {
        .id = NPC_Dummy,
        .pos = { -70.0f, 0.0f, 20.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = ROSIE_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Rosie)),
    {}
};
