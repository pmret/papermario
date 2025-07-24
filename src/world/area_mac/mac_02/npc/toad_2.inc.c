EvtScript N(EVS_NpcInteract_Toad_02) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Bridge_009B)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Bridge_009C)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_009D)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Bridge_0057)
            Else
                Set(LVar0, MSG_MAC_Bridge_0058)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_0059)
        CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_005A)
        CaseLt(STORY_CH4_GOT_TAYCE_TS_CAKE)
            Set(LVar0, MSG_MAC_Bridge_005B)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_005C)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Bridge_005D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_005E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Bridge_005F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_0060)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Bridge_0061)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0062)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Bridge_0063)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_02, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
    Return
    End
};
