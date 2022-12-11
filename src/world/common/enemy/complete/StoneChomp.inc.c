
#include "StoneChomp.h"

#include "world/common/enemy/ai/StoneChompAI.inc.c"
#include "world/area_isk/StoneChompFX.inc.c"

EvtScript N(EVS_NpcAuxAI_StoneChomp) = {
    EVT_CALL(N(StoneChompFXA))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_StoneChomp) = {
    .moveSpeed = 2.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 5.3f,
    .chaseTurnRate = 70,
    .chaseUpdateInterval = 10,
    .chaseRadius = 500.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_StoneChomp) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(StoneChompFXB))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_CALL(N(StoneChompAI_Main), EVT_PTR(N(AISettings_StoneChomp)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_StoneChomp) = {
    EVT_CALL(SetBattleMusic, SONG_SPECIAL_BATTLE)
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(EVS_NpcHitRecoil)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_SPIN)
            EVT_THREAD
                EVT_CALL(func_800458CC, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_LOOP(30)
                        EVT_ADD(LVarA, 40)
                        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVarA, 0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_StoneChomp) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(N(StoneChompFXC))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_StoneChomp) = {
    .height = 32,
    .radius = 32,
    .level = 14,
    .otherAI = &N(EVS_NpcAuxAI_StoneChomp),
    .ai = &N(EVS_NpcAI_StoneChomp),
    .onHit = &N(EVS_NpcHit_StoneChomp),
    .onDefeat = &N(EVS_NpcDefeat_StoneChomp),
};
