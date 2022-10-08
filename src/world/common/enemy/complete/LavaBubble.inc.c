#include "common.h"

#define LAVA_BUBBLE_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SHROOM, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 3, \
}

#define LAVA_BUBBLE_ANIMS \
{ \
    .idle   = ANIM_LavaBubble_Anim01, \
    .walk   = ANIM_LavaBubble_Anim02, \
    .run    = ANIM_LavaBubble_Anim03, \
    .chase  = ANIM_LavaBubble_Anim03, \
    .anim_4 = ANIM_LavaBubble_Anim01, \
    .anim_5 = ANIM_LavaBubble_Anim01, \
    .death  = ANIM_LavaBubble_Anim07, \
    .hit    = ANIM_LavaBubble_Anim07, \
    .anim_8 = ANIM_LavaBubble_Anim04, \
    .anim_9 = ANIM_LavaBubble_Anim01, \
    .anim_A = ANIM_LavaBubble_Anim01, \
    .anim_B = ANIM_LavaBubble_Anim01, \
    .anim_C = ANIM_LavaBubble_Anim01, \
    .anim_D = ANIM_LavaBubble_Anim01, \
    .anim_E = ANIM_LavaBubble_Anim01, \
    .anim_F = ANIM_LavaBubble_Anim01, \
}

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0,
};

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

MobileAISettings N(AISettings_LavaBubble) = {
    .moveSpeed = 0.8f,
    .moveTime = 100,
    .alertRadius = 90.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 3.2f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_LavaBubble) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 150)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(AISettings_LavaBubble)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_LavaBubble) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(EVS_NpcAI_LavaBubble),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
