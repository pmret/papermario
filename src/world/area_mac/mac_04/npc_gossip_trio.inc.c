EvtScript N(EVS_NpcInteract_GossipTrio) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Housing_00EF)
            Set(LVar1, MSG_MAC_Housing_00F0)
            Set(LVar2, MSG_MAC_Housing_00F1)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Housing_00F2)
            Set(LVar1, MSG_MAC_Housing_00F3)
            Set(LVar2, MSG_MAC_Housing_00F4)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_00F5)
            Set(LVar1, MSG_MAC_Housing_00F6)
            Set(LVar2, MSG_MAC_Housing_00F7)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Housing_0081)
                Set(LVar1, MSG_MAC_Housing_0082)
                Set(LVar2, MSG_MAC_Housing_0083)
            Else
                Set(LVar0, MSG_MAC_Housing_0084)
                Set(LVar1, MSG_MAC_Housing_0085)
                Set(LVar2, MSG_MAC_Housing_0086)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0087)
            Set(LVar1, MSG_MAC_Housing_0088)
            Set(LVar2, MSG_MAC_Housing_0089)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, false)
                Set(LVar0, MSG_MAC_Housing_008A)
                Set(LVar1, MSG_MAC_Housing_008B)
                Set(LVar2, MSG_MAC_Housing_008C)
            Else
                Set(LVar0, MSG_MAC_Housing_008D)
                Set(LVar1, MSG_MAC_Housing_008E)
                Set(LVar2, MSG_MAC_Housing_008F)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0090)
            Set(LVar1, MSG_MAC_Housing_0091)
            Set(LVar2, MSG_MAC_Housing_0092)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Housing_0093)
            Set(LVar1, MSG_MAC_Housing_0094)
            Set(LVar2, MSG_MAC_Housing_0095)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0096)
            Set(LVar1, MSG_MAC_Housing_0097)
            Set(LVar2, MSG_MAC_Housing_0098)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Housing_0099)
            Set(LVar1, MSG_MAC_Housing_009A)
            Set(LVar2, MSG_MAC_Housing_009B)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_009C)
            Set(LVar1, MSG_MAC_Housing_009D)
            Set(LVar2, MSG_MAC_Housing_009E)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Housing_009F)
            Set(LVar1, MSG_MAC_Housing_00A0)
            Set(LVar2, MSG_MAC_Housing_00A1)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_00A2)
            Set(LVar1, MSG_MAC_Housing_00A3)
            Set(LVar2, MSG_MAC_Housing_00A4)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Housing_00A5)
            Set(LVar1, MSG_MAC_Housing_00A6)
            Set(LVar2, MSG_MAC_Housing_00A7)
    EndSwitch
    Call(SpeakToPlayer, NPC_GossipTrio1, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Call(SpeakToPlayer, NPC_GossipTrio2, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, LVar1)
    Call(SpeakToPlayer, NPC_GossipTrio3, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, LVar2)
    Return
    End
};

EvtScript N(EVS_NpcInit_GossipTrio1) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GossipTrio)))
    Return
    End
};

EvtScript N(EVS_NpcInit_GossipTrio2) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GossipTrio)))
    Return
    End
};

EvtScript N(EVS_NpcInit_GossipTrio3) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GossipTrio)))
    Return
    End
};
