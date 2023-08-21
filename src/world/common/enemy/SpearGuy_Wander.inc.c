#include "SpearGuy.h"

#include "world/common/enemy/ai/SpearGuyAI.inc.c"

AnimID N(ExtraAnims_SpearGuy)[] = {
    ANIM_SpearGuy_Anim00,
    ANIM_SpearGuy_Anim03,
    ANIM_SpearGuy_Anim05,
    ANIM_SpearGuy_Anim06,
    ANIM_SpearGuy_Anim07,
    ANIM_SpearGuy_Anim0F,
    ANIM_SpearGuy_Anim10,
    ANIM_SpearGuy_Anim1A,
    ANIM_SpearGuy_Anim1B,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_SpearGuy_Hitbox)[] = {
    ANIM_SpearGuy_Anim00,
    ANIM_LIST_END,
};

EvtScript N(EVS_NpcDefeat_SpearGuy_Hitbox) = {
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

MobileAISettings N(AISettings_SpearGuy_Wander) = {
    .moveSpeed = 1.7f,
    .moveTime = 100,
    .waitTime = 1,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 20,
    .chaseUpdateInterval = 1,
    .chaseRadius = 120.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpearGuy_Wander) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 5)
    EVT_CALL(SetSelfVar, 2, 12)
    EVT_CALL(SetSelfVar, 3, 9)
    EVT_CALL(N(SpearGuyAI_Main), EVT_PTR(N(AISettings_SpearGuy_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpearGuy_Wander) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SPEAR_GUY,
    .ai = &N(EVS_NpcAI_SpearGuy_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_SpearGuy_Hitbox) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 4)
    EVT_CALL(SetSelfVar, 1, 22)
    EVT_CALL(SetSelfVar, 2, 40)
    EVT_CALL(SetSelfVar, 3, 28)
    EVT_CALL(SetSelfVar, 4, 1)
    EVT_CALL(SetSelfVar, 15, 0)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpearGuy_Hitbox) = {
    .height = 8,
    .radius = 20,
    .level = ACTOR_LEVEL_SPEAR_GUY,
    .ai = &N(EVS_NpcAI_SpearGuy_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_SpearGuy_Hitbox),
    .actionFlags = AI_ACTION_08,
};

#define SPEAR_GUY_WANDER_NPC_DATA \
    .settings = &N(NpcSettings_SpearGuy_Wander), \
    .drops = SPEAR_GUY_DROPS, \
    .animations = SPEAR_GUY_ANIMS, \
    .extraAnimations = N(ExtraAnims_SpearGuy), \
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION, \
