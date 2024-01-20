#include "hos_04.h"

API_CALLABLE(N(GetLastEntryID)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DoNothing) = {
    Return
    End
};

EvtScript N(EVS_SetupUnused) = {
    Call(N(GetLastEntryID))
    Switch(LVar0)
        CaseEq(hos_04_ENTRY_0)
            Set(LVar0, -1)
            Exec(N(EVS_DoNothing))
    EndSwitch
    Return
    End
};
