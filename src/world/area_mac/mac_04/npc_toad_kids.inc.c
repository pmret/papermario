EvtScript N(EVS_NpcInteract_ToadKids) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Housing_00E0)
            Set(LVar1, MSG_MAC_Housing_00E1)
            Set(LVar2, MSG_MAC_Housing_00E2)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Housing_00E3)
            Set(LVar1, MSG_MAC_Housing_00E4)
            Set(LVar2, MSG_MAC_Housing_00E5)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_00E6)
            Set(LVar1, MSG_MAC_Housing_00E7)
            Set(LVar2, MSG_MAC_Housing_00E8)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Housing_003A)
                Set(LVar1, MSG_MAC_Housing_003B)
                Set(LVar2, MSG_MAC_Housing_003C)
            Else
                Set(LVar0, MSG_MAC_Housing_003D)
                Set(LVar1, MSG_MAC_Housing_003E)
                Set(LVar2, MSG_MAC_Housing_003F)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0040)
            Set(LVar1, MSG_MAC_Housing_0041)
            Set(LVar2, MSG_MAC_Housing_0042)
        CaseLt(STORY_CH4_RETURNED_STOREROOM_KEY)
            IfEq(GF_MAC04_StoreroomKeyStolen, FALSE)
                Set(LVar0, MSG_MAC_Housing_0043)
                Set(LVar1, MSG_MAC_Housing_0044)
                Set(LVar2, MSG_MAC_Housing_0045)
            Else
                Set(LVar0, MSG_MAC_Housing_0046)
                Set(LVar1, MSG_MAC_Housing_0047)
                Set(LVar2, MSG_MAC_Housing_0048)
            EndIf
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_0049)
            Set(LVar1, MSG_MAC_Housing_004A)
            Set(LVar2, MSG_MAC_Housing_004B)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Housing_004C)
            Set(LVar1, MSG_MAC_Housing_004D)
            Set(LVar2, MSG_MAC_Housing_004E)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_004F)
            Set(LVar1, MSG_MAC_Housing_0050)
            Set(LVar2, MSG_MAC_Housing_0051)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Housing_0052)
            Set(LVar1, MSG_MAC_Housing_0053)
            Set(LVar2, MSG_MAC_Housing_0054)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Housing_0055)
            Set(LVar1, MSG_MAC_Housing_0056)
            Set(LVar2, MSG_MAC_Housing_0057)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Housing_0058)
            Set(LVar1, MSG_MAC_Housing_0059)
            Set(LVar2, MSG_MAC_Housing_005A)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Housing_005B)
            Set(LVar1, MSG_MAC_Housing_005C)
            Set(LVar2, MSG_MAC_Housing_005D)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Housing_005E)
            Set(LVar1, MSG_MAC_Housing_005F)
            Set(LVar2, MSG_MAC_Housing_0060)
    EndSwitch
    Call(SpeakToPlayer, NPC_ToadKid_01, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Idle, 0, LVar0)
    Call(SpeakToPlayer, NPC_ToadKid_02, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar1)
    Call(SpeakToPlayer, NPC_ToadKid_03, ANIM_ToadKid_Green_Talk, ANIM_ToadKid_Green_Idle, 0, LVar2)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadKid_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadKids)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadKid_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadKids)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadKid_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadKids)))
    Return
    End
};
