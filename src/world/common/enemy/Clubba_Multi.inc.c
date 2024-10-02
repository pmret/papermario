#include "Clubba.h"

EvtScript N(EVS_NpcDefeat_Clubba) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
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

AnimID N(ExtraAnims_Clubba)[] = {
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

AnimID N(ExtraAnims_Clubba_Hitbox)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_LIST_END
};

#ifdef INCLUDE_CLUBBA_WANDER
#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

MobileAISettings N(AISettings_Clubba_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 120,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 12,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 3,
};

EvtScript N(EVS_NpcAI_Clubba_Wander) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 5)
    Call(SetSelfVar, 2, 8)
    Call(SetSelfVar, 3, 12)
    Call(N(WanderMeleeAI_Main), Ref(N(AISettings_Clubba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Clubba_Wander) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_CLUBBA,
    .ai = &N(EVS_NpcAI_Clubba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#ifdef INCLUDE_CLUBBA_PATROL
#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"
#include "world/common/enemy/ai/ClubbaPatrolAI.inc.c"

MobileAISettings N(AISettings_Clubba_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 20,
    .waitTime = 30,
    .alertRadius = 85.0f,
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 12,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 3,
};

EvtScript N(EVS_NpcAI_Clubba_Patrol) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 5)
    Call(SetSelfVar, 2, 8)
    Call(SetSelfVar, 3, 12)
    Call(N(ClubbaPatrolAI_Main), Ref(N(AISettings_Clubba_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_Clubba_Patrol) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_CLUBBA,
    .ai = &N(EVS_NpcAI_Clubba_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#ifdef INCLUDE_CLUBBA_NAPPING
#include "world/common/enemy/ai/ClubbaNappingAI.inc.c"
#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

MobileAISettings N(AISettings_Clubba_Napping) = {
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

EvtScript N(EVS_NpcAI_Clubba_Napping) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 10)
    Call(SetSelfVar, 2, 14)
    Call(SetSelfVar, 3, 18)
    Call(N(ClubbaNappingAI_Main), Ref(N(AISettings_Clubba_Napping)))
    Return
    End
};

NpcSettings N(NpcSettings_Clubba_Napping) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_CLUBBA,
    .ai = &N(EVS_NpcAI_Clubba_Napping),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#include "world/common/enemy/ai/MeleeHitbox.inc.c"

EvtScript N(EVS_NpcAI_Clubba_Hitbox) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetSelfVar, 0, 4)
    Call(SetSelfVar, 1, 32)
    Call(SetSelfVar, 2, 50)
    Call(SetSelfVar, 3, 32)
    Call(SetSelfVar, 4, 3)
    Call(SetSelfVar, 15, SOUND_CLUBBA_SWING)
    Call(N(MeleeHitbox_Main))
    Return
    End
};

NpcSettings N(NpcSettings_Clubba_Hitbox) = {
    .height = 14,
    .radius = 18,
    .level = ACTOR_LEVEL_CLUBBA,
    .ai = &N(EVS_NpcAI_Clubba_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_Clubba),
    .actionFlags = AI_ACTION_08,
};
