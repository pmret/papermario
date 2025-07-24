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
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
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
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 1, 5)
    Call(SetSelfVar, 2, 12)
    Call(SetSelfVar, 3, 9)
    Call(N(SpearGuyAI_Main), Ref(N(AISettings_SpearGuy_Wander)))
    Return
    End
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
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(SetSelfVar, 0, 4)
    Call(SetSelfVar, 1, 22)
    Call(SetSelfVar, 2, 40)
    Call(SetSelfVar, 3, 28)
    Call(SetSelfVar, 4, 1)
    Call(SetSelfVar, 15, 0)
    Call(N(MeleeHitbox_Main))
    Return
    End
};

NpcSettings N(NpcSettings_SpearGuy_Hitbox) = {
    .height = 8,
    .radius = 20,
    .level = ACTOR_LEVEL_SPEAR_GUY,
    .ai = &N(EVS_NpcAI_SpearGuy_Hitbox),
    .onDefeat = &N(EVS_NpcDefeat_SpearGuy_Hitbox),
    .actionFlags = AI_ACTION_08,
};
