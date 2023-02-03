EvtScript N(EVS_NpcInteract_Koopa_05_Crisis) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_IF_EQ(AF_NOK_09, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0021)
            EVT_SET(AF_NOK_09, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0022)
            EVT_SET(AF_NOK_09, FALSE)
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0023)
        EVT_RETURN
    EVT_END_IF
    EVT_SWITCH(AB_NOK_0)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0024)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0025)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0026)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_Koopa_05, ANIM_Koopa_LeanBackTalk, ANIM_Koopa_LeanBack, 5, MSG_CH1_0027)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80249E24) = {
    EVT_WAIT(1)
    EVT_IF_EQ(GF_NOK01_RecoveredShellC, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_NOK01_RecoveredShellC, TRUE)
    EVT_CALL(BindNpcAI, NPC_KoopaWithoutShell_02, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(SetNpcAux, NPC_KoopaWithoutShell_02, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(5)
    EVT_CALL(NpcJump0, NPC_Koopa_04, 220, 0, 210, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_Koopa_04, SOUND_21A, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Koopa_04, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_KoopaWithoutShell_02, NPC_Koopa_04, 0)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaWithoutShell_02, NPC_FLAG_100, TRUE)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell_02, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_KoopaWithoutShell_Happy)
    EVT_CALL(NpcJump0, NPC_KoopaWithoutShell_02, LVar0, 0, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_Koopa_04, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_KoopaWithoutShell_Run)
    EVT_CALL(NpcMoveTo, NPC_KoopaWithoutShell_02, LVar0, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_Koopa_04, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlayerFaceNpc, NPC_KoopaWithoutShell_02, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_KoopaWithoutShell_02, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_KoopaWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_04, TRUE)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, 6)
    EVT_SET(LVar4, 5)
    EVT_EXEC(N(D_80248F90_9CE370))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_Koopa_04, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_Koopa_04, 0, -1000, 0)
    EVT_CALL(SetNpcSprite, NPC_KoopaWithoutShell_02, ANIM_Koopa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaWithoutShell_02, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_Koopa_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_04, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_Koopa_Happy)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_02, ANIM_Koopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell_02, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001A)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaWithoutShell_02_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellC, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell_02, ANIM_Koopa_Talk, ANIM_Koopa_Happy, 0, MSG_CH1_001B)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0019)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaWithoutShell_02_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellC, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_NpcAI_KoopaWithoutShell_01))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A324_9CF704) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_NOK01_RecoveredShellB, TRUE)
    EVT_CALL(BindNpcAI, NPC_KoopaWithoutShell_01, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(SetNpcAux, NPC_KoopaWithoutShell_01, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcJump0, NPC_Koopa_03, 60, 0, 328, 20)
    EVT_CALL(PlaySound, SOUND_21A)
    EVT_CALL(PlayerFaceNpc, NPC_Koopa_03, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_KoopaWithoutShell_01, NPC_Koopa_03, 0)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaWithoutShell_01, NPC_FLAG_100, TRUE)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell_01, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_KoopaWithoutShell_Happy)
    EVT_CALL(NpcJump0, NPC_KoopaWithoutShell_01, LVar0, 0, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_Koopa_03, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_KoopaWithoutShell_Run)
    EVT_CALL(NpcMoveTo, NPC_KoopaWithoutShell_01, LVar0, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_Koopa_03, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlayerFaceNpc, NPC_KoopaWithoutShell_01, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_KoopaWithoutShell_01, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_KoopaWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_03, TRUE)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, 4)
    EVT_SET(LVar4, 3)
    EVT_EXEC(N(D_80248F90_9CE370))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_Koopa_03, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_Koopa_03, 0, -1000, 0)
    EVT_CALL(SetNpcSprite, NPC_KoopaWithoutShell_01, ANIM_Koopa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaWithoutShell_01, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_Koopa_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_03, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_Koopa_Happy)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_Koopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0012)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024A758) = {
    EVT_EXEC(N(D_8024A324_9CF704))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaWithoutShell_01_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellB, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell_01, ANIM_Koopa_Idle, ANIM_Koopa_Happy, 0, MSG_CH1_0013)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell_01, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0011)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaWithoutShell_01_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024A814_9CFBF4) = {
    EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 200)
    EVT_CALL(SetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -200)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, LVar1, LVar2, 20)
    EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, 3, LVar0, LVar1, LVar2, 0, -1, 0, 3)
    EVT_THREAD
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 4)
        EVT_WAIT(60)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000A)
        EVT_WAIT(30)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
    EVT_CALL(SetNpcSprite, NPC_Koopa_01, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Toppled)
    EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_ADD(LVar2, -10)
    EVT_CALL(NpcJump0, NPC_Koopa_01, LVar0, LVar1, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_WAIT(10)
    EVT_ADD(LVar0, 50)
    EVT_ADD(LVar2, -20)
    EVT_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 20)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Idle)
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C)
    EVT_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 20)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 20)
    EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_Fuzzy_01, 0)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryIdle)
    EVT_THREAD
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 20)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_01_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0003)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0000)
    EVT_CALL(InterpPlayerYaw, 227, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
    EVT_CALL(EndSpeech, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    EVT_CALL(InterpPlayerYaw, 47, 5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(EndSpeech, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
    EVT_WAIT(15)
    EVT_CALL(EndSpeech, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0)
    EVT_EXEC_WAIT(N(D_8024A814_9CFBF4))
    EVT_CALL(SpeakToNpc, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, NPC_Fuzzy_01, MSG_CH1_0001)
    EVT_SET(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopa_01_Crisis) = {
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SetPlayerPos, -386, 0, 399)
        EVT_CALL(PlayerMoveTo, -308, 326, 30)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(NpcFacePlayer, NPC_Koopa_01, 5)
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_ADD(LVar1, 35)
        EVT_CALL(PlaySoundAtNpc, NPC_Koopa_01, SOUND_262, 0)
        EVT_CALL(ShowEmote, NPC_Koopa_01, EMOTE_EXCLAMATION, 0, 20, 2, LVar0, LVar1, LVar2, 0)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Run)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(GetCamDistance, CAM_DEFAULT, LVarA)
        EVT_MULF(LVarA, EVT_FLOAT(0.7))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVarA)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 4)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(NpcMoveTo, NPC_Koopa_01, -280, 301, 30)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Idle)
        EVT_WAIT(7)
        EVT_EXEC_WAIT(N(EVS_NpcInteract_Koopa_01_Crisis))
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_WAIT(5)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 40)
        EVT_CALL(SetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_Koopa_01, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Koopa_01, NPC_FLAG_100, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(BindNpcInteract, NPC_Koopa_01, EVT_PTR(N(EVS_NpcInteract_Koopa_01_Crisis)))
        EVT_CALL(SetNpcFlagBits, NPC_Koopa_01, NPC_FLAG_100, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
    EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_Fuzzy_01, 0)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryRun)
    EVT_CALL(NpcMoveTo, NPC_Koopa_01, LVar0, LVar2, 17)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryIdle)
    EVT_LABEL(1)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Fuzzy_01) = {
    EVT_SET_GROUP(EVT_GROUP_0A)
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
        EVT_CALL(SetNpcPos, NPC_Koopa_02, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -208)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 282)
    EVT_LABEL(10)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVarA, LVarB, LVarC)
        EVT_ADD(LVarA, 20)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVar0, 162)
    EVT_LABEL(0)
    EVT_IF_EQ(GF_NOK01_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(CosInterpMinMax), LVar0, LVar1, -50, 50, 120, 0, 180)
    EVT_CALL(N(CosInterpMinMax), LVar0, LVar2, -32, 32, 120, 0, 30)
    EVT_ADD(LVar1, LVarA)
    EVT_ADD(LVar2, LVarC)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Run)
    EVT_CALL(SetNpcPos, NPC_Fuzzy_01, LVar1, LVarB, LVar2)
    EVT_SET(LVar3, LVarB)
    EVT_ADD(LVar3, 2)
    EVT_ADD(LVar0, 2)
    EVT_ADD(LVar2, 1)
    EVT_IF_EQ(LVar0, 240)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Koopa_02, LVar1, LVar3, LVar2)
    EVT_LABEL(1)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Fuzzy_01) = {
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
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_20, 1)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 25)
            EVT_ADD(LVar0, 40)
            EVT_ADD(LVar2, -40)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 15)
            EVT_ADD(LVar0, 30)
            EVT_ADD(LVar2, -30)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim09)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 13)
            EVT_ADD(LVar0, 20)
            EVT_ADD(LVar2, -20)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 11)
            EVT_ADD(LVar0, 10)
            EVT_ADD(LVar2, -10)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 9)
            EVT_ADD(LVar0, 80)
            EVT_ADD(LVar2, -80)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, 0, LVar2, 15)
            EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 15)
        EVT_LOOP(70)
            EVT_CALL(PlayerFaceNpc, NPC_Fuzzy_01, FALSE)
            EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_Fuzzy_01, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlayerFaceNpc, NPC_Koopa_02, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_Koopa_02, 0)
        EVT_THREAD
            EVT_CALL(AdjustCam, CAM_DEFAULT, 4, 0, EVT_FLOAT(-300.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_END_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Koopa_01, NPC_FLAG_100, TRUE)
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Happy)
        EVT_CALL(NpcJump0, NPC_Koopa_01, LVar0, 0, LVar2, 15)
        EVT_CALL(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Run)
        EVT_CALL(NpcMoveTo, NPC_Koopa_01, LVar0, LVar2, 15)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Idle)
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 10)
        EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, LVar1, LVar2, 10)
        EVT_CALL(PlayerFaceNpc, NPC_Koopa_01, FALSE)
        EVT_CALL(NpcFacePlayer, NPC_Koopa_01, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Still)
        EVT_CALL(EnableNpcBlur, NPC_Koopa_02, TRUE)
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 20)
        EVT_SET(LVar3, 2)
        EVT_SET(LVar4, 0)
        EVT_EXEC(N(D_80248F90_9CE370))
        EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
        EVT_CALL(NpcJump0, NPC_Koopa_02, LVar0, LVar1, LVar2, 30)
        EVT_CALL(SetNpcPos, NPC_Koopa_02, 0, -1000, 0)
        EVT_CALL(SetNpcSprite, NPC_Koopa_01, ANIM_Koopa_Idle)
        EVT_CALL(SetNpcFlagBits, NPC_Koopa_01, NPC_FLAG_100, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Still)
        EVT_WAIT(4)
        EVT_CALL(EnableNpcBlur, NPC_Koopa_02, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Idle)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Happy)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Idle)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0002)
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, 4)
        EVT_END_THREAD
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetEnemyFlagBits, NPC_Koopa_01, ENEMY_FLAG_400000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombomb_01_Crisis) = {
    EVT_IF_EQ(AF_NOK_0A, FALSE)
        EVT_SET(AF_NOK_0A, TRUE)
        EVT_SET(LVar0, MSG_CH1_003D)
    EVT_ELSE
        EVT_SET(AF_NOK_0A, FALSE)
        EVT_SET(LVar0, MSG_CH1_003E)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombomb_01_Crisis) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombomb_01_Crisis)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombomb_02_Crisis) = {
    EVT_IF_EQ(AF_NOK_0C, FALSE)
        EVT_SET(AF_NOK_0C, TRUE)
        EVT_SET(LVar0, MSG_CH1_0044)
    EVT_ELSE
        EVT_SET(AF_NOK_0C, FALSE)
        EVT_SET(LVar0, MSG_CH1_0045)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombomb_02_Crisis) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombomb_02_Crisis)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_01_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_01_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_01_Crisis)))
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

EvtScript N(EVS_NpcInit_Fuzzy_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy_01)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Fuzzy_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy_02)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Fuzzy_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_03) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy_03)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Fuzzy_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_02_Crisis) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaWithoutShell_01_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaWithoutShell_01_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoopaWithoutShell_01_Crisis)))
    EVT_CALL(SetNpcPos, NPC_KoopaWithoutShell_01, 40, 0, 325)
    EVT_CALL(InterpNpcYaw, NPC_KoopaWithoutShell_01, 180, 0)
    EVT_IF_EQ(GF_NOK01_RecoveredShellB, FALSE)
        EVT_CALL(SetNpcPos, NPC_Koopa_03, 22, 85, 375)
        EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell_01, ANIM_KoopaWithoutShell_CryRun)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_KoopaWithoutShell_01, ANIM_Koopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_03_Crisis) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaWithoutShell_02_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaWithoutShell_02_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoopaWithoutShell_02_Crisis)))
    EVT_IF_EQ(GF_NOK01_RecoveredShellC, FALSE)
        EVT_CALL(SetNpcPos, NPC_Koopa_04, 190, 114, 220)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_KoopaWithoutShell_02, ANIM_Koopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_04_Crisis) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_05_Crisis) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_05_Crisis)))
    EVT_CALL(SetNpcPos, NPC_Koopa_05, 333, 17, -162)
    EVT_CALL(InterpNpcYaw, NPC_Koopa_05, 180, 0)
    EVT_CALL(SetNpcAnimation, NPC_Koopa_05, ANIM_Koopa_LeanBack)
    EVT_RETURN
    EVT_END
};
