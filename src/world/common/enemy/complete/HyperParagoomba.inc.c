
#include "common.h"

#define HYPER_PARAGOOMBA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 20, \
    .itemDrops = { \
        { ITEM_DRIED_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 2, \
}

#define HYPER_PARAGOOMBA_ANIMS \
{ \
    .idle   = ANIM_Paragoomba_Hyper_Idle, \
    .walk   = ANIM_Paragoomba_Hyper_Walk, \
    .run    = ANIM_Paragoomba_Hyper_Run, \
    .chase  = ANIM_Paragoomba_Hyper_Run, \
    .anim_4 = ANIM_Paragoomba_Hyper_Idle, \
    .anim_5 = ANIM_Paragoomba_Hyper_Idle, \
    .death  = ANIM_Paragoomba_Hyper_Hurt, \
    .hit    = ANIM_Paragoomba_Hyper_Hurt, \
    .anim_8 = ANIM_Paragoomba_Hyper_Dive, \
    .anim_9 = ANIM_Paragoomba_Hyper_Run, \
    .anim_A = ANIM_Paragoomba_Hyper_Run, \
    .anim_B = ANIM_Paragoomba_Hyper_Run, \
    .anim_C = ANIM_Paragoomba_Hyper_Run, \
    .anim_D = ANIM_Paragoomba_Hyper_Run, \
    .anim_E = ANIM_Paragoomba_Hyper_Run, \
    .anim_F = ANIM_Paragoomba_Hyper_Run, \
}

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0, 
};

#include "world/common/enemy/FlyingAI.inc.c"

MobileAISettings N(AISettings_Paragoomba) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 5,
    .chaseUpdateInterval = 1,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Paragoomba) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 700)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_Paragoomba)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Paragoomba) = {
    .height = 18,
    .radius = 20,
    .level = 12,
    .ai = &N(EVS_NpcAI_Paragoomba),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
