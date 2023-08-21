EvtScript N(EVS_NpcInteract_Koover_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0003)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0004)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0005)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0006)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0007)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0008)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0008)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Koover1))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Koover2))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_02_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0014)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0015)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0016)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0017)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0018)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0018)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopa_03_Normal) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_03_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001C)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001F)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0020)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0020)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_01_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_NOK01_Dialogue_Bobomb_01, FALSE)
                EVT_SET(AF_NOK01_Dialogue_Bobomb_01, TRUE)
                EVT_SET(LVar0, MSG_CH1_003F)
            EVT_ELSE
                EVT_SET(AF_NOK01_Dialogue_Bobomb_01, FALSE)
                EVT_SET(LVar0, MSG_CH1_0040)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0041)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0042)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0043)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
            EVT_WAIT(3)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
            EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_02_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_NOK01_Dialogue_Bobomb_02, FALSE)
                EVT_SET(AF_NOK01_Dialogue_Bobomb_02, TRUE)
                EVT_SET(LVar0, MSG_CH1_0046)
            EVT_ELSE
                EVT_SET(AF_NOK01_Dialogue_Bobomb_02, FALSE)
                EVT_SET(LVar0, MSG_CH1_0047)
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_NOK01_Dialogue_Bobomb_02, FALSE)
                EVT_SET(AF_NOK01_Dialogue_Bobomb_02, TRUE)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_CALL(BringPartnerOut, PARTNER_BOMBETTE)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0048)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_0049)
                EVT_CALL(EnablePartnerAI)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004A)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
                EVT_WAIT(3)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EVT_WAIT(30)
                EVT_CALL(PutPartnerAway)
            EVT_ELSE
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004B)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
                EVT_WAIT(10)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
                EVT_WAIT(3)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004C)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
            EVT_WAIT(3)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
            EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004D)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
            EVT_WAIT(3)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
            EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bobomb_03_Normal) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_NOK_0E, FALSE)
                EVT_SET(AF_NOK_0E, TRUE)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_CALL(NpcFacePlayer, NPC_Bobomb_01, 0)
                EVT_CALL(NpcFacePlayer, NPC_Bobomb_02, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004E)
                EVT_CALL(PlayerFaceNpc, NPC_Bobomb_01, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004F)
                EVT_CALL(PlayerFaceNpc, NPC_Bobomb_02, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_Bobomb_02, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0050)
                EVT_THREAD
                    EVT_CALL(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Red_Run)
                    EVT_WAIT(10)
                    EVT_CALL(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Red_Idle)
                    EVT_WAIT(3)
                    EVT_CALL(GetNpcPos, NPC_Bobomb_02, LVar0, LVar1, LVar2)
                    EVT_CALL(PlaySoundAtNpc, NPC_Bobomb_02, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                    EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EVT_END_THREAD
                EVT_WAIT(20)
                EVT_THREAD
                    EVT_CALL(PlayerFaceNpc, NPC_Bobomb_01, FALSE)
                    EVT_CALL(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Red_Run)
                    EVT_WAIT(10)
                    EVT_CALL(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Red_Idle)
                    EVT_WAIT(3)
                    EVT_CALL(GetNpcPos, NPC_Bobomb_01, LVar0, LVar1, LVar2)
                    EVT_CALL(PlaySoundAtNpc, NPC_Bobomb_01, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                    EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EVT_END_THREAD
                EVT_WAIT(20)
                EVT_THREAD
                    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
                    EVT_WAIT(10)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
                    EVT_WAIT(3)
                    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                    EVT_CALL(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0051)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0052)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0053)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koover_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koover_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_02_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_02_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_03_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_03_Normal)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_03_Normal)))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Still)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_01_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_01_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_02_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_02_Normal)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb_03_Normal) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bobomb_03_Normal)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
