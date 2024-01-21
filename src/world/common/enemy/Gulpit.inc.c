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
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 5)
    Call(SetSelfVar, 2, 13)
    Call(SetSelfVar, 3, 30)
    Call(N(WanderMeleeAI_Main), Ref(N(AISettings_Gulpit)))
    Return
    End
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
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetSelfVar, 0, 6)
    Call(SetSelfVar, 1, 28)
    Call(SetSelfVar, 2, 55)
    Call(SetSelfVar, 3, 32)
    Call(SetSelfVar, 4, 10)
    Call(SetSelfVar, 15, 0)
    Call(N(MeleeHitbox_Main))
    Return
    End
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
