#include "world/common/todo/GetPlayerCoins.inc.c"

API_CALLABLE(N(GetCurrentStatMaxima)) {
    Bytecode* args = script->ptrReadPos;
    s32 out1 = *args++;
    s32 out2 = *args++;
    s32 out3 = *args++;

    evt_set_variable(script, out1, gPlayerData.hardMaxHP);
    evt_set_variable(script, out2, gPlayerData.hardMaxFP);
    evt_set_variable(script, out3, gPlayerData.maxBP);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustStatMaxima)) {
    PlayerData* playerData = &gPlayerData;
    s32 bp = 0;
    s32 fp = 0;
    s32 hp = 0;

    switch (script->varTable[10]) {
        case 0:
            hp = 10;
            fp = -5;
            bp = -3;
            break;
        case 1:
            hp = -5;
            fp = 10;
            bp = -3;
            break;
        case 2:
            hp = -5;
            fp = -5;
            bp = 6;
            break;
    }

    playerData->hardMaxHP += hp;
    playerData->curMaxHP += hp;
    if (playerData->curMaxHP > 75) {
        playerData->curMaxHP = 75;
    }
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    playerData->hardMaxFP += fp;
    playerData->curMaxFP += fp;
    if (playerData->curMaxFP > 75) {
        playerData->curMaxFP = 75;
    }
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    playerData->maxBP += bp;
    if (playerData->maxBP > 30) {
        playerData->maxBP = 30;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetCurrentStatValues)) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = playerData->curMaxHP;
    script->varTable[1] = playerData->curMaxFP;
    script->varTable[2] = playerData->maxBP;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetNpcShadowScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetStatusBarIgnoreChanges)) {
    status_bar_ignore_changes();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetStatusBarRespondToChanges)) {
    status_bar_respond_to_changes();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ForceStatusBarToAppear)) {
    status_bar_respond_to_changes();
    open_status_bar_slowly();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_ChetRippo) = {
    EVT_IF_EQ(GF_MAC04_Met_ChetRippo, FALSE)
        EVT_SET(LVar0, MSG_MAC_Housing_00A8)
        EVT_SET(GF_MAC04_Met_ChetRippo, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Housing_00A9)
    EVT_END_IF
    EVT_CALL(N(SetStatusBarIgnoreChanges))
    EVT_CALL(SpeakToPlayer, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, LVar0)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_000E)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AA)
        EVT_CALL(N(SetStatusBarRespondToChanges))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetPlayerCoins))
    EVT_IF_LT(LVar0, 39)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AB)
        EVT_CALL(N(SetStatusBarRespondToChanges))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetCurrentStatValues))
    EVT_CALL(SetMessageValue, LVar0, 0)
    EVT_CALL(SetMessageValue, LVar1, 1)
    EVT_CALL(SetMessageValue, LVar2, 2)
    EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AC)
    EVT_CALL(ShowChoice, MSG_Choice_000B)
    EVT_IF_EQ(LVar0, 3)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AD)
        EVT_CALL(N(SetStatusBarRespondToChanges))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar2, 0)
    EVT_CALL(N(GetCurrentStatMaxima), LVar3, LVar4, LVar5)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_GT(LVar3, 40)
                EVT_SET(LVar2, 1)
            EVT_END_IF
            EVT_SET(LVar1, MSG_Menus_00D1)
        EVT_CASE_EQ(1)
            EVT_IF_GT(LVar4, 40)
                EVT_SET(LVar2, 1)
            EVT_END_IF
            EVT_SET(LVar1, MSG_Menus_00D2)
        EVT_CASE_EQ(2)
            EVT_IF_GT(LVar5, 24)
                EVT_SET(LVar2, 1)
            EVT_END_IF
            EVT_SET(LVar1, MSG_Menus_00D3)
    EVT_END_SWITCH
    EVT_SET(LVarA, LVar0)
    EVT_IF_EQ(LVar2, 1)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00B1)
        EVT_CALL(N(SetStatusBarRespondToChanges))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AddCoin, -39)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(SetMessageText, LVar1, 0)
    EVT_CALL(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AE)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_Spread)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_ChetRippo, SOUND_MERLEE_APPEAR, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_ChetRippo, LVar6, LVar7, LVar8)
    EVT_ADD(LVar7, 26)
    EVT_PLAY_EFFECT(EFFECT_SHIMMER_BURST, 0, LVar6, LVar7, LVar8, 1, 60)
    EVT_CALL(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_ShakeSlow)
    EVT_WAIT(80)
    EVT_CALL(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_Idle)
    EVT_CALL(N(AdjustStatMaxima))
    EVT_CALL(N(EnforceNewStatLimits), LVar6)
    EVT_IF_EQ(LVar6, 0)
        EVT_SET(LVar7, MSG_MAC_Housing_00AF)
    EVT_ELSE
        EVT_SET(LVar7, MSG_MAC_Housing_00B0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, LVar7)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_ChetRippo, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, NPC_ChetRippo, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    EVT_CALL(SetNpcPos, NPC_ChetRippo, NPC_DISPOSE_LOCATION)
    EVT_SET(AF_MAC_32, TRUE)
    EVT_CALL(N(ForceStatusBarToAppear))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ChetRippo) = {
    EVT_IF_EQ(AF_MAC_32, FALSE)
        EVT_SET(LVar0, 0)
        EVT_CALL(N(GetCurrentStatMaxima), LVar1, LVar2, LVar3)
        EVT_IF_LE(LVar1, 5)
            EVT_SET(LVar0, 1)
        EVT_END_IF
        EVT_IF_LE(LVar2, 5)
            EVT_SET(LVar0, 1)
        EVT_END_IF
        EVT_IF_LE(LVar3, 3)
            EVT_SET(LVar0, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 38, 52)
        EVT_CALL(N(SetNpcShadowScale), -1, EVT_FLOAT(2.0))
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_DIRTY_SHADOW, TRUE)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ChetRippo)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
