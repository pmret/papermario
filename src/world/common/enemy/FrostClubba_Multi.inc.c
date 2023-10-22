#include "FrostClubba.h"

EvtScript N(EVS_NpcDefeat_FrostClubba) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
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
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 3)
    EVT_CALL(SetSelfVar, 2, 7)
    EVT_CALL(SetSelfVar, 3, 6)
    EVT_CALL(N(WanderMeleeAI_Main), EVT_PTR(N(AISettings_FrostClubba_Wander)))
    EVT_RETURN
    EVT_END
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
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 3)
    EVT_CALL(SetSelfVar, 2, 7)
    EVT_CALL(SetSelfVar, 3, 6)
    EVT_CALL(N(ClubbaPatrolAI_Main), EVT_PTR(N(AISettings_FrostClubba_Patrol)))
    EVT_RETURN
    EVT_END
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
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 10)
    EVT_CALL(SetSelfVar, 2, 14)
    EVT_CALL(SetSelfVar, 3, 18)
    EVT_CALL(N(ClubbaNappingAI_Main), EVT_PTR(N(AISettings_FrostClubba_Napping)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_FrostClubba_Napping) = {
    .height = 36,
    .radius = 34,
    .level = ACTOR_LEVEL_CLUBBA, // @bug should be ACTOR_LEVEL_WHITE_CLUBBA
    .ai = &N(EVS_NpcAI_FrostClubba_Napping),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#endif

#include "world/common/enemy/ai/MeleeHitbox.inc.c"

EvtScript N(EVS_NpcAI_FrostClubba_Hitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 4)
    EVT_CALL(SetSelfVar, 1, 32)
    EVT_CALL(SetSelfVar, 2, 48)
    EVT_CALL(SetSelfVar, 3, 30)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_CLUBBA_SWING)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_FrostClubba_Hitbox) = {
    .height = 14,
    .radius = 16,
    .level = ACTOR_LEVEL_WHITE_CLUBBA,
    .ai = &N(EVS_NpcAI_FrostClubba_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_FrostClubba),
    .actionFlags = AI_ACTION_08,
};
