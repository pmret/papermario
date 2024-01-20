EvtScript N(EVS_NpcInteract_Goomama) = {
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_GOOMBARIO)
        Call(DisablePartnerAI, 1)
        IfEq(GF_MAC04_HeardGoombaFamilyArgument, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B6)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00B7)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B8)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00B9)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00BA)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00BB)
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00BC)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00BD)
            Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00BE)
            Set(GF_MAC04_HeardGoombaFamilyArgument, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00BF)
        EndIf
        Call(EnablePartnerAI)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B5)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goombaria) = {
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_GOOMBARIO)
        Call(DisablePartnerAI, 1)
        IfEq(AF_MAC_30, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C1)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00C2)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C3)
            Set(AF_MAC_30, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C4)
        EndIf
        Call(EnablePartnerAI)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Goomama) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goomama)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Goombaria)))
    Return
    End
};
