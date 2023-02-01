#include "hos_04.h"

API_CALLABLE(N(GetLastEntryID)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupUnused) = {
    EVT_CALL(N(GetLastEntryID))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_04_ENTRY_0)
            EVT_SET(LVar0, -1)
            EVT_EXEC(N(EVS_DoNothing))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
