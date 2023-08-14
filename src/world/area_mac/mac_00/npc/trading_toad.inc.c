API_CALLABLE(N(CheckTradeEventTime)) {
    script->varTable[0] = (s32) ((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTradeEventItemCount)) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_TradingToad) = {
    EVT_SET(LVar0, 5)
    EVT_CALL(N(CheckTradeEventTime))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_0119)
        EVT_WAIT(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
        EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_SET(GF_TradingEvent1_Active, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetTradeEventItemCount))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011A)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011B)
    EVT_CHOOSE_ANY_CONSUMABLE(24)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011F)
            EVT_RETURN
        EVT_CASE_EQ(ITEM_KOOPA_LEAF)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011C)
            EVT_GIVE_CONSUMABLE_REWARD(ITEM_MAPLE_SYRUP)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011D)
            EVT_WAIT(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_SET(GF_TradingEvent1_Active, FALSE)
            EVT_ADD(GB_TradingEvent_Count, 1)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011E)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TradingToad) = {
    EVT_IF_NE(GF_TradingEvent1_Active, FALSE)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_TradingToad)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
