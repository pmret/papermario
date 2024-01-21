#include "common.h"
#include "KoopaWithoutShell.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_KoopaWithoutShell_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaWithoutShell_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_KoopaWithoutShell_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_KoopaWithoutShell_Patrol) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_KoopaWithoutShell_Patrol),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

s32 N(missing_80246F94_6F94)[] = {
    0x00000000, 0x002A0018, 0x00000000, 0x00000000, 0x80246F48, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00630000,
};
