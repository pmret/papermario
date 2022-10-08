#include "common.h"

#define PARATROOPA_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_POW_BLOCK, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 1, \
    .maxCoinBonus = 1, \
}

#define PARATROOPA_ANIMS \
{ \
    .idle   = ANIM_ParaTroopa_Anim01, \
    .walk   = ANIM_ParaTroopa_Anim02, \
    .run    = ANIM_ParaTroopa_Anim03, \
    .chase  = ANIM_ParaTroopa_Anim03, \
    .anim_4 = ANIM_ParaTroopa_Anim01, \
    .anim_5 = ANIM_ParaTroopa_Anim01, \
    .death  = ANIM_ParaTroopa_Anim06, \
    .hit    = ANIM_ParaTroopa_Anim06, \
    .anim_8 = ANIM_ParaTroopa_Anim04, \
    .anim_9 = ANIM_ParaTroopa_Anim0C, \
    .anim_A = ANIM_ParaTroopa_Anim0A, \
    .anim_B = ANIM_ParaTroopa_Anim0E, \
    .anim_C = ANIM_ParaTroopa_Anim03, \
    .anim_D = ANIM_ParaTroopa_Anim03, \
    .anim_E = ANIM_ParaTroopa_Anim03, \
    .anim_F = ANIM_ParaTroopa_Anim03, \
}

#include "world/common/enemy/ParatroopaAI.inc.c"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0, 
};

MobileAISettings N(AISettings_ParaTroopa) = {
    .moveSpeed = 2.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 20.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 2.6f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 10,
    .chaseRadius = 150.0f,
    .chaseOffsetDist = 20.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ParaTroopa) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(ParatroopaAI_Main), EVT_PTR(N(AISettings_ParaTroopa)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ParaTroopa) = {
    .height = 40,
    .radius = 24,
    .level = 6,
    .ai = &N(EVS_NpcAI_ParaTroopa),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
