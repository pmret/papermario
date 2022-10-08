#include "common.h"
#include "sprite/npc/BuzzyBeetle.h"

#define SPIKE_TOP_DROPS \
{ \
    .dropFlags = NPC_DROP_FLAGS_80, \
    .itemDropChance = 5, \
    .itemDrops = { \
        { ITEM_SUPER_SODA, 10, 0 }, \
    }, \
    .heartDrops  = STANDARD_HEART_DROPS(4), \
    .flowerDrops = STANDARD_FLOWER_DROPS(2), \
    .minCoinBonus = 2, \
    .maxCoinBonus = 3, \
}

#define SPIKE_TOP_ANIMS \
{ \
    .idle   = ANIM_SpikeTop_Anim03, \
    .walk   = ANIM_SpikeTop_Anim06, \
    .run    = ANIM_SpikeTop_Anim08, \
    .chase  = ANIM_SpikeTop_Anim08, \
    .anim_4 = ANIM_SpikeTop_Anim03, \
    .anim_5 = ANIM_SpikeTop_Anim03, \
    .death  = ANIM_SpikeTop_Anim13, \
    .hit    = ANIM_SpikeTop_Anim13, \
    .anim_8 = ANIM_SpikeTop_Anim0B, \
    .anim_9 = ANIM_SpikeTop_Anim0A, \
    .anim_A = ANIM_SpikeTop_Anim0C, \
    .anim_B = ANIM_SpikeTop_Anim03, \
    .anim_C = ANIM_SpikeTop_Anim03, \
    .anim_D = ANIM_SpikeTop_Anim03, \
    .anim_E = ANIM_SpikeTop_Anim03, \
    .anim_F = ANIM_SpikeTop_Anim03, \
}


#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

MobileAISettings N(D_80243AA0_C647B0) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 60,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 4.5f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80243AD0_C647E0) = {
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(SetSelfVar, 5, 5)
    EVT_CALL(SetSelfVar, 7, 2)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80243AA0_C647B0)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_SpikeTop) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 60,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 7.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpikeTop) = {
    EVT_CALL(SetSelfVar, 2, 4)
    EVT_CALL(SetSelfVar, 3, 10)
    EVT_CALL(SetSelfVar, 5, 4)
    EVT_CALL(SetSelfVar, 7, 3)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_SpikeTop)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80243BE0_C648F0) = {
    .moveSpeed = 1.0f,
    .moveTime = 20,
    .waitTime = 5,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80243C10_C64920) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 8)
    EVT_CALL(SetSelfVar, 5, 6)
    EVT_CALL(SetSelfVar, 7, 6)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80243BE0_C648F0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243C80_C64990) = {
    EVT_CALL(N(func_80240814_97BE44))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BuzzyBeetle_Anim0F)
    EVT_CALL(N(AwaitPlayerNearNpc))
    EVT_CALL(SelfEnemyOverrideSyncPos, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BuzzyBeetle_Anim00)
    EVT_CALL(N(func_802408B4_97BEE4))
    EVT_CALL(SelfEnemyOverrideSyncPos, 0)
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(SetSelfVar, 5, 5)
    EVT_CALL(SetSelfVar, 7, 2)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80243AA0_C647B0)))
    EVT_RETURN
    EVT_END
};

// different spike top prefabs

NpcSettings N(NpcSettings_Unused1) = {
    .height = 20,
    .radius = 22,
    .level = 10,
    .ai = &N(D_80243AD0_C647E0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Unused2) = {
    .height = 20,
    .radius = 22,
    .level = 10,
    .ai = &N(D_80243C80_C64990),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_SpikeTop) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(EVS_NpcAI_SpikeTop),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Unused3) = {
    .height = 24,
    .radius = 24,
    .level = 25,
    .ai = &N(D_80243C10_C64920),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
