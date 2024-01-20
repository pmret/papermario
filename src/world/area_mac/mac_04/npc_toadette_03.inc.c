EvtScript N(EVS_NpcInteract_Toadette_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Housing_0061)
            Else
                Set(LVar0, MSG_MAC_Housing_0062)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0063)
        CaseLt(STORY_CH4_ENTERED_THE_TOY_BOX)
            Set(LVar0, MSG_MAC_Housing_0064)
        CaseLt(STORY_CH4_GOT_STOREROOM_KEY)
            Set(LVar0, MSG_MAC_Housing_0065)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            Set(LVar0, MSG_MAC_Housing_0066)
        CaseLt(STORY_CH4_GOT_FRYING_PAN)
            Set(LVar0, MSG_MAC_Housing_0067)
        CaseLt(STORY_CH4_GOT_TAYCE_TS_CAKE)
            Set(LVar0, MSG_MAC_Housing_0068)
        CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
            Call(FindKeyItem, ITEM_MYSTERY_NOTE, LVar0)
            IfEq(LVar0, -1)
                IfEq(GF_MAC00_DictionaryReturned, FALSE)
                    Set(LVar0, MSG_MAC_Housing_0069)
                Else
                    Set(LVar0, MSG_MAC_Housing_006B)
                EndIf
            Else
                Set(LVar0, MSG_MAC_Housing_006A)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_006C)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Housing_006D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_006E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Housing_006F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0070)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Housing_0071)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0072)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Housing_0073)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_03) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPIRIT_RESCUED, STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, -300, 0, 325)
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_03)))
    Return
    End
};
