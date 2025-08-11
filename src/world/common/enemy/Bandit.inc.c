
#include "Bandit.h"

#define HAS_COIN_FLAG    AreaFlag(1)

API_CALLABLE(N(Bandit_TetherStolenCoin)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID;
    Npc* npc;
    s32 itemEntityIndex;
    s32 areaFlag;

    if (isInitialCall) {
        npcID = evt_get_variable(script, *args++);
        itemEntityIndex = evt_get_variable(script, *args++);
        areaFlag = *args++;

        if (npcID == -1) {
            npc = get_npc_unsafe(script->owner2.npcID);
        } else if (npcID >= EVT_LIMIT) {
            npc = get_npc_unsafe(npcID);
        } else {
            npc = (Npc*)npcID;
        }

        script->functionTempPtr[0] = npc;
        script->functionTemp[1] = itemEntityIndex;
        script->functionTemp[2] = areaFlag;
    }

    npc = script->functionTempPtr[0];
    itemEntityIndex = script->functionTemp[1];
    areaFlag = script->functionTemp[2];

    if (evt_get_variable(script, areaFlag)) {
        set_item_entity_position(itemEntityIndex, npc->pos.x, npc->pos.y + 30.0f, npc->pos.z);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Bandit_CreateStolenCoin) = {
    Set(LVarA, LVar0)
    Call(GetNpcPos, LVarA, LVar1, LVar2, LVar3)
    Add(LVar2, 30)
    Call(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
    Call(N(Bandit_TetherStolenCoin), LVarA, LVar0, HAS_COIN_FLAG)
    Call(RemoveItemEntity, LVar0)
    Return
    End
};

MobileAISettings N(AISettings_Bandit) = {
    .moveSpeed = 2.7f,
    .moveTime = 45,
    .waitTime = 30,
    .alertRadius = 450.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 8.3f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 100,
    .chaseRadius = 550.0f,
    .chaseOffsetDist = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Bandit) = {
    Call(BasicAI_Main, Ref(N(AISettings_Bandit)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Bandit) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(OnPlayerFled, 0)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(DisablePlayerInput, true)
            Set(HAS_COIN_FLAG, true)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Bandit_IdleHolding)
            Call(GetSelfNpcID, LVar0)
            Exec(N(EVS_Bandit_CreateStolenCoin))
            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
            Call(GetPlayerPos, LVar7, LVar8, LVar9)
            Add(LVar7, 20)
            Call(NpcJump0, NPC_SELF, LVar7, 0, LVar9, 6)
            Add(LVar7, 20)
            Call(NpcJump0, NPC_SELF, LVar7, 0, LVar9, 6)
            Call(GetNpcYaw, NPC_SELF, LVar0)
            Add(LVar0, 180)
            Call(InterpNpcYaw, NPC_SELF, LVar0, 5)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Bandit_RunHolding)
            Wait(10)
            Call(SetNpcSpeed, NPC_SELF, Float(16.0))
            Add(LVar7, 200)
            Call(NpcMoveTo, NPC_SELF, LVar7, LVar9, 0)
            Set(HAS_COIN_FLAG, false)
            Call(DisablePlayerInput, false)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Bandit) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_BANDIT,
    .ai = &N(EVS_NpcAI_Bandit),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_Bandit),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER | AI_ACTION_04,
};
