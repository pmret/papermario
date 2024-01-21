#include "Pokey.h"

API_CALLABLE(N(SetPokeyInstigatorValue)) {
    script->owner1.enemy->instigatorValue = 3;
    return ApiStatus_DONE2;
}

MobileAISettings N(AISettings_Pokey) = {
    .moveSpeed = 1.8f,
    .moveTime = 50,
    .waitTime = 10,
    .alertRadius = 250.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 45,
    .chaseUpdateInterval = 6,
    .chaseRadius = 300.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Pokey) = {
    Call(N(SetPokeyInstigatorValue))
    Call(BasicAI_Main, Ref(N(AISettings_Pokey)))
    Return
    End
};

NpcSettings N(NpcSettings_Pokey) = {
    .height = 72,
    .radius = 15,
    .level = ACTOR_LEVEL_POKEY,
    .ai = &N(EVS_NpcAI_Pokey),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
