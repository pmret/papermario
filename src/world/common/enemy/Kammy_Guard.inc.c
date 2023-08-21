#include "Kammy.h"

// odd enemy template used in kmr_02 for flying kammy

#include "world/common/enemy/ai/GuardAI.inc.c"

GuardAISettings N(AISettings_Kammy_Guard) = {
    .playerSearchInterval = -1,
    .chaseRadius = 300.0f,
    .unk_AI_20 = 30,
};

EvtScript N(EVS_NpcAI_Kammy_Guard) = {
    EVT_CALL(N(GuardAI_Main), EVT_PTR(N(AISettings_Kammy_Guard)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Kammy_Guard) = {
    .height = 40,
    .radius = 30,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .ai = &N(EVS_NpcAI_Kammy_Guard),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
