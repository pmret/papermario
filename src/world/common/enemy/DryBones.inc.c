#include "DryBones.h"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"
#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_ThrownBone) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetSelfVar, 0, 5)
            Call(RemoveNpc, NPC_SELF)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(OnPlayerFled, 1)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
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
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 15)
    Call(SetSelfVar, 2, 10)
    Call(SetSelfVar, 3, 2)
    Call(N(RangedAttackAI_Main), Ref(N(AISettings_DryBones)))
    Return
    End
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
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 3)
    Call(SetSelfVar, 2, 15)
    Call(SetSelfVar, 3, 15)
    Call(N(ProjectileAI_Main), Ref(N(AISettings_ThrownBone)))
    Return
    End
};

EvtScript N(EVS_NoAI_ThrownBone) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_ThrownBone) = {
    Call(N(GetEncounterEnemyIsOwner))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NoAI_ThrownBone)))
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
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
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
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ThrownBone)))
    Return
    End
};

NpcSettings N(NpcSettings_ThrownBone) = {
    .height = 12,
    .radius = 12,
    .ai = &N(EVS_NpcAI_ThrownBone),
    .onHit = &N(EVS_NpcHit_ThrownBone),
    .onDefeat = &N(EVS_NpcDefeat_ThrownBone),
    .actionFlags = AI_ACTION_08,
};
