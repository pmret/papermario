EvtScript N(EVS_NpcInteract_Bubulb) = {
    IfEq(GF_MAC02_Gift_MagicalSeed1, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_BuriedIdle, ANIM_Bubulb_Pink_BuriedIdle, 0, MSG_MAC_Bridge_0085)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_PopUp)
        Wait(45)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_Idle)
        Call(SetNpcCollisionSize, NPC_SELF, 45, 26)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_MAC_Bridge_0086)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED1)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_MAC_Bridge_0087)
        Set(GF_MAC02_Gift_MagicalSeed1, TRUE)
        Call(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Revealed)
    Else
        Switch(GB_StoryProgress)
            CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            CaseLt(STORY_CH2_BEGAN_PEACH_MISSION)
                Set(LVar0, MSG_MAC_Bridge_0088)
            CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
                Set(LVar0, MSG_MAC_Bridge_0089)
            CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
                Set(LVar0, MSG_MAC_Bridge_008A)
            CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
                Set(LVar0, MSG_MAC_Bridge_008B)
            CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
                Set(LVar0, MSG_MAC_Bridge_008C)
            CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
                Set(LVar0, MSG_MAC_Bridge_008D)
            CaseLt(STORY_EPILOGUE)
                Set(LVar0, MSG_MAC_Bridge_008E)
            CaseDefault
                Set(LVar0, MSG_MAC_Bridge_008E)
        EndSwitch
        Call(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, LVar0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb)))
    IfEq(GF_MAC02_Gift_MagicalSeed1, FALSE)
        Call(SetNpcCollisionSize, NPC_SELF, 25, 25)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_BuriedIdle)
        Call(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Hidden)
    EndIf
    Return
    End
};
