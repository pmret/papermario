#include "iwa_10.h"
#include "effects.h"
#include "sprite/player.h"

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
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), 30, 300, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LookAround)
        EVT_WAIT(20 * DT)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(55 * DT)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcPos, NPC_Parakarry, -400, 215, -510)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_THREAD
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, 15)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, 0)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, -15)
        EVT_WAIT(30 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
        EVT_CALL(SetNpcRotation, NPC_Parakarry, 0, 0, 0)
    EVT_END_THREAD
    EVT_SET(MV_ParakarryPosZ, -510)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(MakeLerp, -510, LVar2, 60 * DT, EASING_LINEAR)
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
    EVT_CALL(MakeLerp, -400, LVar0, 55 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_Parakarry, LVar0, 220, MV_ParakarryPosZ)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Hurt)
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
    EVT_CALL(PlaySoundAt, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT, LVar0, 230, LVar2)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, LVar0, 230, LVar2, 0, -1, 0, 2)
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
        EVT_CALL(NpcJump1, NPC_Parakarry, LVar0, 215, LVar2, 15 * DT)
        EVT_ADD(LVar0, 15)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Hurt)
        EVT_CALL(NpcJump1, NPC_Parakarry, LVar0, 215, LVar2, 8 * DT)
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_SUB(LVar0, 30)
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 15 * DT)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_TRIP, SOUND_SPACE_DEFAULT, LVarA, LVarB, LVarC)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_SUB(LVar0, 15)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fallen)
    EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 8 * DT)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Parakarry, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetUp)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(NpcJump1, NPC_Parakarry, LVar0, LVar1, LVar2, 8 * DT)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT), 35, 255, EVT_FLOAT(17.5), EVT_FLOAT(-11.5))
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetNpcSpeed, NPC_Parakarry, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_Parakarry, LVar0, LVar2, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_000F)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Parakarry, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0010)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_0011)
    EVT_SET(GB_StoryProgress, STORY_CH2_SPOKE_WITH_PARAKARRY)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(BindNpcAI, NPC_Parakarry, EVT_PTR(N(EVS_NpcIdle_Parakarry)))
    EVT_RETURN
    EVT_END
};

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_MERLON,
    ITEM_LETTER_TO_KOLORADO,
    ITEM_LETTER_CHAIN_GOOMPAPA_1,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Parakarry) = {
    EVT_SET(LFlag0, FALSE)
    EVT_IF_EQ(GB_IWA10_ReturnedLetterCount, 2)
        EVT_SET(LVar0, 0)
        EVT_IF_EQ(GF_IWA01_Item_Letter01, TRUE)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_IF_EQ(GF_IWA03_Item_LettertoKolorado, TRUE)
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
            EVT_CALL(PlayerMoveTo, LVar4, LVar6, 20 * DT)
            EVT_CALL(PlayerFaceNpc, NPC_Parakarry, FALSE)
            EVT_WAIT(10 * DT)
            EVT_CALL(func_802CF56C, 2)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), EVT_FLOAT(0.0), EVT_FLOAT(300.0), EVT_FLOAT(17.5), EVT_FLOAT(-10.0))
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
                        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
                        EVT_RETURN
                    EVT_END_IF
                    EVT_SET(LFlag0, TRUE)
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
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Question)
                    EVT_WAIT(30 * DT)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
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
                    EVT_SET(LFlag0, TRUE)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(ContinueSpeech, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001D)
        EVT_CALL(N(ChangeNpcToPartner), 4, 4)
        EVT_SET(GB_StoryProgress, STORY_CH2_PARAKARRY_JOINED_PARTY)
        EVT_CALL(N(LoadPartyImage))
        EVT_EXEC(N(EVS_PushSong))
        EVT_WAIT(15 * DT)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018C, 160, 40)
        EVT_EXEC(N(EVS_PopSong))
        EVT_WAIT(10 * DT)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 0, MSG_CH2_001E)
        EVT_CALL(AddKeyItem, ITEM_LETTER_TO_MERLON)
        EVT_CALL(AddKeyItem, ITEM_LETTER_TO_KOLORADO)
        EVT_CALL(AddKeyItem, ITEM_LETTER_CHAIN_GOOMPAPA_1)
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
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

NpcData N(NpcData_Parakarry) = {
    .id = NPC_Parakarry,
    .pos = { -610.0f, 230.0f, -485.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Parakarry),
    .settings = &N(NpcSettings_Parakarry),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = PARAKARRY_ANIMS,
    .tattle = MSG_NpcTattle_IWA_Parakarry,
};
