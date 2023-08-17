#include "Swooper.h"

#include "world/common/enemy/ai/SwooperAI.inc.c"

MobileAISettings N(AISettings_Swooper) = {
    .moveSpeed = 1.6f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 80.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 2.2f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 15,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Swooper) = {
    EVT_CALL(N(SwooperAI_Main), EVT_PTR(N(AISettings_Swooper)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_Swoopula) = {
    .moveSpeed = 1.6f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 80.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 2.2f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 15,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Swoopula) = {
    EVT_CALL(N(SwooperAI_Main), EVT_PTR(N(AISettings_Swoopula)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Swooper) = {
    .height = 20,
    .radius = 20,
    .level = ACTOR_LEVEL_SWOOPER,
    .ai = &N(EVS_NpcAI_Swooper),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .flags = ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_Swoopula) = {
    .height = 20,
    .radius = 20,
    .level = ACTOR_LEVEL_SWOOPULA,
    .ai = &N(EVS_NpcAI_Swoopula),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .flags = ENEMY_FLAG_FLYING,
};
