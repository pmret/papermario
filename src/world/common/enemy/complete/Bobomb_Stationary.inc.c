#include "common.h"

#include "world/common/enemy/StationaryAI.inc.c"

StationaryAISettings N(AISettings_Bombomb_Stationary) = {
    .unk_00 = 110.0f,
    .unk_04 = 65.0f,
    .playerSearchInterval = 8,
    .chaseSpeed = 3.4f,
    .chaseTurnRate = 120,
    .chaseUpdateInterval = 2,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 65.0f,
    .unk_20 = 1,
};

EvtScript N(EVS_NpcAI_Bombomb_Stationary) = {
    EVT_CALL(N(StationaryAI_Main), EVT_PTR(N(AISettings_Bombomb_Stationary)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bombomb_Stationary) = {
    .height = 23,
    .radius = 20,
    .level = 6,
    .ai = &N(EVS_NpcAI_Bombomb_Stationary),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
