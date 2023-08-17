#include "StarSpirit.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_StarSpirit_Wander) = {
    .moveSpeed = 1.2f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_StarSpirit_Wander) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_StarSpirit_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_StarSpirit_Wander) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_StarSpirit_Wander),
};

NpcSettings N(NpcSettings_StarKid_Wander) = {
    .height = 20,
    .radius = 20,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_StarSpirit_Wander),
};

NpcSettings N(NpcSettings_StarMan_Wander) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_StarSpirit_Wander),
};
