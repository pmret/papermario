EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Bridge_003A)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MAC_Bridge_003B)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_003C)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_003D)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Bridge_003E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_003F)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_MAC01_MailbagStolen, FALSE)
                EVT_SET(LVar0, MSG_MAC_Bridge_0040)
            EVT_ELSE
                EVT_IF_EQ(GF_MAC01_MailbagReturned, FALSE)
                    EVT_SET(LVar0, MSG_MAC_Bridge_0041)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MAC_Bridge_0042)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0043)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0044)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MAC_Bridge_0045)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0046)
        EVT_CASE_LT(STORY_CH7_INVITED_TO_STARBORN_VALLEY)
            EVT_SET(LVar0, MSG_MAC_Bridge_0047)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Bridge_0048)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Bridge_0049)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Toad_01) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 20, 0, -550)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, -20, -550, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, 20, -550, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(30)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Toad_01)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_RETURN
    EVT_END
};
