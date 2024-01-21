API_CALLABLE(N(CheckTradeEventTime)) {
    script->varTable[0] = (s32) ((gPlayerData.frameCounter - gPlayerData.tradeEventStartTime) / 3600) < script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetTradeEventItemCount)) {
    script->varTable[0] = get_item_count();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_TradingToad) = {
    Set(LVar0, 5)
    Call(N(CheckTradeEventTime))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_0119)
        Wait(10)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
        PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Set(GF_TradingEvent1_Active, FALSE)
        Return
    EndIf
    Call(N(GetTradeEventItemCount))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011A)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011B)
    EVT_CHOOSE_ANY_CONSUMABLE(24)
    Switch(LVar0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011F)
            Return
        CaseEq(ITEM_KOOPA_LEAF)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011C)
            EVT_GIVE_CONSUMABLE_REWARD(ITEM_MAPLE_SYRUP)
            Wait(10)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011D)
            Wait(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Set(GF_TradingEvent1_Active, FALSE)
            Add(GB_TradingEvent_Count, 1)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Pink_Talk, ANIM_Toad_Pink_Idle, 0, MSG_MAC_Gate_011E)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TradingToad) = {
    IfNe(GF_TradingEvent1_Active, FALSE)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_TradingToad)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};
