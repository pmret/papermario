EvtScript N(EVS_NpcInteract_WaterfrontDad) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_0044)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0045)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0046)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Gate_0047)
            Else
                Set(LVar0, MSG_MAC_Gate_0048)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0049)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, false)
                Set(LVar0, MSG_MAC_Gate_004A)
            Else
                IfEq(GF_MAC00_DictionaryReturned, false)
                    Set(LVar0, MSG_MAC_Gate_004B)
                Else
                    Set(LVar0, MSG_MAC_Gate_004C)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_004D)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_004E)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_004F)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0050)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_0051)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0052)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_0053)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0036)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_WaterfrontMom) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_0054)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0055)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0056)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Gate_0057)
            Else
                Set(LVar0, MSG_MAC_Gate_0058)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0059)
#if VERSION_JP
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, false)
                Set(LVar0, MSG_MAC_Gate_0123)
            Else
                IfEq(GF_MAC00_DictionaryReturned, false)
                    Set(LVar0, MSG_MAC_Gate_0124)
                Else
                    Set(LVar0, MSG_MAC_Gate_0125)
                EndIf
            EndIf
#endif
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_005A)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_005B)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_005C)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_005D)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_005E)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_005F)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_0060)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0037)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toadette_Orange_Talk, ANIM_Toadette_Orange_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_WaterfrontKid1) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_0061)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0062)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0063)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Gate_0064)
            Else
                Set(LVar0, MSG_MAC_Gate_0065)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0066)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, false)
                Set(LVar0, MSG_MAC_Gate_0067)
            Else
                IfEq(GF_MAC00_DictionaryReturned, false)
                    Set(LVar0, MSG_MAC_Gate_0068)
                Else
                    Set(LVar0, MSG_MAC_Gate_0069)
                EndIf
            EndIf
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_006A)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_006B)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_006C)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_006D)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_006E)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_006F)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_0070)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0038)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_WaterfrontKid2) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Gate_0071)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MAC_Gate_0072)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0073)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC03_BombedRock, false)
                Set(LVar0, MSG_MAC_Gate_0074)
            Else
                Set(LVar0, MSG_MAC_Gate_0075)
            EndIf
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_0076)
#if VERSION_JP
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, false)
                Set(LVar0, MSG_MAC_Gate_0126)
            Else
                IfEq(GF_MAC00_DictionaryReturned, false)
                    Set(LVar0, MSG_MAC_Gate_0127)
                Else
                    Set(LVar0, MSG_MAC_Gate_0128)
                EndIf
            EndIf
#endif
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MAC_Gate_0077)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_0078)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MAC_Gate_0079)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MAC_Gate_007A)
        CaseLt(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            Set(LVar0, MSG_MAC_Gate_007B)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Gate_007C)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Gate_007D)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0039)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_WaterfrontDad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_WaterfrontDad)))
    Return
    End
};

EvtScript N(EVS_NpcInit_WaterfrontMom) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_WaterfrontMom)))
    Return
    End
};

EvtScript N(EVS_NpcInit_WaterfrontKid1) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_WaterfrontKid1)))
    Return
    End
};

EvtScript N(EVS_NpcInit_WaterfrontKid2) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_WaterfrontKid2)))
    Return
    End
};

EvtScript N(EVS_WaterfrontHouse_DoorLocked) = {
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfGe(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            IfEq(GF_MAC00_DictionaryStolen, false)
                Set(LVar0, MSG_MAC_Gate_004A)
                Set(LVar1, MSG_MAC_Gate_0067)
            Else
                IfEq(GF_MAC00_DictionaryReturned, false)
                    Set(LVar0, MSG_MAC_Gate_004B)
                    Set(LVar1, MSG_MAC_Gate_0068)
                Else
                    Set(LVar0, MSG_MAC_Gate_004C)
                    Set(LVar1, MSG_MAC_Gate_0069)
                EndIf
            EndIf
    EndSwitch
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, LVar0, 160, 40)
    Wait(5)
    Call(ShowMessageAtScreenPos, LVar1, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};
