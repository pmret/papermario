#include "sprite/player.h"

EvtScript N(EVS_Scene_RecoverTreeShell) = {
    EVT_WAIT(1)
    EVT_IF_EQ(GF_NOK01_RecoveredTreeShell, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_NOK01_RecoveredTreeShell, TRUE)
    EVT_CALL(BindNpcAI, NPC_Koopa_03, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(SetNpcAux, NPC_Koopa_03, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(5)
    EVT_CALL(NpcJump0, NPC_KoopaShell_03, 220, 0, 210, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaShell_03, SOUND_ITEM_BOUNCE, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlayerFaceNpc, NPC_KoopaShell_03, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_Koopa_03, NPC_KoopaShell_03, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_CALL(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Happy)
    EVT_CALL(NpcJump0, NPC_Koopa_03, LVar0, 0, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_KoopaShell_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Run)
    EVT_CALL(NpcMoveTo, NPC_Koopa_03, LVar0, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_KoopaShell_03, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlayerFaceNpc, NPC_Koopa_03, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Koopa_03, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_KoopaWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_KoopaShell_03, TRUE)
    EVT_CALL(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, NPC_KoopaShell_03)
    EVT_SET(LVar4, NPC_Koopa_03)
    EVT_EXEC(N(EVS_GetIntoShell))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_KoopaShell_03, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_KoopaShell_03, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcSprite, NPC_Koopa_03, ANIM_Koopa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_Koopa_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_KoopaShell_03, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_Koopa_Happy)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_03, ANIM_Koopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Koopa_03, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001A)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_03_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredTreeShell, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_03, ANIM_Koopa_Talk, ANIM_Koopa_Happy, 0, MSG_CH1_001B)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Koopa_03, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0019)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopa_03_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredTreeShell, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_NpcAI_KoopaWithoutShell_Wander))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RecoverBlockShell) = {
    EVT_IF_EQ(GF_NOK01_RecoveredBlockShell, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_NOK01_RecoveredBlockShell, TRUE)
    EVT_CALL(BindNpcAI, NPC_Koopa_02, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(SetNpcAux, NPC_Koopa_02, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcJump0, NPC_KoopaShell_02, 60, 0, 328, 20)
    EVT_CALL(PlaySound, SOUND_ITEM_BOUNCE)
    EVT_CALL(PlayerFaceNpc, NPC_KoopaShell_02, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_Koopa_02, NPC_KoopaShell_02, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Happy)
    EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_KoopaShell_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Run)
    EVT_CALL(NpcMoveTo, NPC_Koopa_02, LVar0, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlayerFaceNpc, NPC_Koopa_02, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Koopa_02, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, NPC_KoopaShell_02)
    EVT_SET(LVar4, NPC_Koopa_02)
    EVT_EXEC(N(EVS_GetIntoShell))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_KoopaShell_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Happy)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0012)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakBlock_DropShell) = {
    EVT_EXEC(N(EVS_Scene_RecoverBlockShell))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_02_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredBlockShell, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Idle, ANIM_Koopa_Happy, 0, MSG_CH1_0013)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0011)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopa_02_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredBlockShell, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_KooverGetsMugged) = {
    EVT_CALL(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 200)
    EVT_CALL(SetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -200)
    EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, LVar1, LVar2, 20)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, LVar0, LVar1, LVar2, 0, -1, 0, 3)
    EVT_THREAD
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 4)
        EVT_WAIT(60)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Shocked)
        EVT_WAIT(30)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcSprite, NPC_Koover, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Toppled)
    EVT_CALL(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_ADD(LVar2, -10)
    EVT_CALL(NpcJump0, NPC_Koover, LVar0, LVar1, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_WAIT(10)
    EVT_ADD(LVar0, 50)
    EVT_ADD(LVar2, -20)
    EVT_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 20)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Idle)
    EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Anim0C)
    EVT_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 20)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 20)
    EVT_CALL(NpcFaceNpc, NPC_Koover, NPC_FuzzyWithShell, 0)
    EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_CryIdle)
    EVT_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 20)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koover_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0003)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0000)
    EVT_CALL(InterpPlayerYaw, 227, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
    EVT_CALL(EndSpeech, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    EVT_CALL(InterpPlayerYaw, 47, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(EndSpeech, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(15)
    EVT_CALL(EndSpeech, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    EVT_EXEC_WAIT(N(EVS_Scene_KooverGetsMugged))
    EVT_CALL(SpeakToNpc, NPC_Koover, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, NPC_FuzzyWithShell, MSG_CH1_0001)
    EVT_SET(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koover_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SetPlayerPos, -386, 0, 399)
        EVT_CALL(PlayerMoveTo, -308, 326, 30)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(NpcFacePlayer, NPC_Koover, 5)
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_ADD(LVar1, 35)
        EVT_CALL(PlaySoundAtNpc, NPC_Koover, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_Koover, EMOTE_EXCLAMATION, 0, 20, EMOTER_POS, LVar0, LVar1, LVar2, 0)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Run)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(GetCamDistance, CAM_DEFAULT, LVarA)
        EVT_MULF(LVarA, EVT_FLOAT(0.7))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVarA)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 4)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(NpcMoveTo, NPC_Koover, -280, 301, 30)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Idle)
        EVT_WAIT(7)
        EVT_EXEC_WAIT(N(EVS_NpcInteract_Koover_Crisis))
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 40)
        EVT_CALL(SetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_Koover, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
            EVT_CALL(BindNpcInteract, NPC_Koover, EVT_PTR(N(EVS_NpcInteract_Koover_Crisis)))
            EVT_CALL(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetNpcPos, NPC_FuzzyWithShell, LVar0, LVar1, LVar2)
        EVT_CALL(NpcFaceNpc, NPC_Koover, NPC_FuzzyWithShell, 0)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_CryRun)
        EVT_CALL(NpcMoveTo, NPC_Koover, LVar0, LVar2, 17)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_CryIdle)
        EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_FuzzyWithShell) = {
    EVT_SET_GROUP(EVT_GROUP_0A)
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_KooversShell, NPC_DISPOSE_LOCATION)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -208)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 282)
    EVT_LABEL(10)
        EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
            EVT_CALL(GetNpcPos, NPC_FuzzyWithShell, LVarA, LVarB, LVarC)
            EVT_ADD(LVarA, 20)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(LVar0, 162)
    EVT_LABEL(0)
        EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
            EVT_CALL(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(N(CosInterpMinMax), LVar0, LVar1, -50, 50, 120, 0, 180)
        EVT_CALL(N(CosInterpMinMax), LVar0, LVar2, -32, 32, 120, 0, 30)
        EVT_ADD(LVar1, LVarA)
        EVT_ADD(LVar2, LVarC)
        EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Run)
        EVT_CALL(SetNpcPos, NPC_FuzzyWithShell, LVar1, LVarB, LVar2)
        EVT_SET(LVar3, LVarB)
        EVT_ADD(LVar3, 2)
        EVT_ADD(LVar0, 2)
        EVT_ADD(LVar2, 1)
        EVT_IF_EQ(LVar0, 240)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_KooversShell, LVar1, LVar3, LVar2)
        EVT_LABEL(1)
        EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_FuzzyWithShell) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SET(LVar1, 0)
    EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_HAMMER)
        EVT_ADD(LVar1, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_JUMP)
        EVT_ADD(LVar1, 1)
    EVT_END_IF
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_SET(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 25)
            EVT_ADD(LVar0, 40)
            EVT_ADD(LVar2, -40)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 15)
            EVT_ADD(LVar0, 30)
            EVT_ADD(LVar2, -30)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Anim09)
            EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 13)
            EVT_ADD(LVar0, 20)
            EVT_ADD(LVar2, -20)
            EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 11)
            EVT_ADD(LVar0, 10)
            EVT_ADD(LVar2, -10)
            EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 9)
            EVT_ADD(LVar0, 80)
            EVT_ADD(LVar2, -80)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyWithShell, ANIM_Fuzzy_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_FuzzyWithShell, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyWithShell, LVar0, 0, LVar2, 15)
            EVT_CALL(SetNpcPos, NPC_FuzzyWithShell, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_KooversShell, LVar0, 0, LVar2, 15)
        EVT_LOOP(70)
            EVT_CALL(PlayerFaceNpc, NPC_FuzzyWithShell, FALSE)
            EVT_CALL(NpcFaceNpc, NPC_Koover, NPC_FuzzyWithShell, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlayerFaceNpc, NPC_KooversShell, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_Koover, NPC_KooversShell, 0)
        EVT_THREAD
            EVT_CALL(AdjustCam, CAM_DEFAULT, 4, 0, EVT_FLOAT(-300.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_END_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Happy)
        EVT_CALL(NpcJump0, NPC_Koover, LVar0, 0, LVar2, 15)
        EVT_CALL(GetNpcPos, NPC_KooversShell, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Run)
        EVT_CALL(NpcMoveTo, NPC_Koover, LVar0, LVar2, 15)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Idle)
        EVT_CALL(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 10)
        EVT_CALL(NpcJump0, NPC_KooversShell, LVar0, LVar1, LVar2, 10)
        EVT_CALL(PlayerFaceNpc, NPC_Koover, FALSE)
        EVT_CALL(NpcFacePlayer, NPC_Koover, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_KoopaWithoutShell_Still)
        EVT_CALL(EnableNpcBlur, NPC_KooversShell, TRUE)
        EVT_CALL(GetNpcPos, NPC_Koover, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 20)
        EVT_SET(LVar3, NPC_KooversShell)
        EVT_SET(LVar4, NPC_Koover)
        EVT_EXEC(N(EVS_GetIntoShell))
        EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
        EVT_CALL(NpcJump0, NPC_KooversShell, LVar0, LVar1, LVar2, 30)
        EVT_CALL(SetNpcPos, NPC_KooversShell, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcSprite, NPC_Koover, ANIM_Koopa_Idle)
        EVT_CALL(SetNpcFlagBits, NPC_Koover, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Still)
        EVT_WAIT(4)
        EVT_CALL(EnableNpcBlur, NPC_KooversShell, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Idle)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Happy)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Koover, ANIM_Koopa_Idle)
        EVT_CALL(SpeakToPlayer, NPC_Koover, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0002)
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, 4)
        EVT_END_THREAD
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetEnemyFlagBits, NPC_Koover, ENEMY_FLAG_400000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_01_Crisis) = {
    EVT_IF_EQ(AF_NOK01_Dialogue_Bobomb_01_Crisis, FALSE)
        EVT_SET(AF_NOK01_Dialogue_Bobomb_01_Crisis, TRUE)
        EVT_SET(LVar0, MSG_CH1_003D)
    EVT_ELSE
        EVT_SET(AF_NOK01_Dialogue_Bobomb_01_Crisis, FALSE)
        EVT_SET(LVar0, MSG_CH1_003E)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_01_Crisis) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_01_Crisis)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_02_Crisis) = {
    EVT_IF_EQ(AF_NOK01_Dialogue_Bobomb_02, FALSE)
        EVT_SET(AF_NOK01_Dialogue_Bobomb_02, TRUE)
        EVT_SET(LVar0, MSG_CH1_0044)
    EVT_ELSE
        EVT_SET(AF_NOK01_Dialogue_Bobomb_02, FALSE)
        EVT_SET(LVar0, MSG_CH1_0045)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_02_Crisis) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_02_Crisis)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koover_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koover_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koover_Crisis)))
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_KoopaWithoutShell_Idle)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FuzzyWithShell) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_FuzzyWithShell)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_FuzzyWithShell)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MiscFuzzy1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MiscFuzzy1)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MiscFuzzy1)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MiscFuzzy2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MiscFuzzy2)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MiscFuzzy2)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KooversShell) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_02_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_02_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_02_Crisis)))
    EVT_CALL(SetNpcPos, NPC_Koopa_02, 40, 0, 325)
    EVT_CALL(InterpNpcYaw, NPC_Koopa_02, 180, 0)
    EVT_IF_EQ(GF_NOK01_RecoveredBlockShell, FALSE)
        EVT_CALL(SetNpcPos, NPC_KoopaShell_02, 22, 85, 375)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryRun)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaShell_02) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_03_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_03_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_03_Crisis)))
    EVT_IF_EQ(GF_NOK01_RecoveredTreeShell, FALSE)
        EVT_CALL(SetNpcPos, NPC_KoopaShell_03, 190, 114, 220)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_Koopa_03, ANIM_Koopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaShell_03) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};
