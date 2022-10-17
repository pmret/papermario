#include "SpikeTop.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

#include "world/common/todo/AwaitPlayerNearNpc.inc.c"

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

// different spike top varieties

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
