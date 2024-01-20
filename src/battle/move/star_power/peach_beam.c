#include "common.h"
#include "script_api/battle.h"
#include "model.h"

#define NAMESPACE battle_move_peach_beam

#include "battle/common/move/StarPowerSupport.inc.c"
#include "battle/common/move/StarBeamSupport.inc.c"

EvtScript N(EVS_UsePower) = {
    ExecWait(N(EVS_StarPower_WishForBeam))
    Call(AddBattleCamZoom, 100)
    Call(MoveBattleCamOver, 20)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Thread
        Call(N(ProcessPeachStarBeam), TRUE)
    EndThread
    Wait(10)
    Loop(0)
        Wait(1)
        Call(N(GetStage))
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_PEACH_BEAM | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Loop(0)
        Wait(1)
        Call(N(GetStage))
        IfEq(LVar0, 2)
            BreakLoop
        EndIf
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(N(unkStarBeamBgFunc))
    Call(PlayerYieldTurn)
    ExecWait(N(EVS_StarPower_EndWish))
    Return
    End
};
