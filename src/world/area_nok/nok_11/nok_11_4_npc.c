#include "nok_11.h"

#include "world/common/enemy/complete/Goomba_Wander.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/Paragoomba_Wander.inc.c"
#include "world/common/enemy/complete/SpikedGoomba_Wander.inc.c"

NpcSettings N(NpcSettings_JrTroopa_01) = {
    .height = 32,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_KentCKoopa_01) = {
    .height = 68,
    .radius = 80,
    .level = 99,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "common/foliage.inc.c"

EvtScript N(D_802433A4_9F7DE4) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_JrTroopa_01, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0)
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

FoliageModelList N(SceneBush_Models) = FOLIAGE_MODEL_LIST(MODEL_o125);

SearchBushConfig N(SearchBush_Scene) = {
    .bush = &N(SceneBush_Models),
};

EvtScript N(EVS_NpcIdle_JrTroopa_01) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LE(LVar0, -125)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CHILD_THREAD
        EVT_LABEL(10)
        EVT_WAIT(3)
        EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_CHILD_THREAD
    EVT_EXEC(N(EVS_PlayJrTroopaSong))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 5, MSG_CH1_011E)
    EVT_WAIT(15)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(90.0), -190, 0, -40, 200, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
    EVT_WAIT(15)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Scene)))
    EVT_EXEC(N(EVS_SearchBush))
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_SELF, -230, 0, -157, 15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_011F)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0), -140, 0, -40, 400, EVT_FLOAT(15.0), EVT_FLOAT(-5.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Trip)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0120, 160, 40)
    EVT_END_THREAD
    EVT_THREAD
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_SELF, -201, -67, 10)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump1, NPC_SELF, -191, 0, -32, 5)
    EVT_EXEC_GET_TID(N(D_802433A4_9F7DE4), LVarA)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_167, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -165, 50, 15)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(StopSound, SOUND_167)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_FallHeadfirstBack)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20AD, 0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_ADD(LVar0, 10)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 25)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_ADD(LVar0, 10)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, -15)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_ADD(LVar0, 10)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_301, 0)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_SELF, -165, -90, 50, 20)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_74, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ScamperBack)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_THREAD
        EVT_WAIT(85)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ClimbUpBack)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(NpcJump0, NPC_SELF, -165, 0, 50, 90)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_CALL(NpcMoveTo, NPC_SELF, -190, -45, 10)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_PointTapFoot)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(90.0), -140, 0, -40, 250, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0121)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PARTNER_GOOMBARIO)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 5, MSG_CH1_0122)
        EVT_CASE_EQ(PARTNER_KOOPER)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_CH1_0123)
        EVT_CASE_EQ(PARTNER_BOMBETTE)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 5, MSG_CH1_0124)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0125)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_WAIT(10)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0126)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0127)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(StartBossBattle, SONG_JR_TROOPA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_JrTroopa_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_JrTroopa_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH1_012B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_JrTroopa_02) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_JrTroopa_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_JrTroopa_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Defeated, ANIM_JrTroopa_Defeated, 5, MSG_CH1_012B)
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_JrTroopa_01) = {
    EVT_CALL(ClearDefeatedEnemies)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Defeated)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_JrTroopa_02, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 24, 32)
    EVT_CALL(SetNpcCollisionSize, NPC_JrTroopa_02, 24, 32)
    EVT_SET(GB_StoryProgress, STORY_CH1_DEFEATED_JR_TROOPA)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_THREAD
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_JrTroopa_01)))
    EVT_CALL(SetNpcFlagBits, NPC_JrTroopa_02, NPC_FLAG_2, TRUE)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KentCKoopa_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0134)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(KentCheckNotEnoughCoins)) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->coins >= 100) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(KentTakeCoins)) {
    PlayerData* playerData = &gPlayerData;

    playerData->coins -= 100;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_KentCKoopa_01) = {
    EVT_LABEL(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_IF_GE(LVar0, -260)
            EVT_GOTO(10)
        EVT_ELSE
            EVT_GOTO(2)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_LE(LVar0, -55)
            EVT_GOTO(10)
        EVT_ELSE
            EVT_GOTO(2)
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(2)
    EVT_WAIT(1)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012C)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 20)
    EVT_ELSE
        EVT_SET(LVar0, -20)
    EVT_END_IF
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), LVar0, EVT_FLOAT(275.0), EVT_FLOAT(17.5), EVT_FLOAT(-12.0))
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012D)
    EVT_LABEL(15)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_0045)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 20)
    EVT_ELSE
        EVT_SET(LVar0, -20)
    EVT_END_IF
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012E)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_0045)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_LABEL(20)
    EVT_CALL(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0135)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 20)
    EVT_ELSE
        EVT_SET(LVar0, -20)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0136)
    EVT_CALL(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim05)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 90)
    EVT_ELSE
        EVT_SET(LVar0, 270)
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_KentCKoopa_02, LVar0, 0)
    EVT_WAIT(30)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 125)
    EVT_ELSE
        EVT_SET(LVar0, -430)
    EVT_END_IF
    EVT_CALL(NpcMoveTo, NPC_KentCKoopa_02, LVar0, -37, 40)
    EVT_CALL(SetNpcPos, NPC_KentCKoopa_02, 0, -1000, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_GOTO(100)
    EVT_LABEL(30)
    EVT_CALL(N(KentCheckNotEnoughCoins))
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(40)
    EVT_END_IF
    EVT_CALL(CloseMessage)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, -215)
    EVT_ELSE
        EVT_SET(LVar0, -100)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim03)
    EVT_CALL(NpcMoveTo, NPC_KentCKoopa_02, LVar0, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim01)
    EVT_CALL(N(KentTakeCoins))
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0133)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim03)
    EVT_CALL(NpcMoveTo, NPC_KentCKoopa_02, -167, -100, 20)
    EVT_CALL(SetNpcFlagBits, NPC_KentCKoopa_02, NPC_FLAG_100, FALSE)
    EVT_CALL(BindNpcInteract, NPC_KentCKoopa_02, EVT_PTR(N(EVS_NpcInteract_KentCKoopa_02)))
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(SetNpcAnimation, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim01)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 270)
    EVT_ELSE
        EVT_SET(LVar0, 90)
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_KentCKoopa_02, LVar0, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0134)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_GOTO(100)
    EVT_LABEL(40)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_012F)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(41)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_IF_GE(LVar0, -255)
            EVT_SET(LVar3, -256)
            EVT_GOTO(43)
        EVT_ELSE
            EVT_GOTO(42)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_LE(LVar0, -60)
            EVT_SET(LVar3, -59)
            EVT_GOTO(43)
        EVT_ELSE
            EVT_GOTO(42)
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(42)
    EVT_WAIT(1)
    EVT_GOTO(41)
    EVT_LABEL(43)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetPlayerPos, LVar3, LVar1, LVar2)
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0130)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar3, LVar1, LVar2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_GOTO(41)
    EVT_LABEL(50)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(ContinueSpeech, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0131)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(51)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_IF_GE(LVar0, -255)
            EVT_SET(LVar3, -256)
            EVT_GOTO(53)
        EVT_ELSE
            EVT_GOTO(52)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_LE(LVar0, -60)
            EVT_SET(LVar3, -59)
            EVT_GOTO(53)
        EVT_ELSE
            EVT_GOTO(52)
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(52)
    EVT_WAIT(1)
    EVT_GOTO(51)
    EVT_LABEL(53)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    EVT_CALL(SetPlayerPos, LVar3, LVar1, LVar2)
    EVT_CALL(SpeakToPlayer, NPC_KentCKoopa_02, ANIM_KentCKoopa_Anim02, ANIM_KentCKoopa_Anim01, 0, MSG_CH1_0132)
    EVT_IF_EQ(AB_NOK_2, 0)
        EVT_SET(LVar0, 20)
    EVT_ELSE
        EVT_SET(LVar0, -20)
    EVT_END_IF
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), LVar0, EVT_FLOAT(275.0), EVT_FLOAT(17.5), EVT_FLOAT(-12.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar3, LVar1, LVar2)
    EVT_GOTO(15)
    EVT_LABEL(100)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KentCKoopa_01) = {
    EVT_SET(GF_NOK11_Defeated_KentC, TRUE)
    EVT_CALL(ClearDefeatedEnemies)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KentCKoopa_02) = {
    EVT_CALL(ClearDefeatedEnemies)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .pos = { -350.0f, 0.0f, -30.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 3, 0 },
            { ITEM_KOOPA_LEAF, 7, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -350, 0, -30 },
            .wanderSize = { 50, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -350, 0, -30 },
            .detectSize = { 250 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Idle,
        .walk   = ANIM_KoopaTroopa_Walk,
        .run    = ANIM_KoopaTroopa_Run,
        .chase  = ANIM_KoopaTroopa_Run,
        .anim_4 = ANIM_KoopaTroopa_Idle,
        .anim_5 = ANIM_KoopaTroopa_Idle,
        .death  = ANIM_KoopaTroopa_Hurt,
        .hit    = ANIM_KoopaTroopa_Hurt,
        .anim_8 = ANIM_KoopaTroopa_ShellEnter,
        .anim_9 = ANIM_KoopaTroopa_ShellSpin,
        .anim_A = ANIM_KoopaTroopa_ShellExit,
        .anim_B = ANIM_KoopaTroopa_Run,
        .anim_C = ANIM_KoopaTroopa_Run,
        .anim_D = ANIM_KoopaTroopa_Run,
        .anim_E = ANIM_KoopaTroopa_Run,
        .anim_F = ANIM_KoopaTroopa_Run,
    },
};

StaticNpc N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .pos = { 0.0f, 60.0f, -30.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_400,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 0, 60, -30 },
            .wanderSize = { 50, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 60, -30 },
            .detectSize = { 250 },
        }
    },
    .animations = {
        .idle   = ANIM_Paragoomba_Idle,
        .walk   = ANIM_Paragoomba_Walk,
        .run    = ANIM_Paragoomba_Run,
        .chase  = ANIM_Paragoomba_Run,
        .anim_4 = ANIM_Paragoomba_Idle,
        .anim_5 = ANIM_Paragoomba_Idle,
        .death  = ANIM_Paragoomba_Hurt,
        .hit    = ANIM_Paragoomba_Hurt,
        .anim_8 = ANIM_Paragoomba_Run,
        .anim_9 = ANIM_Paragoomba_Run,
        .anim_A = ANIM_Paragoomba_Run,
        .anim_B = ANIM_Paragoomba_Run,
        .anim_C = ANIM_Paragoomba_Run,
        .anim_D = ANIM_Paragoomba_Run,
        .anim_E = ANIM_Paragoomba_Run,
        .anim_F = ANIM_Paragoomba_Run,
    },
};

StaticNpc N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .pos = { 430.0f, 0.0f, -27.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 430, 0, -27 },
            .wanderSize = { 50, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 430, 0, -27 },
            .detectSize = { 250 },
        }
    },
    .animations = {
        .idle   = ANIM_SpikedGoomba_Idle,
        .walk   = ANIM_SpikedGoomba_Walk,
        .run    = ANIM_SpikedGoomba_Run,
        .chase  = ANIM_SpikedGoomba_Run,
        .anim_4 = ANIM_SpikedGoomba_Idle,
        .anim_5 = ANIM_SpikedGoomba_Idle,
        .death  = ANIM_SpikedGoomba_HurtStill,
        .hit    = ANIM_SpikedGoomba_HurtStill,
        .anim_8 = ANIM_SpikedGoomba_Run,
        .anim_9 = ANIM_SpikedGoomba_Run,
        .anim_A = ANIM_SpikedGoomba_Run,
        .anim_B = ANIM_SpikedGoomba_Run,
        .anim_C = ANIM_SpikedGoomba_Run,
        .anim_D = ANIM_SpikedGoomba_Run,
        .anim_E = ANIM_SpikedGoomba_Run,
        .anim_F = ANIM_SpikedGoomba_Run,
    },
};

EvtScript N(EVS_NpcInit_JrTroopa_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_JrTroopa_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_JrTroopa_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_JrTroopa_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_JrTroopa_01)[] = {
    {
        .id = NPC_JrTroopa_01,
        .settings = &N(NpcSettings_JrTroopa_01),
        .pos = { -170.0f, 0.0f, -155.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_JrTroopa_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_JrTroopa_Idle,
            .walk   = ANIM_JrTroopa_Walk,
            .run    = ANIM_JrTroopa_Walk,
            .chase  = ANIM_JrTroopa_Walk,
            .anim_4 = ANIM_JrTroopa_Idle,
            .anim_5 = ANIM_JrTroopa_Idle,
            .death  = ANIM_JrTroopa_Idle,
            .hit    = ANIM_JrTroopa_Idle,
            .anim_8 = ANIM_JrTroopa_Idle,
            .anim_9 = ANIM_JrTroopa_Idle,
            .anim_A = ANIM_JrTroopa_Idle,
            .anim_B = ANIM_JrTroopa_Idle,
            .anim_C = ANIM_JrTroopa_Idle,
            .anim_D = ANIM_JrTroopa_Idle,
            .anim_E = ANIM_JrTroopa_Idle,
            .anim_F = ANIM_JrTroopa_Idle,
        },
        .tattle = MSG_NpcTattle_JrTroopa,
    },
    {
        .id = NPC_JrTroopa_02,
        .settings = &N(NpcSettings_JrTroopa_01),
        .pos = { -170.0f, 0.0f, -155.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_800000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_20000000,
        .init = &N(EVS_NpcInit_JrTroopa_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_JrTroopa_Idle,
            .walk   = ANIM_JrTroopa_Walk,
            .run    = ANIM_JrTroopa_Walk,
            .chase  = ANIM_JrTroopa_Walk,
            .anim_4 = ANIM_JrTroopa_Idle,
            .anim_5 = ANIM_JrTroopa_Idle,
            .death  = ANIM_JrTroopa_Idle,
            .hit    = ANIM_JrTroopa_Idle,
            .anim_8 = ANIM_JrTroopa_Idle,
            .anim_9 = ANIM_JrTroopa_Idle,
            .anim_A = ANIM_JrTroopa_Idle,
            .anim_B = ANIM_JrTroopa_Idle,
            .anim_C = ANIM_JrTroopa_Idle,
            .anim_D = ANIM_JrTroopa_Idle,
            .anim_E = ANIM_JrTroopa_Idle,
            .anim_F = ANIM_JrTroopa_Idle,
        },
        .tattle = MSG_NpcTattle_JrTroopa,
    },
};

EvtScript N(EVS_NpcInit_KentCKoopa_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KentCKoopa_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KentCKoopa_01)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(GetEntryID, AB_NOK_2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KentCKoopa_02) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KentCKoopa_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(GetEntryID, LVar3)
    EVT_IF_EQ(LVar3, nok_11_ENTRY_0)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_ELSE
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KentCKoopa_01)[] = {
    {
        .id = NPC_KentCKoopa_01,
        .settings = &N(NpcSettings_KentCKoopa_01),
        .pos = { -164.0f, 0.0f, -37.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_4000 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_800000,
        .init = &N(EVS_NpcInit_KentCKoopa_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KentCKoopa_Anim01,
            .walk   = ANIM_KentCKoopa_Anim01,
            .run    = ANIM_KentCKoopa_Anim01,
            .chase  = ANIM_KentCKoopa_Anim01,
            .anim_4 = ANIM_KentCKoopa_Anim01,
            .anim_5 = ANIM_KentCKoopa_Anim01,
            .death  = ANIM_KentCKoopa_Anim01,
            .hit    = ANIM_KentCKoopa_Anim01,
            .anim_8 = ANIM_KentCKoopa_Anim01,
            .anim_9 = ANIM_KentCKoopa_Anim01,
            .anim_A = ANIM_KentCKoopa_Anim01,
            .anim_B = ANIM_KentCKoopa_Anim01,
            .anim_C = ANIM_KentCKoopa_Anim01,
            .anim_D = ANIM_KentCKoopa_Anim01,
            .anim_E = ANIM_KentCKoopa_Anim01,
            .anim_F = ANIM_KentCKoopa_Anim01,
        },
    },
    {
        .id = NPC_KentCKoopa_02,
        .settings = &N(NpcSettings_KentCKoopa_01),
        .pos = { -164.0f, 0.0f, -37.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_800000,
        .init = &N(EVS_NpcInit_KentCKoopa_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KentCKoopa_Anim01,
            .walk   = ANIM_KentCKoopa_Anim01,
            .run    = ANIM_KentCKoopa_Anim01,
            .chase  = ANIM_KentCKoopa_Anim01,
            .anim_4 = ANIM_KentCKoopa_Anim01,
            .anim_5 = ANIM_KentCKoopa_Anim01,
            .death  = ANIM_KentCKoopa_Anim01,
            .hit    = ANIM_KentCKoopa_Anim01,
            .anim_8 = ANIM_KentCKoopa_Anim01,
            .anim_9 = ANIM_KentCKoopa_Anim01,
            .anim_A = ANIM_KentCKoopa_Anim01,
            .anim_B = ANIM_KentCKoopa_Anim01,
            .anim_C = ANIM_KentCKoopa_Anim01,
            .anim_D = ANIM_KentCKoopa_Anim01,
            .anim_E = ANIM_KentCKoopa_Anim01,
            .anim_F = ANIM_KentCKoopa_Anim01,
        },
        .tattle = MSG_NpcTattle_KentCKoopa,
    },
};

NpcGroupList N(NpcGroup3) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_NOK_FORMATION_08, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_NOK_FORMATION_02, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_NOK_FORMATION_03, BTL_NOK_STAGE_01),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa_01), BTL_KMR_PART_3_FORMATION_03),
    {}
};

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_KentCKoopa_01), BTL_NOK_FORMATION_18, BTL_NOK_STAGE_00),
    {}
};
