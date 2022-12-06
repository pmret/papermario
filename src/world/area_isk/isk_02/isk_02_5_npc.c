#include "isk_02.h"

#include "world/common/enemy/complete/PokeyMummy.inc.c"

EvtScript N(EVS_NpcIdle_Pokey_01) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_10000000, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_LABEL(1)
    EVT_IF_EQ(AF_ISK02_OpeningSarcophagus1, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_10000000, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -315, 455, 10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_PokeyMummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Pokey_02) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_10000000, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_LABEL(1)
    EVT_IF_EQ(AF_ISK02_OpeningSarcophagus2, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_10000000, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -145, 535, 10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_PokeyMummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Pokey_03) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_10000000, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_LABEL(1)
    EVT_IF_EQ(AF_ISK02_OpeningSarcophagus3, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_10000000, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 50, 550, 10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_PokeyMummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey_01)))
    EVT_CALL(func_800457C4, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey_02)))
    EVT_CALL(func_800457C4, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey_03) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey_03)))
    EVT_CALL(func_800457C4, 3)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Pokey_01) = {
    .id = NPC_Pokey_01,
    .settings = &N(NpcSettings_PokeyMummy),
    .pos = { -296.0f, 0.0f, 421.0f },
    .yaw = 304,
    .flags = ENEMY_FLAGS_200 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Pokey_01),
    .drops = POKEY_MUMMY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -301, 0, 427 },
            .wanderSize = { 200 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -301, 0, 427 },
            .detectSize = { 400 },
        }
    },
    .animations = POKEY_MUMMY_ANIMS,
};

StaticNpc N(NpcData_Pokey_02) = {
    .id = NPC_Pokey_02,
    .settings = &N(NpcSettings_PokeyMummy),
    .pos = { -133.0f, 0.0f, 497.0f },
    .yaw = 284,
    .flags = ENEMY_FLAGS_200 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Pokey_02),
    .drops = POKEY_MUMMY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -134, 0, 495 },
            .wanderSize = { 200 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -140, 0, 510 },
            .detectSize = { 400 },
        }
    },
    .animations = POKEY_MUMMY_ANIMS,
};

StaticNpc N(NpcData_Pokey_03) = {
    .id = NPC_Pokey_03,
    .settings = &N(NpcSettings_PokeyMummy),
    .pos = { 45.0f, 0.0f, 505.0f },
    .yaw = 264,
    .flags = ENEMY_FLAGS_200 | ENEMY_FLAGS_800,
    .init = &N(EVS_NpcInit_Pokey_03),
    .drops = POKEY_MUMMY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 46, 0, 514 },
            .wanderSize = { 200 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 47, 0, 518 },
            .detectSize = { 400 },
        }
    },
    .animations = POKEY_MUMMY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey_01), BTL_ISK_PART_1_FORMATION_00, BTL_ISK_PART_1_STAGE_05),
    NPC_GROUP(N(NpcData_Pokey_02), BTL_ISK_PART_1_FORMATION_00, BTL_ISK_PART_1_STAGE_05),
    NPC_GROUP(N(NpcData_Pokey_03), BTL_ISK_PART_1_FORMATION_01, BTL_ISK_PART_1_STAGE_05),
    {}
};
