#include "arn_03.h"
#include "sprite/player.h"

#include "world/common/npc/Boo_Patrol.inc.c"
#include "world/common/npc/Boo.inc.c"

#include "world/common/complete/GiveReward.inc.c"
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/atomic/MarioSalute.inc.c"

EvtScript N(EVS_NpcInteract_Boo_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_02, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0073)
                EVT_SET(AF_ARN_02, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0074)
                EVT_SET(AF_ARN_02, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0075)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0076)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0077)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0078)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(20)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Boo_01) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(25 * DT)
    EVT_THREAD
        EVT_WAIT(50 * DT)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 325)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(GetCurrentPartnerID, LVar6)
        EVT_IF_NE(LVar6, PARTNER_BOW)
            EVT_CALL(BringPartnerOut, PARTNER_BOW)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            EVT_WAIT(5 * DT)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
            EVT_IF_EQ(LVar6, PARTNER_PARAKARRY)
                EVT_CALL(NpcJump0, NPC_PARTNER, -81, 176, 171, 20 * DT)
            EVT_ELSE
                EVT_CALL(NpcJump0, NPC_PARTNER, -81, 186, 171, 20 * DT)
            EVT_END_IF
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(NpcJump0, NPC_SELF, -8, 186, 159, 60 * DT)
    EVT_WAIT(15 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, -4, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_006E)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, -1, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 5, MSG_CH3_006F)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_0070)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, -1, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 5, MSG_CH3_0071)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_0072)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetCurrentPartnerID, LVar6)
    EVT_IF_NE(LVar6, PARTNER_BOW)
        EVT_CALL(PutPartnerAway)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_SELF, 30, 125, 30 * DT)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_END_THREAD
    EVT_CALL(func_802CF56C, 2)
    EVT_WAIT(15 * DT)
    EVT_SET(GB_StoryProgress, STORY_CH3_ARRIVED_AT_GHOST_TOWN)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_ARRIVED_AT_GHOST_TOWN)
        EVT_CALL(SetNpcPos, NPC_SELF, 175, 240, 145)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_01)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_02) = {
    EVT_IF_NE(MV_Unk_00, 0)
        EVT_IF_GE(MV_Unk_00, MV_Unk_01)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0081)
            EVT_SET(LVar0, 118)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(GiveItemReward))
            EVT_CALL(AddKeyItem, ITEM_KOOT_PACKAGE)
            EVT_SET(MV_Unk_00, 0)
            EVT_SET(GF_ARN03_RecievedPackage, TRUE)
            EVT_SET(GF_ARN03_WaitingForPackage, FALSE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0080)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_03, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0079)
                EVT_SET(AF_ARN_03, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007A)
                EVT_SET(AF_ARN_03, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007B)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007C)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007D)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007E)
    EVT_END_SWITCH
    EVT_IF_EQ(GF_ARN03_RecievedPackage, FALSE)
        EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH7_2)
            EVT_EXEC_WAIT(N(EVS_MarioSalute))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_007F)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0)
            EVT_SET(MV_Unk_00, 0)
            EVT_SET(MV_Unk_01, 450 * DT)
            EVT_SET(GF_ARN03_WaitingForPackage, TRUE)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_ADD(MV_Unk_00, 1)
                    EVT_WAIT(1)
                    EVT_IF_GE(MV_Unk_00, MV_Unk_01)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802428CC) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_ADD(LVar0, 60)
        EVT_CALL(SetNpcYaw, NPC_Boo_05, 90)
    EVT_ELSE
        EVT_SUB(LVar0, 60)
        EVT_CALL(SetNpcYaw, NPC_Boo_05, 270)
    EVT_END_IF
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetNpcPos, NPC_Boo_05, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802429D4) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_ADD(LVar0, 30)
    EVT_ELSE
        EVT_SUB(LVar0, 30)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 40, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Boo_05, LVar0, LVar2, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242B0C) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_ADD(LVar0, 60)
    EVT_ELSE
        EVT_SUB(LVar0, 60)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 255, 0, 40, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_Boo_05, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Boo_05, LVar0, LVar2, 40)
    EVT_CALL(SetNpcPos, NPC_Boo_05, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242C60) = {
    EVT_EXEC_WAIT(N(802429D4))
    EVT_SET(MV_Unk_02, 0)
    EVT_SET(MV_Unk_03, 0)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Flail)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Cower)
        EVT_LOOP(0)
            EVT_IF_EQ(MV_Unk_02, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Boo_Tan_Idle)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Spook)
    EVT_CALL(EndSpeech, NPC_Boo_05, ANIM_Boo_Tan_Spook, ANIM_Boo_Tan_Spook, 5)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Boo_05, ANIM_Boo_Tan_Idle)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(80242B0C))
    EVT_SET(MV_Unk_02, 1)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_04, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0082)
                EVT_SET(AF_ARN_04, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0083)
                EVT_SET(AF_ARN_04, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0084)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0085)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar2, -20)
                EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0))
                EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0086)
            EVT_EXEC_WAIT(N(802428CC))
            EVT_CALL(PlayerFaceNpc, NPC_Boo_05, TRUE)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Boo_05, 1)
            EVT_CALL(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_0087)
            EVT_EXEC_WAIT(N(80242C60))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0088)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar2, -20)
                EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0))
                EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 1)
            EVT_END_THREAD
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0089)
            EVT_EXEC_WAIT(N(802428CC))
            EVT_CALL(PlayerFaceNpc, NPC_Boo_05, TRUE)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Boo_05, 1)
            EVT_CALL(SpeakToPlayer, NPC_Boo_05, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 5, MSG_CH3_008A)
            EVT_EXEC_WAIT(N(80242C60))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008B)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(EnablePartnerAI)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Boo_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
            EVT_IF_EQ(AF_ARN_05, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008C)
                EVT_SET(AF_ARN_05, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008D)
                EVT_SET(AF_ARN_05, FALSE)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008E)
        EVT_CASE_LT(STORY_CH3_BEGAN_PEACH_MISSION)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_008F)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0090)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Tan_Talk, ANIM_Boo_Tan_Idle, 0, MSG_CH3_0091)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Boo_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_05) = {
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Boo_01) = {
    .id = NPC_Boo_01,
    .pos = { 36.0f, 185.0f, 140.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 36, 10, 185 },
                { 56, 10, 185 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 479, 215, 198 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_Boo_01),
    .settings = &N(NpcSettings_Boo_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_LovesBow,
};

NpcData N(NpcData_Boo_02) = {
    .id = NPC_Boo_02,
    .pos = { 209.0f, 185.0f, 217.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_02),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_BooA,
};

NpcData N(NpcData_Boo_03) = {
    .id = NPC_Boo_03,
    .pos = { 379.0f, 186.0f, 186.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 379, 10, 186 },
                { 399, 10, 186 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 479, 215, 198 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_Boo_03),
    .settings = &N(NpcSettings_Boo_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_BooB,
};

NpcData N(NpcData_Boo_04) = {
    .id = NPC_Boo_04,
    .pos = { 544.0f, 235.0f, 128.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_04),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
    .tattle = MSG_NpcTattle_ARN_BooC,
};

NpcData N(NpcData_Boo_05) = {
    .id = NPC_Boo_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Boo_05),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = NO_DROPS,
    .animations = GUSTY_BOO_ANIMS,
};

EvtScript N(EVS_NpcIdle_Boo_06) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -60)
    EVT_SET(LVar4, LVar0)
    EVT_ADD(LVar4, 60)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(0.1))
        EVT_ADDF(LVar6, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, LVar6)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
        EVT_CALL(RandInt, 5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(0.1))
        EVT_ADDF(LVar6, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, LVar6)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar4, LVar2, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_06) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_07) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_08) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo_09) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo_06)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Boo_06)[] = {
    {
        .id = NPC_Boo_06,
        .pos = { 36.0f, 277.0f, 140.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_06),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_07,
        .pos = { 180.0f, 285.0f, 182.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_07),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_08,
        .pos = { 349.0f, 286.0f, 152.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_08),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
    {
        .id = NPC_Boo_09,
        .pos = { 490.0f, 324.0f, 128.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Boo_09),
        .settings = &N(NpcSettings_Boo),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
    },
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_Boo_01)),
    NPC_GROUP(N(NpcData_Boo_02)),
    NPC_GROUP(N(NpcData_Boo_03)),
    NPC_GROUP(N(NpcData_Boo_04)),
    NPC_GROUP(N(NpcData_Boo_05)),
    NPC_GROUP(N(NpcData_Boo_06)),
    {}
};
