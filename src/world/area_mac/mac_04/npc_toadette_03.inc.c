EvtScript N(EVS_NpcInteract_Toadette_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Housing_0061)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_0062)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0063)
        EVT_CASE_LT(STORY_CH4_ENTERED_THE_TOY_BOX)
            EVT_SET(LVar0, MSG_MAC_Housing_0064)
        EVT_CASE_LT(STORY_CH4_GOT_STOREROOM_KEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0065)
        EVT_CASE_LT(STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0066)
        EVT_CASE_LT(STORY_CH4_GOT_FRYING_PAN)
            EVT_SET(LVar0, MSG_MAC_Housing_0067)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MAC_Housing_0068)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_CALL(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_IF_EQ(GF_MAC00_DictionaryReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Housing_0069)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Housing_006B)
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Housing_006A)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_006C)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Housing_006D)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_006E)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Housing_006F)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Housing_0070)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Housing_0071)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Housing_0072)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Housing_0073)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPIRIT_RESCUED, STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, -300, 0, 325)
    EVT_END_SWITCH
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_03)))
    EVT_RETURN
    EVT_END
};
