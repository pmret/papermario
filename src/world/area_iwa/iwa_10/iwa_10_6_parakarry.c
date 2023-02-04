#include "iwa_10.h"
#include "effects.h"

#include "world/common/npc/Parakarry.inc.c"

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(EVS_Scene_MeetParakarry) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, 215)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_LT(LVar0, -600)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH2_000E, 320, 150)
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
        EVT_CALL(PlaySoundAtPlayer, SOUND_263, SOUND_SPACE_MODE_0)
        EVT_CALL(ShowEmote, NPC_TrainToad_01, EMOTE_QUESTION, 0, 20, FALSE, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), 30, 300, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80022)
        EVT_WAIT(20)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(55)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(SetNpcPos, NPC_Parakarry, -400, 215, -510)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_40, TRUE)
    EVT_THREAD
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, 15)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
        EVT_WAIT(20)
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, 0)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
        EVT_WAIT(5)
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, -15)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, 0)
    EVT_END_THREAD
    EVT_SET(MV_ParakarryPosZ, -510)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(MakeLerp, -510, LVar2, 60, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_ParakarryPosZ, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_ADD(LVar0, 25)
    EVT_CALL(MakeLerp, -400, LVar0, 55, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_Parakarry, LVar0, 220, MV_ParakarryPosZ)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_FallBack)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_HurtStill)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_Parakarry, LVar3, LVar4, LVar5)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_ADD(LVar2, LVar5)
    EVT_DIV(LVar2, 2)
    EVT_CALL(PlaySoundAt, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_MODE_0, LVar0, 230, LVar2)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, 3, LVar0, 230, LVar2, 0, -1, 0, 2)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, 230)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar2, -380)
        EVT_SET(LVar2, -380)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Parakarry, EVT_FLOAT(1.0))
        EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar3)
        EVT_ADD(LVar0, 30)
        EVT_CALL(NpcJump1, NPC_Parakarry, LVar0, 215, LVar2, 15)
        EVT_ADD(LVar0, 15)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Hurt)
        EVT_CALL(NpcJump1, NPC_Parakarry, LVar0, 215, LVar2, 8)
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_SUB(LVar0, 30)
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 15)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_162, SOUND_SPACE_MODE_0, LVarA, LVarB, LVarC)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_SUB(LVar0, 15)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_DeadStill)
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 8)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Parakarry, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GetUp)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(NpcJump1, NPC_Parakarry, LVar0, LVar1, LVar2, 8)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(30)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), 35, 255, EVT_FLOAT(17.5), EVT_FLOAT(-11.5))
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetNpcSpeed, NPC_Parakarry, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Parakarry, LVar0, LVar2, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_000F)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Parakarry, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0010)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0011)
    EVT_SET(GB_StoryProgress, STORY_CH2_SPOKE_WITH_PARAKARRY)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(BindNpcAI, NPC_Parakarry, EVT_PTR(N(EVS_NpcIdle_Parakarry)))
    EVT_RETURN
    EVT_END
};

s32 N(LetterList)[] = {
    ITEM_LETTER01,
    ITEM_LETTER25,
    ITEM_LETTER10,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Parakarry) = {
    EVT_SET(LocalFlag(0), FALSE)
    EVT_IF_EQ(GB_IWA10_ReturnedLetterCount, 2)
        EVT_SET(LVar0, 0)
        EVT_IF_EQ(GF_IWA01_Item_Letter01, TRUE)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_IF_EQ(GF_IWA03_Item_Letter25, TRUE)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_IF_EQ(GF_IWA04_Item_Letter10, TRUE)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 3)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(GetNpcPos, NPC_Parakarry, LVar4, LVar5, LVar6)
            EVT_IF_LT(LVar1, LVar4)
                EVT_ADD(LVar4, -30)
            EVT_ELSE
                EVT_ADD(LVar4, 30)
            EVT_END_IF
            EVT_CALL(PlayerMoveTo, LVar4, LVar6, 20)
            EVT_CALL(PlayerFaceNpc, NPC_Parakarry, FALSE)
            EVT_WAIT(10)
            EVT_CALL(func_802CF56C, 2)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), EVT_FLOAT(0.0), EVT_FLOAT(300.0), EVT_FLOAT(17.5), EVT_FLOAT(-10.0))
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(LetterList)))
    EVT_SET(LVar1, 4)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SWITCH(GB_IWA10_ReturnedLetterCount)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0012)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0015)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0017)
                EVT_CASE_EQ(3)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001C)
                    EVT_CALL(ShowChoice, MSG_Choice_000F)
                    EVT_IF_NE(LVar0, 0)
                        EVT_CALL(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001B)
                        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
                        EVT_RETURN
                    EVT_END_IF
                    EVT_SET(LocalFlag(0), TRUE)
            EVT_END_SWITCH
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0013)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveKeyItemAt, LVar0)
            EVT_ADD(GB_IWA10_ReturnedLetterCount, 1)
            EVT_SWITCH(GB_IWA10_ReturnedLetterCount)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0014)
                EVT_CASE_EQ(2)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0016)
                EVT_CASE_EQ(3)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Celebrate, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0018)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Question)
                    EVT_WAIT(30)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
                    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0019)
                    EVT_CALL(ShowChoice, MSG_Choice_000F)
                    EVT_IF_NE(LVar0, 0)
                        EVT_CALL(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001A)
                        EVT_CALL(ShowChoice, MSG_Choice_000F)
                        EVT_IF_NE(LVar0, 0)
                            EVT_CALL(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001B)
                            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
                            EVT_RETURN
                        EVT_END_IF
                    EVT_END_IF
                    EVT_SET(LocalFlag(0), TRUE)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_IF_EQ(LocalFlag(0), TRUE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001D)
        EVT_CALL(N(ChangeNpcToPartner), 4, 4)
        EVT_SET(GB_StoryProgress, STORY_CH2_PARAKARRY_JOINED_PARTY)
        EVT_CALL(N(LoadPartyImage))
        EVT_EXEC(N(EVS_PushSong))
        EVT_WAIT(15)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018C, 160, 40)
        EVT_EXEC(N(EVS_PopSong))
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001E)
        EVT_CALL(AddKeyItem, ITEM_LETTER01)
        EVT_CALL(AddKeyItem, ITEM_LETTER25)
        EVT_CALL(AddKeyItem, ITEM_LETTER10)
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(EnablePartnerAI)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Parakarry) = {
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.0))
    EVT_ADD(LVar0, -670)
    EVT_ADD(LVar2, -485)
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(30)
        EVT_ADD(LVar0, 120)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldParakarry_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(30)
        EVT_ADD(LVar0, -120)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Parakarry) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Parakarry)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_SPOKE_WITH_PARAKARRY)
            EVT_CALL(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
        EVT_CASE_LT(STORY_CH2_PARAKARRY_JOINED_PARTY)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Parakarry)))
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Parakarry) = {
    .id = NPC_Parakarry,
    .settings = &N(NpcSettings_Parakarry),
    .pos = { -610.0f, 230.0f, -485.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_Parakarry),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = PARAKARRY_ANIMS,
    .tattle = MSG_NpcTattle_IWA_Parakarry,
};
