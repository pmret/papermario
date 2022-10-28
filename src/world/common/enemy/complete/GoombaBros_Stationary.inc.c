#include "GoombaBros.h"

#include "world/common/enemy/ai/StationaryAI.inc.c"

StationaryAISettings N(AISettings_GoombaBros_Stationary) = {
    .unk_00 = 130.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 2.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_20 = 1,
};

EvtScript N(EVS_NpcAI_GoombaBros_Stationary) = {
    EVT_CALL(N(StationaryAI_Main), EVT_PTR(N(AISettings_GoombaBros_Stationary)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_GoombaBros_Stationary) = {
    .height = 20,
    .radius = 23,
    .level = 5,
    .ai = &N(EVS_NpcAI_GoombaBros_Stationary),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
