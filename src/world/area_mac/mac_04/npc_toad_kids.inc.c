EvtScript N(EVS_NpcInteract_ToadKids) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_003A)
                EVT_SET(LVar1, MSG_MAC_Housing_003B)
                EVT_SET(LVar2, MSG_MAC_Housing_003C)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_003D)
                EVT_SET(LVar1, MSG_MAC_Housing_003E)
                EVT_SET(LVar2, MSG_MAC_Housing_003F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0040)
            EVT_SET(LVar1, MSG_MAC_Housing_0041)
            EVT_SET(LVar2, MSG_MAC_Housing_0042)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_IF_EQ(GF_MAC04_StoreroomKeyStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0043)
                EVT_SET(LVar1, MSG_MAC_Housing_0044)
                EVT_SET(LVar2, MSG_MAC_Housing_0045)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0046)
                EVT_SET(LVar1, MSG_MAC_Housing_0047)
                EVT_SET(LVar2, MSG_MAC_Housing_0048)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0049)
            EVT_SET(LVar1, MSG_MAC_Housing_004A)
            EVT_SET(LVar2, MSG_MAC_Housing_004B)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_004C)
            EVT_SET(LVar1, MSG_MAC_Housing_004D)
            EVT_SET(LVar2, MSG_MAC_Housing_004E)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_004F)
            EVT_SET(LVar1, MSG_MAC_Housing_0050)
            EVT_SET(LVar2, MSG_MAC_Housing_0051)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_0052)
            EVT_SET(LVar1, MSG_MAC_Housing_0053)
            EVT_SET(LVar2, MSG_MAC_Housing_0054)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0055)
            EVT_SET(LVar1, MSG_MAC_Housing_0056)
            EVT_SET(LVar2, MSG_MAC_Housing_0057)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0058)
            EVT_SET(LVar1, MSG_MAC_Housing_0059)
            EVT_SET(LVar2, MSG_MAC_Housing_005A)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_005B)
            EVT_SET(LVar1, MSG_MAC_Housing_005C)
            EVT_SET(LVar2, MSG_MAC_Housing_005D)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_005E)
            EVT_SET(LVar1, MSG_MAC_Housing_005F)
            EVT_SET(LVar2, MSG_MAC_Housing_0060)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_01, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle, 0, LVar0)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar1)
    EVT_CALL(SpeakToPlayer, NPC_ToadKid_03, ANIM_ToadKid_Green_Talk, ANIM_ToadKid_Green_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKids)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKids)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadKid_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadKids)))
    EVT_RETURN
    EVT_END
};
