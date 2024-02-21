#include "hos_02.h"

API_CALLABLE(N(FetchEntryID)) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupUnused) = {
    Return
    End
};
