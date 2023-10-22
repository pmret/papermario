s32 N(ItemList_StoreroomKey)[] = {
    ITEM_STOREROOM_KEY,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_HarryT) = {
    EVT_SET(LVar9, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_SET(LVar9, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar9, 1)
        EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0001)
        EVT_SET(LVar0, EVT_PTR(N(ItemList_StoreroomKey)))
        EVT_SET(LVar1, 0)
        EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(-1)
                EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0002)
            EVT_CASE_EQ(0)
            EVT_CASE_DEFAULT
                EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0003)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Run)
                EVT_CALL(NpcMoveTo, NPC_HarryT, 295, -460, 0)
                EVT_CALL(NpcMoveTo, NPC_HarryT, 230, -480, 0)
                EVT_CALL(NpcJump0, NPC_HarryT, 198, 30, -480, 0)
                EVT_CALL(NpcJump0, NPC_HarryT, 162, 40, -480, 0)
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
                EVT_WAIT(20)
                EVT_EXEC(N(EVS_ForceStoreroomUnlock))
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Run)
                EVT_CALL(NpcMoveTo, NPC_HarryT, 200, -524, 0)
                EVT_CALL(SetNpcPos, NPC_HarryT, 200, 30, -524)
                EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
                EVT_CALL(InterpNpcYaw, NPC_HarryT, 180, 0)
                EVT_CALL(PlayerFaceNpc, NPC_HarryT, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_HarryT, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Housing_0005)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, FALSE)
                EVT_SET(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HarryT) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_HarryT)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_STAR_SPRIT_DEPARTED)
        EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_STOREROOM_KEY)
            EVT_CALL(SetNpcAnimation, NPC_HarryT, ANIM_HarryT_Idle)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
