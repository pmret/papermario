EvtScript N(EVS_NpcInteract_GossipTrio) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0081)
                EVT_SET(LVar1, MSG_MAC_Housing_0082)
                EVT_SET(LVar2, MSG_MAC_Housing_0083)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0084)
                EVT_SET(LVar1, MSG_MAC_Housing_0085)
                EVT_SET(LVar2, MSG_MAC_Housing_0086)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0087)
            EVT_SET(LVar1, MSG_MAC_Housing_0088)
            EVT_SET(LVar2, MSG_MAC_Housing_0089)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_008A)
                EVT_SET(LVar1, MSG_MAC_Housing_008B)
                EVT_SET(LVar2, MSG_MAC_Housing_008C)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_008D)
                EVT_SET(LVar1, MSG_MAC_Housing_008E)
                EVT_SET(LVar2, MSG_MAC_Housing_008F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0090)
            EVT_SET(LVar1, MSG_MAC_Housing_0091)
            EVT_SET(LVar2, MSG_MAC_Housing_0092)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_0093)
            EVT_SET(LVar1, MSG_MAC_Housing_0094)
            EVT_SET(LVar2, MSG_MAC_Housing_0095)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0096)
            EVT_SET(LVar1, MSG_MAC_Housing_0097)
            EVT_SET(LVar2, MSG_MAC_Housing_0098)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_0099)
            EVT_SET(LVar1, MSG_MAC_Housing_009A)
            EVT_SET(LVar2, MSG_MAC_Housing_009B)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_009C)
            EVT_SET(LVar1, MSG_MAC_Housing_009D)
            EVT_SET(LVar2, MSG_MAC_Housing_009E)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_009F)
            EVT_SET(LVar1, MSG_MAC_Housing_00A0)
            EVT_SET(LVar2, MSG_MAC_Housing_00A1)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_00A2)
            EVT_SET(LVar1, MSG_MAC_Housing_00A3)
            EVT_SET(LVar2, MSG_MAC_Housing_00A4)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_00A5)
            EVT_SET(LVar1, MSG_MAC_Housing_00A6)
            EVT_SET(LVar2, MSG_MAC_Housing_00A7)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_GossipTrio1, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_GossipTrio2, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar1)
    EVT_CALL(SpeakToPlayer, NPC_GossipTrio3, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GossipTrio1) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GossipTrio)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GossipTrio2) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GossipTrio)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GossipTrio3) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GossipTrio)))
    EVT_RETURN
    EVT_END
};
