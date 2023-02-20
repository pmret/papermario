#include "common.h"
#include "script_api/battle.h"
#include "model.h"

#define NAMESPACE battle_move_peach_beam

#include "battle/common/move/StarBeamSupport.inc.c"

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(beforeUsePower))
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(N(ProcessPeachStarBeam), 1)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(N(GetStage))
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_PEACH_BEAM | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(N(GetStage))
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(N(unkStarBeamBgFunc))
    EVT_CALL(func_80276EFC)
    EVT_EXEC_WAIT(N(afterUsePower))
    EVT_RETURN
    EVT_END
};
