EvtScript N(EVS_NpcInteract_Toad_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Bridge_003A)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Bridge_003B)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_003C)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MAC_Bridge_003D)
            Else
                Set(LVar0, MSG_MAC_Bridge_003E)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_003F)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC01_MailbagStolen, FALSE)
                Set(LVar0, MSG_MAC_Bridge_0040)
            Else
                IfEq(GF_MAC01_MailbagReturned, FALSE)
                    Set(LVar0, MSG_MAC_Bridge_0041)
                Else
                    Set(LVar0, MSG_MAC_Bridge_0042)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Bridge_0043)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0044)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Bridge_0045)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Bridge_0046)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Bridge_0047)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Bridge_0048)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Bridge_0049)
    EndSwitch
    Call(SpeakToPlayer, NPC_Toad_01, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Toad_01) = {
    Call(SetNpcPos, NPC_SELF, 20, 0, -550)
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Walk)
        Call(NpcMoveTo, NPC_SELF, -20, -550, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
        Call(InterpNpcYaw, NPC_SELF, 90, 7)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 270, 7)
        Wait(30)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Walk)
        Call(NpcMoveTo, NPC_SELF, 20, -550, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
        Call(InterpNpcYaw, NPC_SELF, 270, 7)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 90, 7)
        Wait(30)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    IfLt(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Toad_01)))
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Return
    End
};
