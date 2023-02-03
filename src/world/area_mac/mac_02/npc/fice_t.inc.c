s32 N(LetterList_FiceT)[] = {
    ITEM_LETTER_TO_FICE_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_FiceT) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle,
        ITEM_LETTER_TO_FICE_T, ITEM_NONE,
        MSG_MAC_Bridge_0036, MSG_MAC_Bridge_0037, MSG_MAC_Bridge_0038, 0,
        EVT_PTR(N(LetterList_FiceT)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_FiceT) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle, 0, MSG_MAC_Bridge_0039)
        EVT_CALL(SetNpcAnimation, NPC_FiceT, ANIM_FiceT_Afraid)
        EVT_CALL(EndSpeech, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0)
        EVT_GIVE_STAR_PIECE()
        EVT_CALL(SetNpcAnimation, NPC_FiceT, ANIM_FiceT_Idle)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FiceT) = {
    EVT_SET(LVar3, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0021)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar3, 1)
            EVT_SET(LVar0, MSG_MAC_Bridge_002A)
            EVT_SET(LVar1, MSG_MAC_Bridge_002B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_002C)
            EVT_SET(LVar1, MSG_MAC_Bridge_002D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_002E)
            EVT_SET(LVar1, MSG_MAC_Bridge_002F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0030)
            EVT_SET(LVar1, MSG_MAC_Bridge_0031)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0032)
            EVT_SET(LVar1, MSG_MAC_Bridge_0033)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0034)
            EVT_SET(LVar1, MSG_MAC_Bridge_0035)
    EVT_END_SWITCH
    EVT_CALL(GetCurrentPartnerID, LVar2)
    EVT_IF_EQ(LVar2, PARTNER_BOW)
        EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar1)
    EVT_ELSE
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Talk, ANIM_FiceT_Idle, 0, LVar0)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_FiceT, ANIM_FiceT_Afraid, ANIM_FiceT_Afraid, 0, LVar0)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_FiceT))
    EVT_EXEC_WAIT(N(EVS_LetterReward_FiceT))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FiceT) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_FiceT_Afraid)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 390, 0, -50)
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FiceT)))
    EVT_RETURN
    EVT_END
};
