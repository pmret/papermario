#include "isk_02.h"

#include "world/common/enemy/PokeyMummy.inc.c"

EvtScript N(EVS_NpcIdle_Pokey_01) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Label(1)
    IfEq(AF_ISK02_OpeningSarcophagus1, FALSE)
        Wait(1)
        Goto(1)
    EndIf
    Wait(15)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
    Call(NpcMoveTo, NPC_SELF, -315, 455, 10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PokeyMummy)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Pokey_02) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Label(1)
    IfEq(AF_ISK02_OpeningSarcophagus2, FALSE)
        Wait(1)
        Goto(1)
    EndIf
    Wait(15)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
    Call(NpcMoveTo, NPC_SELF, -145, 535, 10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PokeyMummy)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Pokey_03) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Label(1)
    IfEq(AF_ISK02_OpeningSarcophagus3, FALSE)
        Wait(1)
        Goto(1)
    EndIf
    Wait(15)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
    Call(NpcMoveTo, NPC_SELF, 50, 550, 10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PokeyMummy)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey_01)))
    Call(SetOwnerInstigatorValue, 3)
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey_02) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey_02)))
    Call(SetOwnerInstigatorValue, 3)
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey_03) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey_03)))
    Call(SetOwnerInstigatorValue, 3)
    Return
    End
};

NpcData N(NpcData_Pokey_01) = {
    .id = NPC_Pokey_01,
    .pos = { -296.0f, 0.0f, 421.0f },
    .yaw = 304,
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
    .init = &N(EVS_NpcInit_Pokey_01),
    .settings = &N(NpcSettings_PokeyMummy),
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcData N(NpcData_Pokey_02) = {
    .id = NPC_Pokey_02,
    .pos = { -133.0f, 0.0f, 497.0f },
    .yaw = 284,
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
    .init = &N(EVS_NpcInit_Pokey_02),
    .settings = &N(NpcSettings_PokeyMummy),
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcData N(NpcData_Pokey_03) = {
    .id = NPC_Pokey_03,
    .pos = { 45.0f, 0.0f, 505.0f },
    .yaw = 264,
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
    .init = &N(EVS_NpcInit_Pokey_03),
    .settings = &N(NpcSettings_PokeyMummy),
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey_01), BTL_ISK_1_FORMATION_00, BTL_ISK_1_STAGE_05),
    NPC_GROUP(N(NpcData_Pokey_02), BTL_ISK_1_FORMATION_00, BTL_ISK_1_STAGE_05),
    NPC_GROUP(N(NpcData_Pokey_03), BTL_ISK_1_FORMATION_01, BTL_ISK_1_STAGE_05),
    {}
};
