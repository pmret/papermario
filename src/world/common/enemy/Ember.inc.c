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
    Call(SetSelfVar, 0, 1)
    Call(SetSelfVar, 5, 0)
    Call(SetSelfVar, 6, 0)
    Call(SetSelfVar, 1, 0)
    Call(N(FlyingNoAttackAI_Main), Ref(N(AISettings_Ember)))
    Return
    End
};

NpcSettings N(NpcSettings_Ember) = {
    .height = 20,
    .radius = 22,
    .level = ACTOR_LEVEL_EMBER,
    .ai = &N(EVS_NpcAI_Ember),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
