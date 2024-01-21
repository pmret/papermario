#include "PiranhaPlant.h"

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

#include "world/common/enemy/ai/GenericHitboxDefeat.inc.c"

MobileAISettings N(AISettings_PiranhaPlant) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(EVS_NpcAI_PiranhaPlant) = {
    Call(SetSelfVar, 7, 0)
    Call(SetSelfVar, 8, 12)
    Call(SetSelfVar, 9, 11)
    Call(SetSelfVar, 10, 14)
    Call(SetSelfVar, 11, 9)
    Call(SetSelfVar, 12, 25)
    Call(SetSelfVar, 13, -1)
    Call(SetSelfVar, 14, 10)
    Call(SetSelfVar, 15, 15)
    Call(N(PiranhaPlantAI_Main), Ref(N(AISettings_PiranhaPlant)))
    Return
    End
};

NpcSettings N(NpcSettings_PiranhaPlant) = {
    .height = 32,
    .radius = 26,
    .level = ACTOR_LEVEL_PIRANHA_PLANT,
    .ai = &N(EVS_NpcAI_PiranhaPlant),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcAI_PiranhaPlant_Hitbox) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetSelfVar, 0, 10)
    Call(SetSelfVar, 1, 18)
    Call(SetSelfVar, 4, 3)
    Call(SetSelfVar, 15, SOUND_PIRANHA_BITE)
    Call(N(MeleeHitbox_Main))
    Return
    End
};

EvtScript N(EVS_8024411C) = {
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

NpcSettings N(NpcSettings_PiranhaPlant_Hitbox) = {
    .height = 18,
    .radius = 18,
    .level = ACTOR_LEVEL_PIRANHA_PLANT,
    .ai = &N(EVS_NpcAI_PiranhaPlant_Hitbox),
    .onDefeat = &N(EVS_GenericHitboxDefeat),
    .actionFlags = AI_ACTION_08,
};
