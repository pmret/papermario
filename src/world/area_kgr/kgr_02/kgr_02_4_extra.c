#include "kgr_02.h"

API_CALLABLE(N(HasBombetteExploded)) {
    if (gCollisionStatus.bombetteExploded >= 0) {
        script->varTable[1] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MonitorFriendlyFire) = {
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(ACTION_STATE_HAMMER)
                EVT_WAIT(10)
                EVT_SET(LVar1, TRUE)
            EVT_CASE_EQ(ACTION_STATE_SPIN_POUND)
                EVT_SET(LVar1, TRUE)
        EVT_END_SWITCH
        EVT_CALL(N(HasBombetteExploded))
        EVT_IF_NE(LVar1, 0)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Port_009A, 160, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
