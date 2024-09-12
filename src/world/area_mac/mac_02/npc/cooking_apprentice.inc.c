EvtScript N(EVS_NpcInteract_CookingApprentice) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Bridge_0097)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Bridge_0098)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0099)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Bridge_004A)
            Else
                Set(LVar0, MSG_MAC_Bridge_004B)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_004C)
#if VERSION_JP
        CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_009A)
#endif
        CaseLt(STORY_CH4_GOT_TAYCE_TS_CAKE)
            Set(LVar0, MSG_MAC_Bridge_004D)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_004E)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC02_TayceT_HasCookbook, FALSE)
                Set(LVar0, MSG_MAC_Bridge_004F)
            Else
                Switch(GB_StoryProgress)
                    CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
                        Set(LVar0, MSG_MAC_Bridge_0050)
                    CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
                        Set(LVar0, MSG_MAC_Bridge_0051)
                    CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
                        Set(LVar0, MSG_MAC_Bridge_0052)
                    CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
                        Set(LVar0, MSG_MAC_Bridge_0053)
                    CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
                        Set(LVar0, MSG_MAC_Bridge_0054)
                    CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
                        Set(LVar0, MSG_MAC_Bridge_0055)
                EndSwitch
            EndIf
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Bridge_0056)
    EndSwitch
    Call(SpeakToPlayer, NPC_CookingApprentice, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_CookingApprentice) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_CookingApprentice)))
    Return
    End
};
