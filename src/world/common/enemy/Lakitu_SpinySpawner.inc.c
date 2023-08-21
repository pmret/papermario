#include "Lakitu.h"
#include "Spiny.h"

#include "world/common/enemy/ai/LakituAI.inc.c"

MobileAISettings N(AISettings_Lakitu_SpinySpawner) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 60.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 10,
    .chaseRadius = 80.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Lakitu_SpinySpawner) = {
    #ifdef DEBUG_LAKITU
    EVT_DEBUG_LOG(EVT_PTR("JUGEMU MOVE"))
    #endif
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 400)
    EVT_CALL(N(LakituAI_Main), EVT_PTR(N(AISettings_Lakitu_SpinySpawner)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Lakitu_SpinySpawner) = {
    .height = 28,
    .radius = 24,
    .level = ACTOR_LEVEL_LAKITU,
    .ai = &N(EVS_NpcAI_Lakitu_SpinySpawner),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/enemy/ai/SpinyAI.inc.c"

MobileAISettings N(AISettings_SpawnedSpiny) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 3,
};

EvtScript N(EVS_NpcAI_SpawnedSpiny) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    #ifdef DEBUG_LAKITU
    EVT_DEBUG_LOG(EVT_PTR("TOGEZO TYPE1 : NORMAL MOVE"))
    #endif
    EVT_CALL(N(SpinyAI_Main), EVT_PTR(N(AISettings_SpawnedSpiny)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_SpawnedSpiny) = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 10, 100)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpawnedSpiny) = {
    .height = 21,
    .radius = 22,
    .level = ACTOR_LEVEL_SPINY,
    .ai = &N(EVS_NpcAI_SpawnedSpiny),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_SpawnedSpiny),
};
