#include "MontyMole.h"

#include "world/common/enemy/ai/MontyMoleAI.inc.c"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_MontyMole_Stone) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetSelfVar, 0, 5)
            Call(RemoveNpc, NPC_SELF)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(OnPlayerFled, 1)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, TRUE)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
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
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_FLIP_INSTANTLY, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Label(0)
    Call(RandInt, 15, LVar0)
    Add(LVar0, 15)
    Wait(LVar0)
    Call(N(MontyMoleAI_Main), Ref(N(AISettings_MontyMole_StoneThrower)))
    Return
    End
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
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 0)
    Call(SetSelfVar, 2, 17)
    Call(SetSelfVar, 3, 17)
    Call(N(ProjectileAI_Main), Ref(N(AISettings_MontyMole_Stone)))
    Return
    End
};

EvtScript N(EVS_NpcHit_MontyMole_Stone_DoNothing) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_MontyMole_Stone) = {
    Call(N(GetEncounterEnemyIsOwner))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcHit_MontyMole_Stone_DoNothing)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_SPIN)
            Call(SetSelfVar, 0, 3)
            Call(N(ProjectileAI_Reflect))
            IfEq(LVar0, 0)
                Return
            EndIf
        EndCaseGroup
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Call(SetSelfVar, 0, 4)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(SetSelfVar, 0, 0)
        EndCaseGroup
        CaseDefault
            Call(SetBattleAsScripted)
        EndCaseGroup
    EndSwitch
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_MontyMole_Stone)))
    Return
    End
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
