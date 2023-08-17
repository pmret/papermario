#include "Gulpit.h"

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

#include "world/common/enemy/ai/GenericHitboxDefeat.inc.c"

MobileAISettings N(AISettings_Gulpit) = {
    .moveSpeed = 0.5f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 100.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 20,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Gulpit) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 13)
    EVT_CALL(SetSelfVar, 3, 30)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(AISettings_Gulpit)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Gulpit) = {
    .height = 48,
    .radius = 36,
    .level = ACTOR_LEVEL_GULPIT,
    .ai = &N(EVS_NpcAI_Gulpit),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_Gulpit_Hitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 6)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 2, 55)
    EVT_CALL(SetSelfVar, 3, 32)
    EVT_CALL(SetSelfVar, 4, 10)
    EVT_CALL(SetSelfVar, 15, 0)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Gulpit_Hitbox) = {
    .height = 32,
    .radius = 22,
    .level = ACTOR_LEVEL_GULPIT,
    .ai = &N(EVS_NpcAI_Gulpit_Hitbox),
    .onDefeat = &N(EVS_GenericHitboxDefeat),
    .actionFlags = AI_ACTION_08,
};

AnimID N(ExtraAnims_Gulpit_Hitbox)[] = {
    ANIM_Gulpit_Anim00,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Gulpit)[] = {
    ANIM_Gulpit_Anim00,
    ANIM_Gulpit_Anim01,
    ANIM_Gulpit_Anim0B,
    ANIM_Gulpit_Anim04,
    ANIM_Gulpit_Anim02,
    ANIM_Gulpit_Anim03,
    ANIM_LIST_END
};
