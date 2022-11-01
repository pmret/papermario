#include "arn_07.h"
#include "effects.h"

#include "world/common/enemy/complete/HyperParagoomba.inc.c"
#include "world/common/npc/TubbasHeart.inc.c"
#include "world/common/enemy/complete/TubbaBlubba.inc.c"
#include "world/common/npc/Boo.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

API_CALLABLE(N(UpgradeStarPower)) {
    set_max_SP(3);
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_TubbaWalking) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_Tubba, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.8))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_TubbaRelents) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 236, 0, -46)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 0, -46)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim08)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 5, MSG_CH3_00CA)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 5, MSG_CH3_00CB)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(5.0), EVT_FLOAT(-16.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BossDefeated) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim22)
    EVT_WAIT(15)
    EVT_LOOP(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
        EVT_CALL(SetNpcVar, NPC_Boo_02, 0, 1)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
        EVT_CALL(SetNpcVar, NPC_Boo_05, 0, 1)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
        EVT_CALL(SetNpcVar, NPC_Boo_01, 0, 1)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
        EVT_CALL(SetNpcVar, NPC_Boo_03, 0, 1)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
        EVT_CALL(SetNpcVar, NPC_Boo_04, 0, 1)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
        EVT_CALL(SetNpcVar, NPC_Boo_06, 0, 1)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim23)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim22)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000010, 0)
    EVT_CALL(SetNpcVar, NPC_Boo_02, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim21)
    EVT_WAIT(45)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 236, 0, -46)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim0F)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 0, MSG_CH3_00CC)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_LOOP(40)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_802CF56C, 2)
        EVT_LOOP(45)
            EVT_CALL(PlayerFaceNpc, NPC_SELF, TRUE)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(EVS_TubbaWalking), LVarA)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 800)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 80)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
    EVT_CALL(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EVT_CALL(GetCurrentPartnerID, LVar6)
    EVT_IF_EQ(LVar6, PARTNER_BOW)
        EVT_SET(LVar5, -4)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 257, 25, 0)
    EVT_END_IF
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_WAIT(10)
    EVT_IF_NE(LVar6, PARTNER_BOW)
        EVT_SET(LVar5, 8)
        EVT_CALL(SetNpcPos, NPC_Bow, 257, 25, 0)
        EVT_CALL(func_802CFD30, 8, 7, 0, 0, 0, 0)
        EVT_CALL(NpcFacePlayer, NPC_Bow, 0)
        EVT_CALL(MakeLerp, 0, 240, 20, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, 8, 7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_802CF56C, 0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_THREAD
        EVT_IF_NE(LVar6, PARTNER_BOW)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Bow, 0)
            EVT_WAIT(5)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00CD)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, LVar5, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -20)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), LVar0, LVar1, LVar2, EVT_FLOAT(300.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(PlayerFaceNpc, LVar5, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00CE)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00CF)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00D0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00D1)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 175, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 175, 0, 0)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, NPC_Bootler, 93, 160, -6)
    EVT_CALL(InterpNpcYaw, NPC_Bootler, 90, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar6, PARTNER_BOW)
            EVT_WAIT(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 160, 31, 70, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_Bootler, 93, LVar0, -6)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_IF_NE(LVar6, PARTNER_BOW)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00D2)
    EVT_THREAD
        EVT_IF_NE(LVar6, PARTNER_BOW)
            EVT_WAIT(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_EXEC(N(EVS_SpawnStarCard))
    EVT_WAIT(20)
    EVT_THREAD
        EVT_IF_NE(LVar6, 9)
            EVT_CALL(MakeLerp, 240, 0, 20, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, 8, 7, LVar0, 0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetNpcPos, NPC_Bow, NPC_DISPOSE_LOCATION)
            EVT_CALL(EnablePartnerAI)
        EVT_ELSE
            EVT_WAIT(20)
            EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
        EVT_WAIT(8)
        EVT_CALL(func_802CF56C, 2)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Tubba) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(StartBossBattle, SONG_TUBBA_BLUBBA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Boo) = {
    EVT_LABEL(10)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_SETF(LVar0, EVT_FLOAT(0.5))
        EVT_CALL(MakeLerp, 50, 80, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 100)
            EVT_CALL(SetNpcScale, NPC_SELF, LVar2, LVar2, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(RandInt, 80, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 5)
        EVT_CALL(MakeLerp, LVar2, 240, LVar3, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, -1, 7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_SELF, 293, 59, 21)
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(-0.3))
    EVT_CALL(RandInt, 100, LVar3)
    EVT_SUB(LVar0, LVar3)
    EVT_ADD(LVar1, 100)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Tubba) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAGS_2, TRUE)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 1, 8)
            EVT_EXEC_WAIT(N(EVS_Scene_TubbaRelents))
            EVT_EXEC(N(EVS_Scene_BossDefeated))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TubbasHeart) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Tubba) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Tubba)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Tubba)))
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Boo) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Boo)))
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bow) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bootler) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WINDY_MILL)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Tubba)[] = {
    ANIM_WorldTubba_Anim00,
    ANIM_WorldTubba_Anim22,
    ANIM_WorldTubba_Anim23,
    ANIM_WorldTubba_Anim06,
    ANIM_WorldTubba_Anim10,
    ANIM_WorldTubba_Anim08,
    ANIM_WorldTubba_Anim0F,
    ANIM_WorldTubba_Anim12,
    -1
};

s32 N(ExtraAnims_Boo)[] = {
    ANIM_Boo_Still,
    -1
};

s32 N(ExtraAnims_GustyBoo)[] = {
    ANIM_Boo_Tan_Still,
    -1
};

s32 N(ExtraAnims_Bootler)[] = {
    ANIM_Bootler_Idle,
    -1
};

EvtScript N(EVS_NpcIdle_Skolar) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_SkolarRescued) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_SET(LVar4, LVar1)
    EVT_ADD(LVar4, 26)
    EVT_CALL(SetNpcPos, NPC_Skolar, LVar3, LVar4, LVar2)
    EVT_CALL(PlayerFaceNpc, NPC_Skolar, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Skolar, 0)
    EVT_ADD(LVar0, -25)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(475.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -8)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D3)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Skolar, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Skolar, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Leap)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_CALL(PlaySoundAtPlayer, SOUND_139, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_188, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, NPC_Skolar, ANIM_WorldSkolar_Idle)
    EVT_CALL(EnableNpcAI, NPC_Skolar, TRUE)
    EVT_CALL(N(UpgradeStarPower))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0193, 160, 40)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D4)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Skolar, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D5)
    EVT_CALL(SetNpcFlagBits, NPC_Skolar, NPC_FLAG_40000, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Skolar, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 1800)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Skolar, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Skolar, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Skolar, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Skolar, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, NPC_Skolar, SOUND_2045, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(90)
    EVT_CALL(ResetCam, CAM_DEFAULT, 3)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_SET(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, arn_07_ENTRY_3)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Skolar)))
        EVT_EXEC(N(EVS_Scene_SkolarRescued))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Tubba)[] = {
    {
        .id = NPC_Tubba,
        .settings = &N(NpcSettings_TubbaBlubba),
        .pos = { 309.0f, 0.0f, 11.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_4 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_40000 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Tubba),
        .drops = TUBBA_DROPS,
        .animations = TUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Tubba),
    },
    {
        .id = NPC_TubbasHeart,
        .settings = &N(NpcSettings_TubbasHeart),
        .pos = { -10.0f, 50.0f, -170.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_40000 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_TubbasHeart),
        .drops = TUBBAS_HEART_DROPS,
        .animations = TUBBAS_HEART_ANIMS,
    },
};

StaticNpc N(NpcData_Boos)[] = {
    {
        .id = NPC_Boo_01,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Boo),
        .drops = BOO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_02,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Boo),
        .drops = BOO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_03,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Boo),
        .drops = BOO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_04,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Boo),
        .drops = BOO_DROPS,
        .animations = GUSTY_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_GustyBoo),
    },
    {
        .id = NPC_Boo_05,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Boo),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_Boo),
    },
    {
        .id = NPC_Boo_06,
        .settings = &N(NpcSettings_Boo),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
        .init = &N(EVS_NpcInit_Boo),
        .drops = BOO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
        .extraAnimations = N(ExtraAnims_Boo),
    },
};

StaticNpc N(NpcData_Bow) = {
    .id = NPC_Bow,
    .settings = &N(NpcSettings_Boo),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
    .init = &N(EVS_NpcInit_Bow),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldBow_Idle,
        .walk   = ANIM_WorldBow_Walk,
        .run    = ANIM_WorldBow_Run,
        .chase  = ANIM_WorldBow_Run,
        .anim_4 = ANIM_WorldBow_Idle,
        .anim_5 = ANIM_WorldBow_Idle,
        .death  = ANIM_WorldBow_Still,
        .hit    = ANIM_WorldBow_Still,
        .anim_8 = ANIM_WorldBow_Run,
        .anim_9 = ANIM_WorldBow_Run,
        .anim_A = ANIM_WorldBow_Run,
        .anim_B = ANIM_WorldBow_Run,
        .anim_C = ANIM_WorldBow_Run,
        .anim_D = ANIM_WorldBow_Run,
        .anim_E = ANIM_WorldBow_Run,
        .anim_F = ANIM_WorldBow_Run,
    },
};

StaticNpc N(NpcData_Bootler) = {
    .id = NPC_Bootler,
    .settings = &N(NpcSettings_Boo),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_200000,
    .init = &N(EVS_NpcInit_Bootler),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Bootler_Idle,
        .walk   = ANIM_Bootler_Walk,
        .run    = ANIM_Bootler_Run,
        .chase  = ANIM_Bootler_Run,
        .anim_4 = ANIM_Bootler_Idle,
        .anim_5 = ANIM_Bootler_Idle,
        .death  = ANIM_Bootler_Still,
        .hit    = ANIM_Bootler_Still,
        .anim_8 = ANIM_Bootler_Shock,
        .anim_9 = ANIM_Bootler_Panic,
        .anim_A = ANIM_Bootler_Dejected,
        .anim_B = ANIM_Bootler_Quaver,
        .anim_C = ANIM_Bootler_Shock,
        .anim_D = ANIM_Bootler_Panic,
        .anim_E = ANIM_Bootler_Dejected,
        .anim_F = ANIM_Bootler_Quaver,
    },
    .extraAnimations = N(ExtraAnims_Bootler),
};

EvtScript N(EVS_NpcInit_HyperParagoomba) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER)
        EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_HyperParagoomba_01) = {
    .id = NPC_HyperParagoomba_01,
    .settings = &N(NpcSettings_HyperParagoomba),
    .pos = { -216.0f, 60.0f, -10.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_HyperParagoomba),
    .drops = HYPER_PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -216, 60, -10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -216, 60, -10 },
            .detectSize = { 250 },
        }
    },
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_HyperParagoomba_02) = {
    .id = NPC_HyperParagoomba_02,
    .settings = &N(NpcSettings_HyperParagoomba),
    .pos = { 0.0f, 60.0f, 150.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_HyperParagoomba),
    .drops = HYPER_PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 60, 150 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 60, 150 },
            .detectSize = { 250 },
        }
    },
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_HyperParagoomba_03) = {
    .id = NPC_HyperParagoomba_03,
    .settings = &N(NpcSettings_HyperParagoomba),
    .pos = { 260.0f, 60.0f, 30.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_HyperParagoomba),
    .drops = HYPER_PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 260, 60, 30 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 260, 60, 30 },
            .detectSize = { 250 },
        }
    },
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Skolar) = {
    .id = NPC_Skolar,
    .settings = &N(NpcSettings_StarSpirit),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Skolar),
    .drops = SKOLAR_DROPS,
    .animations = SKOLAR_ANIMS,
};

NpcGroupList N(BossNPCs) = {
    NPC_GROUP(N(NpcData_Tubba), BTL_ARN_FORMATION_10, BTL_ARN_STAGE_01),
    NPC_GROUP(N(NpcData_Boos)),
    NPC_GROUP(N(NpcData_Bow)),
    NPC_GROUP(N(NpcData_Bootler)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HyperParagoomba_01), BTL_ARN_FORMATION_06, BTL_ARN_STAGE_01),
    NPC_GROUP(N(NpcData_HyperParagoomba_02), BTL_ARN_FORMATION_07, BTL_ARN_STAGE_01),
    NPC_GROUP(N(NpcData_HyperParagoomba_03), BTL_ARN_FORMATION_08, BTL_ARN_STAGE_01),
    {}
};

NpcGroupList N(SpiritNPCs) = {
    NPC_GROUP(N(NpcData_Skolar)),
    {}
};
