
#include "common.h"

#include "world/common/Bandit_DropCoin.inc.c"

EvtScript N(EVS_Bandit_CreateStolenCoin) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetNpcPos, LVarA, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, 30)
    EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_CALL(N(Bandit_DropCoin), LVarA, LVar0, AF_SBK_01)
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
            EVT_CALL(func_80045900, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_SET(AF_SBK_01, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bandit_Anim02)
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
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bandit_Anim08)
            EVT_WAIT(10)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(16.0))
            EVT_ADD(LVar7, 200)
            EVT_CALL(NpcMoveTo, NPC_SELF, LVar7, LVar9, 0)
            EVT_SET(AF_SBK_01, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bandit) = {
    .height = 26,
    .radius = 24,
    .level = 9,
    .ai = &N(EVS_NpcAI_Bandit),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_Bandit),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER | AI_ACTION_04,
};
