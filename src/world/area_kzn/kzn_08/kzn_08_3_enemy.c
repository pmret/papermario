#include "kzn_08.h"

extern EvtScript D_800936DC;

#include "sprite/npc/LargePiranha.h"

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

#include "world/common/enemy/PiranhaPlantAI.inc.c"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0, 
};

MobileAISettings N(D_80244DB8_C76238) = {
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

EvtScript N(D_80244DE8_C76268) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 150)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(D_80244DB8_C76238)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(80244E58) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(D_80244DE8_C76268),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(D_80244E84_C76304) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(func_80045900, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80244F40_C763C0) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(D_80244F70_C763F0) = {
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(SetSelfVar, 8, 10)
    EVT_CALL(SetSelfVar, 9, 9)
    EVT_CALL(SetSelfVar, 10, 12)
    EVT_CALL(SetSelfVar, 11, 7)
    EVT_CALL(SetSelfVar, 12, 30)
    EVT_CALL(SetSelfVar, 13, 15)
    EVT_CALL(SetSelfVar, 14, 18)
    EVT_CALL(SetSelfVar, 15, 15)
    EVT_CALL(N(PiranhaPlantAI_Main), EVT_PTR(N(D_80244F40_C763C0)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(D_80245044_C764C4) = {
    .height = 50,
    .radius = 36,
    .level = 17,
    .ai = &N(D_80244F70_C763F0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(D_80245070_C764F0) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 14)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_20DE)
    EVT_CALL(EVT_PTR(N(MeleeHitbox_Main)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802450F0) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(D_800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MeleeHitbox) = {
    .height = 20,
    .radius = 28,
    .level = 17,
    .ai = &N(D_80245070_C764F0),
    .onDefeat = &N(D_80244E84_C76304),
};

StaticNpc N(D_802451A8_C76628)[] = {
    {
        .id = NPC_PutridPiranha_01,
        .settings = &N(D_80245044_C764C4),
        .pos = { 80.0f, 0.0f, 135.0f },
        .yaw = 270,
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS,
        .init = NULL,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 80, 0, 135 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 90, 0, 130 },
                .detectSize = { 130, 60 },
            }
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_PutridPiranha_02,
        .settings = &N(NpcSettings_MeleeHitbox),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .init = NULL,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(D_802451A8_C76628), BTL_KZN_FORMATION_11, BTL_KZN_STAGE_04),
    {}
};
