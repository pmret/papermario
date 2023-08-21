#include "Ember.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"
#include "world/common/enemy/ai/FlyingNoAttackAI.inc.c"

MobileAISettings N(AISettings_Ember) = {
    .moveSpeed = 0.8f,
    .moveTime = 100,
    .alertRadius = 90.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 3.8f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Ember) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(AISettings_Ember)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Ember) = {
    .height = 20,
    .radius = 22,
    .level = ACTOR_LEVEL_EMBER,
    .ai = &N(EVS_NpcAI_Ember),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
