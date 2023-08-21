#include "HammerBros.h"

#include "world/common/enemy/ai/RangedAttackAI.inc.c"

#include "world/common/todo/GetEncounterEnemyIsOwner.inc.c"

EvtScript N(EVS_NpcDefeat_HammerBros_Hammer) = {
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

MobileAISettings N(AISettings_HammerBros) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .alertOffsetDist = 20.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 3,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 20.0f,
};

EvtScript N(EVS_NpcAI_HammerBros) = {
    EVT_CALL(SetSelfVar, 0, 70)
    EVT_CALL(SetSelfVar, 1, 3)
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 6)
    EVT_CALL(N(RangedAttackAI_Main), EVT_PTR(N(AISettings_HammerBros)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HammerBros_Wander) = {
    .height = 36,
    .radius = 24,
    .level = ACTOR_LEVEL_HAMMER_BROS,
    .ai = &N(EVS_NpcAI_HammerBros),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

MobileAISettings N(AISettings_HammerBros_Hammer) = {
    .moveSpeed = 5.4f,
    .alertRadius = 13.0f,
    .alertOffsetDist = 1.4f,
    .playerSearchInterval = -1,
};

EvtScript N(EVS_NpcAI_HammerBros_Hammer) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 3)
    EVT_CALL(SetSelfVar, 2, 20)
    EVT_CALL(N(ProjectileAI_Main), EVT_PTR(N(AISettings_HammerBros_Hammer)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NoAI_HammerBros_Hammer) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_HammerBros_Hammer) = {
    EVT_CALL(N(GetEncounterEnemyIsOwner))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NoAI_HammerBros_Hammer)))
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
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_HammerBros_Hammer)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HammerBros_Hammer) = {
    .height = 12,
    .radius = 12,
    .ai = &N(EVS_NpcAI_HammerBros_Hammer),
    .onHit = &N(EVS_NpcHit_HammerBros_Hammer),
    .onDefeat = &N(EVS_NpcDefeat_HammerBros_Hammer),
    .actionFlags = AI_ACTION_08,
};

AnimID N(ExtraAnims_HammerBros_Hammer)[] = {
    ANIM_HammerBros_Anim0D,
    ANIM_LIST_END
};
