#include "jan_02.h"
#include "sprite/player.h"

#include "world/common/npc/Yoshi.inc.c"
#include "world/common/npc/Yoshi_Patrol.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#define QUIZMO_PRE_STATIC_PAD
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_GetRescuedYoshiCount) = {
    EVT_SET(LVar0, 0)
    EVT_ADD(LVar0, GF_JAN05_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN07_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN08_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN10_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN11_SavedYoshi)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_GetJadeRaven) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_IF_EQ(GF_JAN02_Met_VillageLeader, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0023)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0024)
    EVT_END_IF
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Walk)
    EVT_CALL(NpcMoveTo, NPC_SELF, 8, -140, 25)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
    EVT_WAIT(5 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 25, 15, -150)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 25, 15, -150)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(5 * DT)
    EVT_CALL(PlayerMoveTo, 58, -140, 25)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(func_802D2C14, 1)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Rummage)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Rummage, ANIM_VillageLeader_Rummage, 5, MSG_CH5_0025)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0026)
    EVT_GIVE_KEY_REWARD(ITEM_JADE_RAVEN)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_0027)
    EVT_SET(GB_StoryProgress, STORY_CH5_GOT_JADE_RAVEN)
    EVT_WAIT(15 * DT)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, 25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(func_802D2C14, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_SUSHIE)
        EVT_THREAD
            EVT_WAIT(15 * DT)
            EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EVT_END_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 2, MSG_CH5_0028)
    EVT_ELSE
        EVT_CALL(N(SwitchToPartner), PARTNER_SUSHIE)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, -1, -1, 5, MSG_CH5_0029)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_WAIT(15 * DT)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
        EVT_CALL(MakeLerp, LVar2, 85, 10 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_WAIT(10 * DT)
        EVT_THREAD
            EVT_WAIT(10 * DT)
            EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EVT_END_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 5, MSG_CH5_002A)
        EVT_WAIT(10 * DT)
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 5, MSG_CH5_002B)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 5, MSG_CH5_002C)
    EVT_WAIT(10 * DT)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_VillageLeader) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_IF_EQ(GF_JAN02_Met_VillageLeader, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0021)
                EVT_SET(GF_JAN02_Met_VillageLeader, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0022)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        EVT_CASE_LT(STORY_CH5_GOT_JADE_RAVEN)
            EVT_EXEC_WAIT(N(EVS_Scene_GetJadeRaven))
        EVT_CASE_LT(STORY_CH5_RAPHAEL_LEFT_NEST)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Talk, ANIM_VillageLeader_Idle, 0, MSG_CH5_002D)
        EVT_CASE_LT(STORY_CH5_ZIP_LINE_READY)
            EVT_IF_EQ(AF_JAN02_RaphaelComment, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_002E)
                EVT_SET(AF_JAN02_RaphaelComment, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_002F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0030)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0031)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0032)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_TalkSit, ANIM_VillageLeader_IdleSit, 0, MSG_CH5_0033)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_VillageLeader) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_IdleSit)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_VillageLeader)))
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH5_GOT_JADE_RAVEN)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 15, -50)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_VillageLeader)))
        EVT_CASE_LT(STORY_CH5_RAPHAEL_LEFT_NEST)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Idle)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, 30, 15, -30)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_VillageLeader)))
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_VillageLeader)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Councillor) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_IF_EQ(AF_JAN02_MetCouncillor, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0034)
                EVT_CALL(EndSpeech, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0)
                EVT_SET(AF_JAN02_MetCouncillor, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0035)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSitSad, ANIM_LeadersFriend_BowSit, 0, MSG_CH5_0036)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSitSad, ANIM_LeadersFriend_BowSit, 0, MSG_CH5_0037)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_GOT_JADE_RAVEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0038)
        EVT_CASE_LT(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_0039)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_003A)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_003B)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LeadersFriend_TalkSit, ANIM_LeadersFriend_IdleSit, 0, MSG_CH5_003C)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Councillor) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LeadersFriend_IdleSit)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 40, 32)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LeadersFriend_BowSit)
        EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Councillor)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_003D)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_EXEC_WAIT(N(EVS_GetRescuedYoshiCount))
            EVT_IF_EQ(LVar0, 0)
                EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_CryTalk, ANIM_Yoshi_Red_Cry, 0, MSG_CH5_003E)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_CryTalk, ANIM_Yoshi_Red_Cry, 0, MSG_CH5_003F)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_JAN08_SavedYoshi, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_CryTalk, ANIM_Yoshi_Red_Cry, 0, MSG_CH5_0040)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0041)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LE(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0042)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0043)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0044)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Red_Talk, ANIM_Yoshi_Red_Idle, 0, MSG_CH5_0045)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Yoshi_01) = {
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -520, -270, 50)
        EVT_CALL(NpcMoveTo, NPC_SELF, -420, -270, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_IF_EQ(GF_JAN08_SavedYoshi, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Red_Panic)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Yoshi_01)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_0046)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_EXEC_WAIT(N(EVS_GetRescuedYoshiCount))
            EVT_IF_EQ(LVar0, 0)
                EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_CryTalk, ANIM_Yoshi_Blue_Cry, 0, MSG_CH5_0047)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_CryTalk, ANIM_Yoshi_Blue_Cry, 0, MSG_CH5_0048)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_JAN10_SavedYoshi, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_CryTalk, ANIM_Yoshi_Blue_Cry, 0, MSG_CH5_0049)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004A)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LE(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004B)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004C)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004D)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Blue_Talk, ANIM_Yoshi_Blue_Idle, 0, MSG_CH5_004E)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Yoshi_02) = {
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 180, -520, 50)
        EVT_CALL(NpcMoveTo, NPC_SELF, 80, -520, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_IF_EQ(GF_JAN10_SavedYoshi, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Blue_Panic)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Yoshi_02)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Yoshi_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_004F)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_EXEC_WAIT(N(EVS_GetRescuedYoshiCount))
            EVT_IF_EQ(LVar0, 0)
                EVT_IF_EQ(GF_JAN03_AgreedToRescueChildren, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_CryTalk, ANIM_Yoshi_Purple_Cry, 0, MSG_CH5_0050)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_CryTalk, ANIM_Yoshi_Purple_Cry, 0, MSG_CH5_0051)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_JAN05_SavedYoshi, FALSE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_CryTalk, ANIM_Yoshi_Purple_Cry, 0, MSG_CH5_0052)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0053)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LE(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0054)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0055)
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0056)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Purple_Talk, ANIM_Yoshi_Purple_Idle, 0, MSG_CH5_0057)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Yoshi_03) = {
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 600, -150, 50)
        EVT_CALL(NpcMoveTo, NPC_SELF, 500, -150, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Yoshi_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_IF_EQ(GF_JAN05_SavedYoshi, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Purple_Panic)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Yoshi_03)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Yoshi_03)))
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Councillor)[] = {
    ANIM_LeadersFriend_TalkSit,
    ANIM_LeadersFriend_TalkSitSad,
    ANIM_LeadersFriend_IdleSit,
    ANIM_LeadersFriend_BowSit,
    ANIM_LIST_END
};

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_YoshiLeader,
        .pos = { 323.0f, 30.0f, 412.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_VillageLeader),
        .settings = &N(NpcSettings_Yoshi),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = YOSHI_LEADER_ANIMS,
        .tattle = MSG_NpcTattle_VillageLeader,
    },
    {
        .id = NPC_YoshiCouncillor,
        .pos = { 172.0f, 30.0f, 418.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Councillor),
        .settings = &N(NpcSettings_Yoshi),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = YOSHI_COUNCILLOR_ANIMS,
        .extraAnimations = N(ExtraAnims_Councillor),
        .tattle = MSG_NpcTattle_LeadersFriend,
    },
    {
        .id = NPC_Yoshi_01,
        .pos = { -520.0f, 0.0f, -270.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -520, 0, -270 },
                    { -420, 0, -270 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -520, 0, -270 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_01),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_RED_ANIMS,
        .tattle = MSG_NpcTattle_EntranceYoshi,
    },
    {
        .id = NPC_Yoshi_02,
        .pos = { 180.0f, 0.0f, -520.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { 180, 0, -520 },
                    { 10, 0, -520 },
                    { 100, 0, -600 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 5, 0, -554 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_02),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_BlueYoshi,
    },
    {
        .id = NPC_Yoshi_03,
        .pos = { 600.0f, 0.0f, -150.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 600, 0, -150 },
                    { 485, 0, -220 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 600, 0, -150 },
                .detectSize = { 100 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_03),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_LikeableYoshi,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { -150.0f, 15.0f, 300.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_JAN, QUIZ_COUNT_JAN, QUIZ_MAP_JAN_02 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};
