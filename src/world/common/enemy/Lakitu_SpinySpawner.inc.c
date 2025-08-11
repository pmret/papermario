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
    EVT_DEBUG_LOG(Ref("JUGEMU MOVE"))
    #endif
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 5, -650)
    Call(SetSelfVar, 6, 30)
    Call(SetSelfVar, 1, 400)
    Call(N(LakituAI_Main), Ref(N(AISettings_Lakitu_SpinySpawner)))
    Return
    End
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
    Call(SetSelfVar, 2, 3)
    Call(SetSelfVar, 3, 18)
    Call(SetSelfVar, 5, 3)
    Call(SetSelfVar, 7, 4)
    #ifdef DEBUG_LAKITU
    EVT_DEBUG_LOG(Ref("TOGEZO TYPE1 : NORMAL MOVE"))
    #endif
    Call(N(SpinyAI_Main), Ref(N(AISettings_SpawnedSpiny)))
    Return
    End
};

EvtScript N(EVS_NpcDefeat_SpawnedSpiny) = {
    Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetSelfVar, 10, 100)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(OnPlayerFled, 0)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_SpawnedSpiny) = {
    .height = 21,
    .radius = 22,
    .level = ACTOR_LEVEL_SPINY,
    .ai = &N(EVS_NpcAI_SpawnedSpiny),
    .onHit = &EnemyNpcHit,
    .onDefeat = &N(EVS_NpcDefeat_SpawnedSpiny),
};
