#include "MontyMole.h"

#include "world/common/enemy/ai/MontyMoleAI.inc.c"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_MontyMole_Stone) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetSelfVar, 0, 5)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(OnPlayerFled, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_MontyMole_StoneThrower) = {
    .moveSpeed = 1.7f,
    .moveTime = 90,
    .alertRadius = 110.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 7.5f,
    .chaseRadius = 110.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_StoneThrower) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_200000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_LABEL(0)
    EVT_CALL(RandInt, 15, LVar0)
    EVT_ADD(LVar0, 15)
    EVT_WAIT(LVar0)
    EVT_CALL(N(MontyMoleAI_Main), EVT_PTR(N(AISettings_MontyMole_StoneThrower)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MontyMole_StoneThrower) = {
    .height = 20,
    .radius = 24,
    .level = ACTOR_LEVEL_MONTY_MOLE,
    .ai = &N(EVS_NpcAI_MontyMole_StoneThrower),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_08,
};

MobileAISettings N(AISettings_MontyMole_Stone) = {
    .moveSpeed = 8.3f,
    .alertRadius = 2.5f,
    .alertOffsetDist = 0.4f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_MontyMole_Stone) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_CALL(SetSelfVar, 2, 17)
    EVT_CALL(SetSelfVar, 3, 17)
    EVT_CALL(N(ProjectileAI_Main), EVT_PTR(N(AISettings_MontyMole_Stone)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_MontyMole_Stone_DoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_MontyMole_Stone) = {
    EVT_CALL(N(GetEncounterEnemyIsOwner))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcHit_MontyMole_Stone_DoNothing)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
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
            EVT_CALL(SetBattleAsScripted)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MontyMole_Stone)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MontyMole_Stone) = {
    .height = 12,
    .radius = 12,
    .ai = &N(EVS_NpcAI_MontyMole_Stone),
    .onHit = &N(EVS_NpcHit_MontyMole_Stone),
    .onDefeat = &N(EVS_NpcDefeat_MontyMole_Stone),
    .actionFlags = AI_ACTION_08,
};

#define MONTY_MOLE_STONE_HITBOX(npcID) \
{ \
    .id = npcID, \
    .settings = &N(NpcSettings_MontyMole_Stone), \
    .pos = { NPC_DISPOSE_LOCATION }, \
    .yaw = 90, \
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DROPS, \
    .drops = NO_DROPS, \
    .territory = { \
        .wander = { \
            .isFlying = TRUE, \
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED, \
            .wanderShape = SHAPE_CYLINDER, \
            .centerPos  = { NPC_DISPOSE_LOCATION }, \
            .wanderSize = { 0 }, \
            .detectShape = SHAPE_CYLINDER, \
            .detectPos  = { 0, 0, 0 }, \
            .detectSize = { 0 }, \
        } \
    }, \
    .animations = { \
        .idle   = ANIM_MontyMole_Anim0F, \
        .walk   = ANIM_MontyMole_Anim0F, \
        .run    = ANIM_MontyMole_Anim0F, \
        .chase  = ANIM_MontyMole_Anim0F, \
        .anim_4 = ANIM_MontyMole_Anim0F, \
        .anim_5 = ANIM_MontyMole_Anim0F, \
        .death  = ANIM_MontyMole_Anim0F, \
        .hit    = ANIM_MontyMole_Anim0F, \
        .anim_8 = ANIM_MontyMole_Anim0F, \
        .anim_9 = ANIM_MontyMole_Anim0F, \
        .anim_A = ANIM_MontyMole_Anim0F, \
        .anim_B = ANIM_MontyMole_Anim0F, \
        .anim_C = ANIM_MontyMole_Anim0F, \
        .anim_D = ANIM_MontyMole_Anim0F, \
        .anim_E = ANIM_MontyMole_Anim0F, \
        .anim_F = ANIM_MontyMole_Anim0F, \
    }, \
}
