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
    IfEq(GF_MAC04_Met_ChetRippo, FALSE)
        Set(LVar0, MSG_MAC_Housing_00A8)
        Set(GF_MAC04_Met_ChetRippo, TRUE)
    Else
        Set(LVar0, MSG_MAC_Housing_00A9)
    EndIf
    Call(N(SetStatusBarIgnoreChanges))
    Call(SpeakToPlayer, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, LVar0)
    Call(ShowCoinCounter, TRUE)
    Call(ShowChoice, MSG_Choice_000E)
    IfNe(LVar0, 0)
        Call(ShowCoinCounter, FALSE)
        Call(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AA)
        Call(N(SetStatusBarRespondToChanges))
        Return
    EndIf
    Call(N(GetPlayerCoins))
    IfLt(LVar0, 39)
        Call(ShowCoinCounter, FALSE)
        Call(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AB)
        Call(N(SetStatusBarRespondToChanges))
        Return
    EndIf
    Call(N(GetCurrentStatValues))
    Call(SetMessageValue, LVar0, 0)
    Call(SetMessageValue, LVar1, 1)
    Call(SetMessageValue, LVar2, 2)
    Call(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AC)
    Call(ShowChoice, MSG_Choice_000B)
    IfEq(LVar0, 3)
        Call(ShowCoinCounter, FALSE)
        Call(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AD)
        Call(N(SetStatusBarRespondToChanges))
        Return
    EndIf
    Set(LVar2, 0)
    Call(N(GetCurrentStatMaxima), LVar3, LVar4, LVar5)
    Switch(LVar0)
        CaseEq(0)
            IfGt(LVar3, 40)
                Set(LVar2, 1)
            EndIf
            Set(LVar1, MSG_Menus_00D1)
        CaseEq(1)
            IfGt(LVar4, 40)
                Set(LVar2, 1)
            EndIf
            Set(LVar1, MSG_Menus_00D2)
        CaseEq(2)
            IfGt(LVar5, 24)
                Set(LVar2, 1)
            EndIf
            Set(LVar1, MSG_Menus_00D3)
    EndSwitch
    Set(LVarA, LVar0)
    IfEq(LVar2, 1)
        Call(ShowCoinCounter, FALSE)
        Call(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00B1)
        Call(N(SetStatusBarRespondToChanges))
        Return
    EndIf
    Call(AddCoin, -39)
    Call(ShowCoinCounter, FALSE)
    Call(SetMessageText, LVar1, 0)
    Call(ContinueSpeech, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, MSG_MAC_Housing_00AE)
    Wait(10)
    Call(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_Spread)
    Wait(10)
    Call(PlaySoundAtNpc, NPC_ChetRippo, SOUND_MERLEE_APPEAR, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_ChetRippo, LVar6, LVar7, LVar8)
    Add(LVar7, 26)
    PlayEffect(EFFECT_SHIMMER_BURST, 0, LVar6, LVar7, LVar8, 1, 60)
    Call(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_ShakeSlow)
    Wait(80)
    Call(SetNpcAnimation, NPC_ChetRippo, ANIM_ChetRippo_Idle)
    Call(N(AdjustStatMaxima))
    Call(N(EnforceNewStatLimits), LVar6)
    IfEq(LVar6, 0)
        Set(LVar7, MSG_MAC_Housing_00AF)
    Else
        Set(LVar7, MSG_MAC_Housing_00B0)
    EndIf
    Call(SpeakToPlayer, NPC_ChetRippo, ANIM_ChetRippo_Talk, ANIM_ChetRippo_Idle, 0, LVar7)
    Wait(10)
    Call(GetNpcPos, NPC_ChetRippo, LVar0, LVar1, LVar2)
    Call(PlaySoundAtNpc, NPC_ChetRippo, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1)
    Call(SetNpcPos, NPC_ChetRippo, NPC_DISPOSE_LOCATION)
    Set(AF_MAC_32, TRUE)
    Call(N(ForceStatusBarToAppear))
    Return
    End
};

EvtScript N(EVS_NpcInit_ChetRippo) = {
    IfEq(AF_MAC_32, FALSE)
        Set(LVar0, 0)
        Call(N(GetCurrentStatMaxima), LVar1, LVar2, LVar3)
        IfLe(LVar1, 5)
            Set(LVar0, 1)
        EndIf
        IfLe(LVar2, 5)
            Set(LVar0, 1)
        EndIf
        IfLe(LVar3, 3)
            Set(LVar0, 1)
        EndIf
    Else
        Set(LVar0, 1)
    EndIf
    IfEq(LVar0, 0)
        Call(SetNpcCollisionSize, NPC_SELF, 38, 52)
        Call(N(SetNpcShadowScale), -1, Float(2.0))
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_DIRTY_SHADOW, TRUE)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ChetRippo)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};
