s32 N(LetterList_FiceT)[] = {
    ITEM_LETTER_TO_FICE_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_FiceT) = {
    Call(N(LetterDelivery_Init),
        NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle,
        ITEM_LETTER_TO_FICE_T, ITEM_NONE,
        MSG_MAC_Bridge_0036, MSG_MAC_Bridge_0037, MSG_MAC_Bridge_0038, 0,
        Ref(N(LetterList_FiceT)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_FiceT) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle, 0, MSG_MAC_Bridge_0039)
        Call(SetNpcAnimation, NPC_FiceT, ANIM_FiceT_Afraid)
        Call(EndSpeech, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0)
        EVT_GIVE_STAR_PIECE()
        Call(SetNpcAnimation, NPC_FiceT, ANIM_FiceT_Idle)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_FiceT) = {
    Set(LVar3, 0)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0021)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar3, 1)
            Set(LVar0, MSG_MAC_Bridge_002A)
            Set(LVar1, MSG_MAC_Bridge_002B)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_002C)
            Set(LVar1, MSG_MAC_Bridge_002D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_002E)
            Set(LVar1, MSG_MAC_Bridge_002F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_0030)
            Set(LVar1, MSG_MAC_Bridge_0031)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0032)
            Set(LVar1, MSG_MAC_Bridge_0033)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Bridge_0034)
            Set(LVar1, MSG_MAC_Bridge_0035)
    EndSwitch
    Call(GetCurrentPartnerID, LVar2)
    IfEq(LVar2, PARTNER_BOW)
        Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar1)
    Else
        IfEq(LVar3, 0)
            Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle, 0, LVar0)
        Else
            Call(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar0)
        EndIf
    EndIf
    ExecWait(N(EVS_LetterPrompt_FiceT))
    ExecWait(N(EVS_LetterReward_FiceT))
    IfNe(LVarC, DELIVERY_NOT_POSSIBLE)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_FiceT) = {
    IfEq(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        Call(SetNpcAnimation, NPC_SELF, ANIM_FiceT_Afraid)
    Else
        Call(SetNpcPos, NPC_SELF, 390, 0, -50)
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_FiceT)))
    Return
    End
};
