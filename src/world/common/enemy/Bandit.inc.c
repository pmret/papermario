
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
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetNpcPos, LVarA, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, 30)
    EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_CALL(N(Bandit_TetherStolenCoin), LVarA, LVar0, HAS_COIN_FLAG)
    EVT_CALL(RemoveItemEntity, LVar0)
    EVT_RETURN
    EVT_END
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
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Bandit)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Bandit) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_SET(HAS_COIN_FLAG, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bandit_IdleHolding)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_EXEC(N(EVS_Bandit_CreateStolenCoin))
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetPlayerPos, LVar7, LVar8, LVar9)
            EVT_ADD(LVar7, 20)
            EVT_CALL(NpcJump0, NPC_SELF, LVar7, 0, LVar9, 6)
            EVT_ADD(LVar7, 20)
            EVT_CALL(NpcJump0, NPC_SELF, LVar7, 0, LVar9, 6)
            EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
            EVT_ADD(LVar0, 180)
            EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 5)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bandit_RunHolding)
            EVT_WAIT(10)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(16.0))
            EVT_ADD(LVar7, 200)
            EVT_CALL(NpcMoveTo, NPC_SELF, LVar7, LVar9, 0)
            EVT_SET(HAS_COIN_FLAG, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
