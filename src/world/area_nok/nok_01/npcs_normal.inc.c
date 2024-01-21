EvtScript N(EVS_NpcInteract_Koover_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0003)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0004)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0005)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0006)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK11_Defeated_KentC, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0007)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0008)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0008)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_Koover1))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    ExecWait(N(EVS_LetterPrompt_Koover2))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_02_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0014)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0015)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0016)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK11_Defeated_KentC, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0017)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0018)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0018)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopa_03_Normal) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_03_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001C)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001E)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK11_Defeated_KentC, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_001F)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0020)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0020)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_01_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            IfEq(AF_NOK01_Dialogue_Bobomb_01, FALSE)
                Set(AF_NOK01_Dialogue_Bobomb_01, TRUE)
                Set(LVar0, MSG_CH1_003F)
            Else
                Set(AF_NOK01_Dialogue_Bobomb_01, FALSE)
                Set(LVar0, MSG_CH1_0040)
            EndIf
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0041)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0042)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(NpcFacePlayer, NPC_SELF, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0043)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
            Wait(10)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
            Wait(3)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
            Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_02_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            IfEq(AF_NOK01_Dialogue_Bobomb_02, FALSE)
                Set(AF_NOK01_Dialogue_Bobomb_02, TRUE)
                Set(LVar0, MSG_CH1_0046)
            Else
                Set(AF_NOK01_Dialogue_Bobomb_02, FALSE)
                Set(LVar0, MSG_CH1_0047)
            EndIf
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, LVar0)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(AF_NOK01_Dialogue_Bobomb_02, FALSE)
                Set(AF_NOK01_Dialogue_Bobomb_02, TRUE)
                Call(NpcFacePlayer, NPC_SELF, 0)
                Call(BringPartnerOut, PARTNER_BOMBETTE)
                Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0048)
                Call(DisablePartnerAI, 0)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_0049)
                Call(EnablePartnerAI)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004A)
                Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
                Wait(10)
                Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
                Wait(3)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                Wait(30)
                Call(PutPartnerAway)
            Else
                Call(NpcFacePlayer, NPC_SELF, 0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004B)
                Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
                Wait(10)
                Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
                Wait(3)
                Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
            EndIf
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(NpcFacePlayer, NPC_SELF, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004C)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
            Wait(10)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
            Wait(3)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
            Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(NpcFacePlayer, NPC_SELF, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004D)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
            Wait(10)
            Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
            Wait(3)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
            Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_03_Normal) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(AF_NOK_0E, FALSE)
                Set(AF_NOK_0E, TRUE)
                Call(NpcFacePlayer, NPC_SELF, 0)
                Call(NpcFacePlayer, NPC_Bobomb_01, 0)
                Call(NpcFacePlayer, NPC_Bobomb_02, 0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004E)
                Call(PlayerFaceNpc, NPC_Bobomb_01, FALSE)
                Call(SpeakToPlayer, NPC_Bobomb_01, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_004F)
                Call(PlayerFaceNpc, NPC_Bobomb_02, FALSE)
                Call(SpeakToPlayer, NPC_Bobomb_02, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0050)
                Thread
                    Call(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Red_Run)
                    Wait(10)
                    Call(SetNpcAnimation, NPC_Bobomb_02, ANIM_WorldBobomb_Red_Idle)
                    Wait(3)
                    Call(GetNpcPos, NPC_Bobomb_02, LVar0, LVar1, LVar2)
                    Call(PlaySoundAtNpc, NPC_Bobomb_02, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                    Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EndThread
                Wait(20)
                Thread
                    Call(PlayerFaceNpc, NPC_Bobomb_01, FALSE)
                    Call(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Red_Run)
                    Wait(10)
                    Call(SetNpcAnimation, NPC_Bobomb_01, ANIM_WorldBobomb_Red_Idle)
                    Wait(3)
                    Call(GetNpcPos, NPC_Bobomb_01, LVar0, LVar1, LVar2)
                    Call(PlaySoundAtNpc, NPC_Bobomb_01, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                    Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EndThread
                Wait(20)
                Thread
                    Call(PlayerFaceNpc, NPC_SELF, FALSE)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Run)
                    Wait(10)
                    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldBobomb_Red_Idle)
                    Wait(3)
                    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BOMBETTE_BLAST_LV1, SOUND_SPACE_DEFAULT)
                    Call(N(SpawnExplosionEffect), LVar0, LVar1, LVar2)
                EndThread
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0051)
            EndIf
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0052)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_0053)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koover_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koover_Normal)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_02_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_02_Normal)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_03_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_03_Normal)))
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopa_03_Normal)))
        Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Still)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_01_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_01_Normal)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_02_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_02_Normal)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_03_Normal) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_03_Normal)))
    IfLt(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};
