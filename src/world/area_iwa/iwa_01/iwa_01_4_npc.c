#include "iwa_01.h"

#include "world/common/enemy/MontyMoleAI.inc.c"

#include "world/common/enemy/RangedAttackAI.inc.c"

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

#include "world/common/enemy/CleftAI.inc.c"

EvtScript N(EVS_NpcDefeat_MontyMole_04) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 5)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_MontyMole_03) = {
    .moveSpeed = 1.7f,
    .moveTime = 90,
    .alertRadius = 110.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 7.5f,
    .chaseRadius = 110.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_03) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2 | NPC_FLAG_200000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_LABEL(0)
    EVT_CALL(RandInt, 15, LVar0)
    EVT_ADD(LVar0, 15)
    EVT_WAIT(LVar0)
    EVT_CALL(N(MontyMoleAI_Main), EVT_PTR(N(AISettings_MontyMole_03)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MontyMole_03) = {
    .height = 20,
    .radius = 24,
    .level = 8,
    .ai = &N(EVS_NpcAI_MontyMole_03),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_08,
};

MobileAISettings N(AISettings_MontyMole_04) = {
    .moveSpeed = 8.3f,
    .alertRadius = 2.5f,
    .alertOffsetDist = 0.4f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_MontyMole_04) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(SetSelfVar, 2, 17)
    EVT_CALL(SetSelfVar, 3, 17)
    EVT_CALL(N(ProjectileAI_Main), EVT_PTR(N(AISettings_MontyMole_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_MontyMole_04b) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_MontyMole_04) = {
    EVT_CALL(N(GetEncounterEnemyIsOwner))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MontyMole_04b)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_SPIN)
            EVT_CALL(SetSelfVar, 0, 3)
            EVT_CALL(N(ProjectileAI_Reflect))
            EVT_IF_EQ(LVar0, 0)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_CALL(SetSelfVar, 0, 4)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetSelfVar, 0, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(func_800457F8)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MontyMole_04)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MontyMole_04) = {
    .height = 12,
    .radius = 12,
    .ai = &N(EVS_NpcAI_MontyMole_04),
    .onHit = &N(EVS_NpcHit_MontyMole_04),
    .onDefeat = &N(EVS_NpcDefeat_MontyMole_04),
    .actionFlags = AI_ACTION_08,
};

EvtScript N(D_80244384_913A34) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244420_913AD0) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim12)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_802444A0_913B50) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_802444D0_913B80) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
        EVT_ADD(LVar5, 30)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar4, LVar5, LVar6, 20)
        EVT_CALL(SetNpcPos, LVar0, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
        EVT_CALL(BasicAI_Main, EVT_PTR(N(D_802444A0_913B50)))
        EVT_RETURN
        EVT_END
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(D_80244384_913A34),
    .ai = &N(D_802444D0_913B80),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_Unused2) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(D_80244420_913AD0),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

EvtScript N(EVS_NpcAuxAI_MontyMole_01) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 50)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_MontyMole_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 50)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim13)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80244890_913F40) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_01) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 130)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_ADD(LVar3, 50)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_SUB(LVar2, 30)
        EVT_ADD(LVar3, 80)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.7))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar1, LVar2, LVar3, 20)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_END_IF
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80244890_913F40)))
    EVT_RETURN
    EVT_END
};

EvtScript N(missing_80244B58_4B58) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MontyMole_01) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_01),
    .ai = &N(EVS_NpcAI_MontyMole_01),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_MontyMole_02) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_02),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

MobileAISettings N(AISettings_Cleft) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 7.0f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 5,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Cleft) = {
    EVT_CALL(N(CleftAI_Main), EVT_PTR(N(AISettings_Cleft)), 16)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Cleft) = {
    .height = 26,
    .radius = 24,
    .level = 10,
    .ai = &N(EVS_NpcAI_Cleft),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

StaticNpc N(NpcData_MontyMole_01)[] = {
    {
        .id = NPC_MontyMole_01,
        .settings = &N(NpcSettings_MontyMole_01),
        .pos = { 340.0f, 70.0f, 101.0f },
        .yaw = 0,
        .flags = NPC_FLAG_LOCK_ANIMS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 10,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 345, 70, 245 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 425, 70, 245 },
                .detectSize = { 145, 300 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim19,
            .walk   = ANIM_MontyMole_Anim02,
            .run    = ANIM_MontyMole_Anim03,
            .chase  = ANIM_MontyMole_Anim03,
            .anim_4 = ANIM_MontyMole_Anim19,
            .anim_5 = ANIM_MontyMole_Anim19,
            .death  = ANIM_MontyMole_Anim09,
            .hit    = ANIM_MontyMole_Anim09,
            .anim_8 = ANIM_MontyMole_Anim19,
            .anim_9 = ANIM_MontyMole_Anim19,
            .anim_A = ANIM_MontyMole_Anim19,
            .anim_B = ANIM_MontyMole_Anim19,
            .anim_C = ANIM_MontyMole_Anim19,
            .anim_D = ANIM_MontyMole_Anim19,
            .anim_E = ANIM_MontyMole_Anim19,
            .anim_F = ANIM_MontyMole_Anim19,
        },
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_02,
        .settings = &N(NpcSettings_MontyMole_02),
        .pos = { 340.0f, 70.0f, 101.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_AI | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim19,
            .walk   = ANIM_MontyMole_Anim02,
            .run    = ANIM_MontyMole_Anim03,
            .chase  = ANIM_MontyMole_Anim03,
            .anim_4 = ANIM_MontyMole_Anim19,
            .anim_5 = ANIM_MontyMole_Anim19,
            .death  = ANIM_MontyMole_Anim09,
            .hit    = ANIM_MontyMole_Anim09,
            .anim_8 = ANIM_MontyMole_Anim19,
            .anim_9 = ANIM_MontyMole_Anim19,
            .anim_A = ANIM_MontyMole_Anim19,
            .anim_B = ANIM_MontyMole_Anim19,
            .anim_C = ANIM_MontyMole_Anim19,
            .anim_D = ANIM_MontyMole_Anim19,
            .anim_E = ANIM_MontyMole_Anim19,
            .anim_F = ANIM_MontyMole_Anim19,
        },
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
};

StaticNpc N(NpcData_MontyMole_03)[] = {
    {
        .id = NPC_MontyMole_03,
        .settings = &N(NpcSettings_MontyMole_03),
        .pos = { -250.0f, 10.0f, 260.0f },
        .yaw = 90,
        .flags = NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 10,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -250, 10, 260 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -250, 10, 260 },
                .detectSize = { 180 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim01,
            .walk   = ANIM_MontyMole_Anim02,
            .run    = ANIM_MontyMole_Anim03,
            .chase  = ANIM_MontyMole_Anim03,
            .anim_4 = ANIM_MontyMole_Anim01,
            .anim_5 = ANIM_MontyMole_Anim01,
            .death  = ANIM_MontyMole_Anim05,
            .hit    = ANIM_MontyMole_Anim05,
            .anim_8 = ANIM_MontyMole_Anim00,
            .anim_9 = ANIM_MontyMole_Anim00,
            .anim_A = ANIM_MontyMole_Anim00,
            .anim_B = ANIM_MontyMole_Anim00,
            .anim_C = ANIM_MontyMole_Anim00,
            .anim_D = ANIM_MontyMole_Anim00,
            .anim_E = ANIM_MontyMole_Anim00,
            .anim_F = ANIM_MontyMole_Anim00,
        },
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_04,
        .settings = &N(NpcSettings_MontyMole_04),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { NPC_DISPOSE_LOCATION },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim0F,
            .walk   = ANIM_MontyMole_Anim0F,
            .run    = ANIM_MontyMole_Anim0F,
            .chase  = ANIM_MontyMole_Anim0F,
            .anim_4 = ANIM_MontyMole_Anim0F,
            .anim_5 = ANIM_MontyMole_Anim0F,
            .death  = ANIM_MontyMole_Anim0F,
            .hit    = ANIM_MontyMole_Anim0F,
            .anim_8 = ANIM_MontyMole_Anim0F,
            .anim_9 = ANIM_MontyMole_Anim0F,
            .anim_A = ANIM_MontyMole_Anim0F,
            .anim_B = ANIM_MontyMole_Anim0F,
            .anim_C = ANIM_MontyMole_Anim0F,
            .anim_D = ANIM_MontyMole_Anim0F,
            .anim_E = ANIM_MontyMole_Anim0F,
            .anim_F = ANIM_MontyMole_Anim0F,
        },
    },
};

StaticNpc N(NpcData_MontyMole_05)[] = {
    {
        .id = NPC_MontyMole_05,
        .settings = &N(NpcSettings_MontyMole_03),
        .pos = { -175.0f, 10.0f, 240.0f },
        .yaw = 270,
        .flags = NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 10,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -175, 10, 240 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -175, 10, 240 },
                .detectSize = { 180 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim01,
            .walk   = ANIM_MontyMole_Anim02,
            .run    = ANIM_MontyMole_Anim03,
            .chase  = ANIM_MontyMole_Anim03,
            .anim_4 = ANIM_MontyMole_Anim01,
            .anim_5 = ANIM_MontyMole_Anim01,
            .death  = ANIM_MontyMole_Anim05,
            .hit    = ANIM_MontyMole_Anim05,
            .anim_8 = ANIM_MontyMole_Anim00,
            .anim_9 = ANIM_MontyMole_Anim00,
            .anim_A = ANIM_MontyMole_Anim00,
            .anim_B = ANIM_MontyMole_Anim00,
            .anim_C = ANIM_MontyMole_Anim00,
            .anim_D = ANIM_MontyMole_Anim00,
            .anim_E = ANIM_MontyMole_Anim00,
            .anim_F = ANIM_MontyMole_Anim00,
        },
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_06,
        .settings = &N(NpcSettings_MontyMole_04),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { NPC_DISPOSE_LOCATION },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim0F,
            .walk   = ANIM_MontyMole_Anim0F,
            .run    = ANIM_MontyMole_Anim0F,
            .chase  = ANIM_MontyMole_Anim0F,
            .anim_4 = ANIM_MontyMole_Anim0F,
            .anim_5 = ANIM_MontyMole_Anim0F,
            .death  = ANIM_MontyMole_Anim0F,
            .hit    = ANIM_MontyMole_Anim0F,
            .anim_8 = ANIM_MontyMole_Anim0F,
            .anim_9 = ANIM_MontyMole_Anim0F,
            .anim_A = ANIM_MontyMole_Anim0F,
            .anim_B = ANIM_MontyMole_Anim0F,
            .anim_C = ANIM_MontyMole_Anim0F,
            .anim_D = ANIM_MontyMole_Anim0F,
            .anim_E = ANIM_MontyMole_Anim0F,
            .anim_F = ANIM_MontyMole_Anim0F,
        },
    },
};

StaticNpc N(NpcData_MontyMole_07)[] = {
    {
        .id = NPC_MontyMole_07,
        .settings = &N(NpcSettings_MontyMole_03),
        .pos = { -55.0f, 10.0f, 180.0f },
        .yaw = 270,
        .flags = NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 10,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -55, 10, 180 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -55, 10, 180 },
                .detectSize = { 180 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim01,
            .walk   = ANIM_MontyMole_Anim02,
            .run    = ANIM_MontyMole_Anim03,
            .chase  = ANIM_MontyMole_Anim03,
            .anim_4 = ANIM_MontyMole_Anim01,
            .anim_5 = ANIM_MontyMole_Anim01,
            .death  = ANIM_MontyMole_Anim05,
            .hit    = ANIM_MontyMole_Anim05,
            .anim_8 = ANIM_MontyMole_Anim00,
            .anim_9 = ANIM_MontyMole_Anim00,
            .anim_A = ANIM_MontyMole_Anim00,
            .anim_B = ANIM_MontyMole_Anim00,
            .anim_C = ANIM_MontyMole_Anim00,
            .anim_D = ANIM_MontyMole_Anim00,
            .anim_E = ANIM_MontyMole_Anim00,
            .anim_F = ANIM_MontyMole_Anim00,
        },
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_08,
        .settings = &N(NpcSettings_MontyMole_04),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { NPC_DISPOSE_LOCATION },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_MontyMole_Anim0F,
            .walk   = ANIM_MontyMole_Anim0F,
            .run    = ANIM_MontyMole_Anim0F,
            .chase  = ANIM_MontyMole_Anim0F,
            .anim_4 = ANIM_MontyMole_Anim0F,
            .anim_5 = ANIM_MontyMole_Anim0F,
            .death  = ANIM_MontyMole_Anim0F,
            .hit    = ANIM_MontyMole_Anim0F,
            .anim_8 = ANIM_MontyMole_Anim0F,
            .anim_9 = ANIM_MontyMole_Anim0F,
            .anim_A = ANIM_MontyMole_Anim0F,
            .anim_B = ANIM_MontyMole_Anim0F,
            .anim_C = ANIM_MontyMole_Anim0F,
            .anim_D = ANIM_MontyMole_Anim0F,
            .anim_E = ANIM_MontyMole_Anim0F,
            .anim_F = ANIM_MontyMole_Anim0F,
        },
    },
};

StaticNpc N(NpcData_Cleft) = {
    .id = NPC_Cleft,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -657.0f, 163.0f, 155.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -639, 163, 100 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -655, 0, 125 },
            .detectSize = { 125, 125 },
        }
    },
    .animations = {
        .idle   = ANIM_Cleft_Anim02,
        .walk   = ANIM_Cleft_Anim06,
        .run    = ANIM_Cleft_Anim07,
        .chase  = ANIM_Cleft_Anim07,
        .anim_4 = ANIM_Cleft_Anim02,
        .anim_5 = ANIM_Cleft_Anim02,
        .death  = ANIM_Cleft_Anim08,
        .hit    = ANIM_Cleft_Anim08,
        .anim_8 = ANIM_Cleft_Anim14,
        .anim_9 = ANIM_Cleft_Anim17,
        .anim_A = ANIM_Cleft_Anim13,
        .anim_B = ANIM_Cleft_Anim15,
        .anim_C = ANIM_Cleft_Anim10,
        .anim_D = ANIM_Cleft_Anim11,
        .anim_E = ANIM_Cleft_Anim16,
        .anim_F = ANIM_Cleft_Anim00,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_MontyMole_01), BTL_IWA_FORMATION_06, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_03), BTL_IWA_FORMATION_07, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_05), BTL_IWA_FORMATION_06, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_07), BTL_IWA_FORMATION_07, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Cleft), BTL_IWA_FORMATION_04, BTL_IWA_STAGE_01),
    {}
};
