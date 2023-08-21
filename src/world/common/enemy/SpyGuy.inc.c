#include "SpyGuy.h"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

API_CALLABLE(N(SetSpyGuyInstigatorValue)) {
    script->owner1.enemy->instigatorValue = 3;
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_SpyGuyRock) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 5)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_SpyGuy) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 90.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.8f,
    .chaseTurnRate = 8,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpyGuy) = {
    EVT_CALL(N(SetSpyGuyInstigatorValue))
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 12)
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(N(RangedAttackAI_Main), EVT_PTR(N(AISettings_SpyGuy)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpyGuy) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_SPY_GUY,
    .ai = &N(EVS_NpcAI_SpyGuy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

MobileAISettings N(AISettings_SpyGuyRock) = {
    .moveSpeed = 8.0f,
    .alertRadius = 4.0f,
    .alertOffsetDist = 0.5f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_SpyGuyRock_Projectile) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(SetSelfVar, 2, 12)
    EVT_CALL(SetSelfVar, 3, 13)
    EVT_CALL(N(ProjectileAI_Main), EVT_PTR(N(AISettings_SpyGuyRock)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_SpyGuyRock_Projectile_None) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_SpyGuyRock) = {
    EVT_CALL(N(GetEncounterEnemyIsOwner))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_SpyGuyRock_Projectile_None)))
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_SPIN)
            EVT_CALL(SetSelfVar, 0, 3)
            EVT_CALL(N(ProjectileAI_Reflect))
            EVT_IF_EQ(LVar0, 0)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(SetSelfVar, 0, 4)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetSelfVar, 0, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetBattleAsScripted)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_SpyGuyRock_Projectile)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpyGuyRock) = {
    .height = 7,
    .radius = 7,
    .ai = &N(EVS_NpcAI_SpyGuyRock_Projectile),
    .onHit = &N(EVS_NpcHit_SpyGuyRock),
    .onDefeat = &N(EVS_NpcDefeat_SpyGuyRock),
    .actionFlags = AI_ACTION_08,
};
