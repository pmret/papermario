EvtScript N(EVS_NpcInteract_CookingApprentice) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_004A)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_004B)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_004C)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MAC_Bridge_004D)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_004E)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC02_TayceT_HasCookbook, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_004F)
            EVT_ELSE
                EVT_SWITCH(GB_StoryProgress)
                    EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0050)
                    EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0051)
                    EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0052)
                    EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0053)
                    EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0054)
                    EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
                        EVT_SET(LVar0, MSG_MAC_Bridge_0055)
                EVT_END_SWITCH
            EVT_END_IF
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0056)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_CookingApprentice, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_CookingApprentice) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_CookingApprentice)))
    EVT_RETURN
    EVT_END
};
