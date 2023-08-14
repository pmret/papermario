#include "nok_03.h"

#include "world/common/enemy/Fuzzy_Wander.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/npc/Koopa.inc.c"

EvtScript N(EVS_NpcIdle_FuzzyBoss) = {
    EVT_THREAD
        EVT_LABEL(0)
            EVT_CALL(GetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetNpcPos, NPC_KoopersShell, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_LABEL(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_03, LVar3, LVar4, LVar5)
        EVT_SET(LVar6, LVar3)
        EVT_SUB(LVar6, LVar0)
        EVT_IF_LT(LVar6, 100)
            EVT_ADD(LVar3, 100)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar3, LVar4, LVar5, 10 * DT)
            EVT_SET(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_RAN_AWAY)
        EVT_END_IF
        EVT_IF_GT(LVar3, 1200)
            EVT_CALL(SetNpcPos, NPC_Fuzzy_03, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
            EVT_CALL(EnableNpcShadow, NPC_KoopersShell, FALSE)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Fuzzy_01) = {
    EVT_WAIT(5)
    EVT_LABEL(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -400)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 6)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.2))
    EVT_ADD(LVar0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8)
    EVT_SUB(LVar0, 15)
    EVT_ADD(LVar2, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar2, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.8))
    EVT_CALL(NpcJump0, NPC_SELF, -341, 0, 23, 15)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Fuzzy_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Fuzzy_02) = {
    EVT_WAIT(5)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -140)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 6)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Fuzzy_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_01) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy_01)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_02) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FuzzyBoss) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_RAN_AWAY)
        EVT_CALL(SetNpcFlagBits, NPC_Fuzzy_03, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_KoopersShell, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_KoopersShell, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_FuzzyBoss)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopersShell) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .pos = { -388.0f, 100.0f, -107.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -388, 100, -107 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -388, 0, -107 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_Fuzzy_01),
    .settings = &N(NpcSettings_Fuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = FUZZY_DROPS,
    .animations = FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .pos = { -76.0f, 118.0f, -43.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -76, 118, -43 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -76, 118, -43 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_Fuzzy_02),
    .settings = &N(NpcSettings_Fuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = FUZZY_DROPS,
    .animations = FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_FuzzyBoss)[] = {
    {
        .id = NPC_Fuzzy_03,
        .pos = { -540.0f, 0.0f, 0.0f },
        .yaw = 0,
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
        .init = &N(EVS_NpcInit_FuzzyBoss),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = FUZZY_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KoopersShell,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopersShell),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = FUZZY_DROPS,
        .animations = KOOPER_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy_01), BTL_NOK_FORMATION_16, BTL_NOK_STAGE_01),
    NPC_GROUP(N(NpcData_Fuzzy_02), BTL_NOK_FORMATION_16, BTL_NOK_STAGE_01),
    NPC_GROUP(N(NpcData_FuzzyBoss)),
    {}
};
