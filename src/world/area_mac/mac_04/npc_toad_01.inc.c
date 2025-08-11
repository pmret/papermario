EvtScript N(EVS_NpcInteract_Toad_01) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Housing_00DA)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Housing_00DB)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_00DC)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Housing_0020)
            Else
                Set(LVar0, MSG_MAC_Housing_0021)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0022)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, false)
                Set(LVar0, MSG_MAC_Housing_0023)
            Else
                Set(LVar0, MSG_MAC_Housing_0024)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0025)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Housing_0026)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0027)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Housing_0028)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0029)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Housing_002A)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_002B)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Housing_002C)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Return
    End
};
