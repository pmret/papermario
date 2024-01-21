#include "FrostClubba.h"

EvtScript N(EVS_NpcDefeat_FrostClubba) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(RemoveNpc, NPC_SELF)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(OnPlayerFled, 1)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

AnimID N(ExtraAnims_FrostClubba)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim0C,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim11,
    ANIM_WorldClubba_Anim12,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_FrostClubba_Hitbox)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_LIST_END
};

#ifdef INCLUDE_FROST_CLUBBA_WANDER
#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

MobileAISettings N(AISettings_FrostClubba_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 7,
    .chaseSpeed = 3.8f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 15,
    .chaseRadius = 200.0f,
    .chaseOffsetDist = 160.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_FrostClubba_Wander) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 3)
    Call(SetSelfVar, 2, 7)
    Call(SetSelfVar, 3, 6)
    Call(N(WanderMeleeAI_Main), Ref(N(AISettings_FrostClubba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_FrostClubba_Wander) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_WHITE_CLUBBA,
    .ai = &N(EVS_NpcAI_FrostClubba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#ifdef INCLUDE_FROST_CLUBBA_PATROL
#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"
#include "world/common/enemy/ai/ClubbaPatrolAI.inc.c"

MobileAISettings N(AISettings_FrostClubba_Patrol) = {
    .moveSpeed = 2.0f,
    .alertRadius = 100.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 7,
    .chaseSpeed = 3.8f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 10,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 50.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_FrostClubba_Patrol) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 3)
    Call(SetSelfVar, 2, 7)
    Call(SetSelfVar, 3, 6)
    Call(N(ClubbaPatrolAI_Main), Ref(N(AISettings_FrostClubba_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_FrostClubba_Patrol) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_WHITE_CLUBBA,
    .ai = &N(EVS_NpcAI_FrostClubba_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#ifdef INCLUDE_FROST_CLUBBA_NAPPING
#include "world/common/enemy/ai/ClubbaNappingAI.inc.c"
#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

MobileAISettings N(AISettings_FrostClubba_Napping) = {
    .moveSpeed = 1.0f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 15,
    .chaseRadius = 200.0f,
    .chaseOffsetDist = 160.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_FrostClubba_Napping) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 10)
    Call(SetSelfVar, 2, 14)
    Call(SetSelfVar, 3, 18)
    Call(N(ClubbaNappingAI_Main), Ref(N(AISettings_FrostClubba_Napping)))
    Return
    End
};

NpcSettings N(NpcSettings_FrostClubba_Napping) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_CLUBBA, /// @bug should be ACTOR_LEVEL_WHITE_CLUBBA
    .ai = &N(EVS_NpcAI_FrostClubba_Napping),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#include "world/common/enemy/ai/MeleeHitbox.inc.c"

EvtScript N(EVS_NpcAI_FrostClubba_Hitbox) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetSelfVar, 0, 4)
    Call(SetSelfVar, 1, 32)
    Call(SetSelfVar, 2, 48)
    Call(SetSelfVar, 3, 30)
    Call(SetSelfVar, 4, 3)
    Call(SetSelfVar, 15, SOUND_CLUBBA_SWING)
    Call(N(MeleeHitbox_Main))
    Return
    End
};

NpcSettings N(NpcSettings_FrostClubba_Hitbox) = {
    .height = 14,
    .radius = 16,
    .level = ACTOR_LEVEL_WHITE_CLUBBA,
    .ai = &N(EVS_NpcAI_FrostClubba_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_FrostClubba),
    .actionFlags = AI_ACTION_08,
};
