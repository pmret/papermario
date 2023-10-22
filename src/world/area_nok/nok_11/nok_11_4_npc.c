#include "nok_11.h"

#include "world/common/enemy/Goomba_Wander.inc.c"
#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/Paragoomba_Wander.inc.c"
#include "world/common/enemy/SpikedGoomba_Wander.inc.c"
#include "world/common/npc/JrTroopa.inc.c"
#include "world/common/enemy/KentCKoopa.inc.c"

#include "common/foliage.inc.c"

EvtScript N(EVS_JrTroopa_RunFX) = {
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
    EVT_WAIT(15 * DT)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(90.0), -190, 0, -40, 200, EVT_FLOAT(15.0), EVT_FLOAT(-8.5))
    EVT_WAIT(15 * DT)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Scene)))
    EVT_EXEC(N(EVS_SearchBush))
    EVT_WAIT(15 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_SELF, -230, 0, -157, 15 * DT)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_011F)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(4.0 / DT), -140, 0, -40, 400, EVT_FLOAT(15.0), EVT_FLOAT(-5.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Trip)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_0120, 160, 40)
    EVT_END_THREAD
    EVT_THREAD
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_LOOP(10 * DT)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_SELF, -201, -67, 10 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump1, NPC_SELF, -191, 0, -32, 5 * DT)
    EVT_EXEC_GET_TID(N(EVS_JrTroopa_RunFX), LVarA)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SLIDE, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcMoveTo, NPC_SELF, -165, 50, 15 * DT)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(StopSound, SOUND_SLIDE)
    EVT_WAIT(5 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_FallHeadfirstBack)
    EVT_WAIT(15 * DT)
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_WATER_SPLASH, SOUND_SPACE_DEFAULT)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_ADD(LVar0, 10)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_WAIT(5 * DT)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 25)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_ADD(LVar0, 10)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_WAIT(5 * DT)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, -15)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
        EVT_ADD(LVar0, 10)
        EVT_PLAY_EFFECT(EFFECT_WATER_SPLASH, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.7), 30)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_SELF, -165, -90, 50, 20 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SCAMPER, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ScamperBack)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_THREAD
        EVT_WAIT(85 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ClimbUpBack)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_SELF, 0)
    EVT_CALL(NpcJump0, NPC_SELF, -165, 0, 50, 90 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    EVT_CALL(NpcMoveTo, NPC_SELF, -190, -45, 10 * DT)
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
    EVT_WAIT(10 * DT)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0126)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot, 0, MSG_CH1_0127)
    EVT_END_IF
    EVT_WAIT(10 * DT)
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
    EVT_CALL(SetNpcFlagBits, NPC_JrTroopa_02, NPC_FLAG_INVISIBLE, TRUE)
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
    EVT_CALL(SetNpcPos, NPC_KentCKoopa_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
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
    EVT_CALL(SetNpcFlagBits, NPC_KentCKoopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(BindNpcInteract, NPC_KentCKoopa_02, EVT_PTR(N(EVS_NpcInteract_KentCKoopa_02)))
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
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

NpcData N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .pos = { -350.0f, 0.0f, -30.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_NOK_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
};

NpcData N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .pos = { 0.0f, 60.0f, -30.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = PARAGOOMBA_DROPS,
    .animations = PARAGOOMBA_ANIMS,
};

NpcData N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .pos = { 430.0f, 0.0f, -27.0f },
    .yaw = 270,
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
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKED_GOOMBA_DROPS,
    .animations = SPIKED_GOOMBA_ANIMS,
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
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_JrTroopa)[] = {
    {
        .id = NPC_JrTroopa_01,
        .pos = { -170.0f, 0.0f, -155.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa_01),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
    {
        .id = NPC_JrTroopa_02,
        .pos = { -170.0f, 0.0f, -155.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa_02),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
        .tattle = MSG_NpcTattle_JrTroopa,
    },
};

EvtScript N(EVS_NpcInit_KentCKoopa_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KentCKoopa_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KentCKoopa_01)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetEntryID, AB_NOK_2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KentCKoopa_02) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_KentCKoopa_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetEntryID, LVar3)
    EVT_IF_EQ(LVar3, nok_11_ENTRY_0)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_ELSE
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KentCKoopa)[] = {
    {
        .id = NPC_KentCKoopa_01,
        .pos = { -164.0f, 0.0f, -37.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KentCKoopa_01),
        .settings = &N(NpcSettings_KentCKoopa),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = KENT_C_KOOPA_ANIMS,
    },
    {
        .id = NPC_KentCKoopa_02,
        .pos = { -164.0f, 0.0f, -37.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KentCKoopa_02),
        .settings = &N(NpcSettings_KentCKoopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = KENT_C_KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_KentCKoopa,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_NOK_FORMATION_08, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_NOK_FORMATION_02, BTL_NOK_STAGE_00),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_NOK_FORMATION_03, BTL_NOK_STAGE_01),
    {}
};

NpcGroupList N(JrTroopaNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa), BTL_KMR_3_FORMATION_03),
    {}
};

NpcGroupList N(KentCKoopaNPCs) = {
    NPC_GROUP(N(NpcData_KentCKoopa), BTL_NOK_FORMATION_18, BTL_NOK_STAGE_00),
    {}
};
