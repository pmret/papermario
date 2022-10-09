#include "iwa_03.h"

EvtScript N(EVS_NpcAuxAI_MontyMole_01) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_MontyMole_02) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim12)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80241C1C_91A7CC) = {
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
        EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80241C1C_91A7CC)))
        EVT_RETURN
        EVT_END
};

#include "world/common/enemy/complete/MontyMole.inc.c"

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

#include "world/common/enemy/complete/Cleft.inc.c"

StaticNpc N(NpcData_Cleft_01) = {
    .id = NPC_Cleft_01,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -525.0f, -75.0f, 60.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -525, -75, 60 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -525, -75, 60 },
            .detectSize = { 250 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_02) = {
    .id = NPC_Cleft_02,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -1686.0f, -60.0f, 180.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -1686, -60, 180 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -1686, -60, 180 },
            .detectSize = { 250 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_03) = {
    .id = NPC_Cleft_03,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -1300.0f, 408.0f, -125.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -1300, 408, -125 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -1290, 408, -125 },
            .detectSize = { 140 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_MontyMole_01)[] = {
    {
        .id = NPC_MontyMole_01,
        .settings = &N(NpcSettings_MontyMole_01),
        .pos = { -1000.0f, 23.0f, 60.0f },
        .yaw = 0,
        .flags = NPC_FLAG_LOCK_ANIMS,
        .drops = MONTY_MOLE_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -1000, 23, 60 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -1000, 23, 60 },
                .detectSize = { 250 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_02,
        .settings = &N(NpcSettings_MontyMole_02),
        .pos = { -1000.0f, 23.0f, 60.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_AI | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
        .animations = MONTY_MOLE_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Cleft_01), BTL_IWA_FORMATION_03, BTL_IWA_STAGE_00),
    NPC_GROUP(N(NpcData_Cleft_02), BTL_IWA_FORMATION_00, BTL_IWA_STAGE_00),
    NPC_GROUP(N(NpcData_Cleft_03), BTL_IWA_FORMATION_01, BTL_IWA_STAGE_00),
    NPC_GROUP(N(NpcData_MontyMole_01), BTL_IWA_FORMATION_09, BTL_IWA_STAGE_00),
    {}
};
