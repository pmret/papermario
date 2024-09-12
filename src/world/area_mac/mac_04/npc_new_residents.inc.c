EvtScript N(EVS_NpcInteract_NewResident1) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Housing_00D4)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Housing_00D5)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_00D6)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Housing_0006)
            Else
                Set(LVar0, MSG_MAC_Housing_0007)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0008)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Housing_0009)
            Else
                Set(LVar0, MSG_MAC_Housing_000A)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_000B)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Housing_000C)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_000D)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Housing_000E)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_000F)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Housing_0010)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0011)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Housing_0012)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Green_Talk, ANIM_Toadette_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_NewResident1) = {
    Set(AF_MAC_2D, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_NewResident1)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_NewResident2) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Housing_00D7)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Housing_00D8)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_00D9)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Housing_0013)
            Else
                Set(LVar0, MSG_MAC_Housing_0014)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0015)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Housing_0016)
            Else
                Set(LVar0, MSG_MAC_Housing_0017)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0018)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Housing_0019)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_001A)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Housing_001B)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_001C)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Housing_001D)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_001E)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Housing_001F)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Purple_Talk, ANIM_Toadette_Purple_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_NewResident2) = {
    Set(AF_MAC_2E, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_NewResident2)))
    Return
    End
};
