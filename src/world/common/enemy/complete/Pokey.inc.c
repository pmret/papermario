#include "common.h"

#include "world/common/SetNpcB5_3.inc.c"

#define POKEY_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 15, \
    .itemDrops = { \
        { ITEM_DRIED_FRUIT, 9, 0 }, \
        { ITEM_TASTY_TONIC, 1, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(2), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 0, \
    .maxCoinBonus = 1, \
}

#define POKEY_ANIMS \
{ \
    .idle   = ANIM_Pokey_Anim04, \
    .walk   = ANIM_Pokey_Anim08, \
    .run    = ANIM_Pokey_Anim08, \
    .chase  = ANIM_Pokey_Anim08, \
    .anim_4 = ANIM_Pokey_Anim04, \
    .anim_5 = ANIM_Pokey_Anim04, \
    .death  = ANIM_Pokey_Anim0C, \
    .hit    = ANIM_Pokey_Anim0C, \
    .anim_8 = ANIM_Pokey_Anim08, \
    .anim_9 = ANIM_Pokey_Anim08, \
    .anim_A = ANIM_Pokey_Anim08, \
    .anim_B = ANIM_Pokey_Anim08, \
    .anim_C = ANIM_Pokey_Anim08, \
    .anim_D = ANIM_Pokey_Anim08, \
    .anim_E = ANIM_Pokey_Anim08, \
    .anim_F = ANIM_Pokey_Anim08, \
}

MobileAISettings N(AISettings_Pokey) = {
    .moveSpeed = 1.8f,
    .moveTime = 50,
    .waitTime = 10,
    .alertRadius = 250.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 45,
    .chaseUpdateInterval = 6,
    .chaseRadius = 300.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Pokey) = {
    EVT_CALL(N(SetNpcB5_3))
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Pokey)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Pokey) = {
    .height = 72,
    .radius = 15,
    .level = 9,
    .ai = &N(EVS_NpcAI_Pokey),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
