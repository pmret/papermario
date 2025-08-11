#include "kgr_02.h"

API_CALLABLE(N(HasBombetteExploded)) {
    if (gCollisionStatus.bombetteExploded >= 0) {
        script->varTable[1] = true;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MonitorFriendlyFire) = {
    Set(LVar1, 0)
    Loop(0)
        Call(GetPlayerActionState, LVar0)
        Switch(LVar0)
            CaseEq(ACTION_STATE_HAMMER)
                Wait(10)
                Set(LVar1, true)
            CaseEq(ACTION_STATE_SPIN_POUND)
                Set(LVar1, true)
        EndSwitch
        Call(N(HasBombetteExploded))
        IfNe(LVar1, 0)
            Call(DisablePlayerInput, true)
            Call(ShowMessageAtScreenPos, MSG_MAC_Port_009A, 160, 40)
            Set(LVar1, 0)
            Call(DisablePlayerInput, false)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};
