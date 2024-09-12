EvtScript N(EVS_NpcInteract_ToadKid) = {
    Switch(GB_StoryProgress)
#if VERSION_JP
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Bridge_009E)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_009F)
#endif
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0064)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_0065)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0066)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0067)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_0068)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0069)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Bridge_006A)
    EndSwitch
    Call(SpeakToPlayer, NPC_ToadKid, ANIM_ToadKid_Yellow_Talk, ANIM_ToadKid_Yellow_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadKid) = {
    IfLt(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        Call(RemoveNpc, NPC_SELF)
    Else
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadKid)))
    EndIf
    Return
    End
};
