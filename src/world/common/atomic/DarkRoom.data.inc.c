#include "common.h"

EvtScript N(EVS_CreateDarkness) = {
    EVT_THREAD
        EVT_CALL(N(DarkRoomUpdate))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
