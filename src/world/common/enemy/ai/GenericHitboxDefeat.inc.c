#ifndef _GENERIC_HITBOX_DEFEAT_
#define _GENERIC_HITBOX_DEFEAT_

#include "common.h"

EvtScript N(EVS_GenericHitboxDefeat) = {
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

#endif
