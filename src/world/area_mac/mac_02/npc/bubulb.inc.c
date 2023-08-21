EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GF_MAC02_Gift_MagicalSeed1, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_BuriedIdle, ANIM_Bubulb_Pink_BuriedIdle, 0, MSG_MAC_Bridge_0085)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_PopUp)
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_Idle)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 26)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_MAC_Bridge_0086)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, MSG_MAC_Bridge_0087)
        EVT_SET(GF_MAC02_Gift_MagicalSeed1, TRUE)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Revealed)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CASE_LT(STORY_CH2_BEGAN_PEACH_MISSION)
                EVT_SET(LVar0, MSG_MAC_Bridge_0088)
            EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_MAC_Bridge_0089)
            EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008A)
            EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008B)
            EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008C)
            EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
                EVT_SET(LVar0, MSG_MAC_Bridge_008D)
            EVT_CASE_LT(STORY_EPILOGUE)
                EVT_SET(LVar0, MSG_MAC_Bridge_008E)
            EVT_CASE_DEFAULT
                EVT_SET(LVar0, MSG_MAC_Bridge_008E)
        EVT_END_SWITCH
        EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_IF_EQ(GF_MAC02_Gift_MagicalSeed1, FALSE)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 25, 25)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Pink_BuriedIdle)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_MAC_Bubulb_Hidden)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
