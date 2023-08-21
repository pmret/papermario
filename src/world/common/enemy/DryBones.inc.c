#include "DryBones.h"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"
#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_ThrownBone) = {
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

MobileAISettings N(AISettings_DryBones) = {
    .moveSpeed = 2.0f,
    .moveTime = 20,
    .waitTime = 3,
    .alertRadius = 120.0f,
    .alertOffsetDist = 120.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 1.0f,
    .chaseRadius = 150.0f,
    .chaseOffsetDist = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_DryBones) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 15)
    EVT_CALL(SetSelfVar, 2, 10)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(N(RangedAttackAI_Main), EVT_PTR(N(AISettings_DryBones)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_DryBones) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_DRY_BONES,
    .ai = &N(EVS_NpcAI_DryBones),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

MobileAISettings N(AISettings_ThrownBone) = {
    .moveSpeed = 7.5f,
    .alertRadius = 1.1f,
    .alertOffsetDist = 0.18f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_ThrownBone) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 3)
    EVT_CALL(SetSelfVar, 2, 15)
    EVT_CALL(SetSelfVar, 3, 15)
    EVT_CALL(N(ProjectileAI_Main), EVT_PTR(N(AISettings_ThrownBone)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NoAI_ThrownBone) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_ThrownBone) = {
    EVT_CALL(N(GetEncounterEnemyIsOwner))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NoAI_ThrownBone)))
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
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
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
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ThrownBone)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ThrownBone) = {
    .height = 12,
    .radius = 12,
    .ai = &N(EVS_NpcAI_ThrownBone),
    .onHit = &N(EVS_NpcHit_ThrownBone),
    .onDefeat = &N(EVS_NpcDefeat_ThrownBone),
    .actionFlags = AI_ACTION_08,
};
