#include "Spiny.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

MobileAISettings N(AISettings_Spiny) = {
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

EvtScript N(EVS_NpcAI_Spiny) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(SetSelfVar, 5, 3)
    EVT_CALL(SetSelfVar, 7, 4)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_Spiny)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Spiny) = {
    .height = 21,
    .radius = 22,
    .level = ACTOR_LEVEL_SPINY,
    .ai = &N(EVS_NpcAI_Spiny),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
