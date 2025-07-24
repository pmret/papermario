#include "FrostPiranha.h"

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

#include "world/common/enemy/ai/GenericHitboxDefeat.inc.c"

MobileAISettings N(AISettings_FrostPiranha) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(EVS_NpcAI_FrostPiranha) = {
    Call(SetSelfVar, 7, 1)
    Call(SetSelfVar, 8, 10)
    Call(SetSelfVar, 9, 9)
    Call(SetSelfVar, 10, 12)
    Call(SetSelfVar, 11, 7)
    Call(SetSelfVar, 12, 30)
    Call(SetSelfVar, 13, 15)
    Call(SetSelfVar, 14, 18)
    Call(SetSelfVar, 15, 15)
    Call(N(PiranhaPlantAI_Main), Ref(N(AISettings_FrostPiranha)))
    Return
    End
};

NpcSettings N(NpcSettings_FrostPiranha) = {
    .height = 50,
    .radius = 36,
    .level = ACTOR_LEVEL_FROST_PIRANHA,
    .ai = &N(EVS_NpcAI_FrostPiranha),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_FrostPiranha_Hitbox) = {
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(SetSelfVar, 0, 14)
    Call(SetSelfVar, 1, 28)
    Call(SetSelfVar, 4, 3)
    Call(SetSelfVar, 15, SOUND_PIRANHA_BITE)
    Call(N(MeleeHitbox_Main))
    Return
    End
};

EvtScript N(EVS_802425A8) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_NONE)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(GetSelfAnimationFromTable, ENEMY_ANIM_INDEX_HIT, LVar0)
            ExecWait(EVS_NpcHitRecoil)
        EndCaseGroup
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_FrostPiranha_Hitbox) = {
    .height = 20,
    .radius = 28,
    .level = ACTOR_LEVEL_FROST_PIRANHA,
    .ai = &N(EVS_NpcAI_FrostPiranha_Hitbox),
    .onDefeat = &N(EVS_GenericHitboxDefeat),
};

AnimID N(ExtraAnims_FrostPiranha_Hitbox)[] = {
    ANIM_LargePiranha_Frost_Anim00,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_FrostPiranha)[] = {
    ANIM_LargePiranha_Frost_Anim00,
    ANIM_LargePiranha_Frost_Anim01,
    ANIM_LargePiranha_Frost_Anim0E,
    ANIM_LargePiranha_Frost_Anim05,
    ANIM_LargePiranha_Frost_Anim06,
    ANIM_LargePiranha_Frost_Anim18,
    ANIM_LargePiranha_Frost_Anim17,
    ANIM_LIST_END
};
