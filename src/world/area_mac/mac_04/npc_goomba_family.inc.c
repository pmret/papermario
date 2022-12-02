EvtScript N(EVS_NpcInteract_Goomama) = {
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_GOOMBARIO)
        EVT_CALL(DisablePartnerAI, 1)
        EVT_IF_EQ(GF_MAC04_HeardGoombaFamilyArgument, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B6)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00B7)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B8)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00B9)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00BA)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00BB)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00BC)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00BD)
            EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00BE)
            EVT_SET(GF_MAC04_HeardGoombaFamilyArgument, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00BF)
        EVT_END_IF
        EVT_CALL(EnablePartnerAI)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goomama_Talk, ANIM_Goomama_Idle, 0, MSG_MAC_Housing_00B5)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Goombaria) = {
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_GOOMBARIO)
        EVT_CALL(DisablePartnerAI, 1)
        EVT_IF_EQ(AF_MAC_30, FALSE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C1)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_MAC_Housing_00C2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C3)
            EVT_SET(AF_MAC_30, TRUE)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C4)
        EVT_END_IF
        EVT_CALL(EnablePartnerAI)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_MAC_Housing_00C0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomama) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goomama)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Goombaria)))
    EVT_RETURN
    EVT_END
};
