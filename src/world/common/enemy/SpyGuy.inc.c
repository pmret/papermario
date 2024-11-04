#include "SpyGuy.h"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

API_CALLABLE(N(SetSpyGuyInstigatorValue)) {
    script->owner1.enemy->instigatorValue = 3;
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_SpyGuyRock) = {
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

MobileAISettings N(AISettings_SpyGuy) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 90.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.8f,
    .chaseTurnRate = 8,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpyGuy) = {
    Call(N(SetSpyGuyInstigatorValue))
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 12)
    Call(SetSelfVar, 2, 5)
    Call(SetSelfVar, 3, 2)
    Call(N(RangedAttackAI_Main), Ref(N(AISettings_SpyGuy)))
    Return
    End
};

NpcSettings N(NpcSettings_SpyGuy) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_SPY_GUY,
    .ai = &N(EVS_NpcAI_SpyGuy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

MobileAISettings N(AISettings_SpyGuyRock) = {
    .moveSpeed = 8.0f,
    .alertRadius = 4.0f,
    .alertOffsetDist = 0.5f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_SpyGuyRock_Projectile) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 0)
    Call(SetSelfVar, 2, 12)
    Call(SetSelfVar, 3, 13)
    Call(N(ProjectileAI_Main), Ref(N(AISettings_SpyGuyRock)))
    Return
    End
};

EvtScript N(EVS_NpcAI_SpyGuyRock_Projectile_None) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_SpyGuyRock) = {
    Call(N(GetEncounterEnemyIsOwner))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpyGuyRock_Projectile_None)))
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
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_SpyGuyRock_Projectile)))
    Return
    End
};

NpcSettings N(NpcSettings_SpyGuyRock) = {
    .height = 7,
    .radius = 7,
    .ai = &N(EVS_NpcAI_SpyGuyRock_Projectile),
    .onHit = &N(EVS_NpcHit_SpyGuyRock),
    .onDefeat = &N(EVS_NpcDefeat_SpyGuyRock),
    .actionFlags = AI_ACTION_08,
};
