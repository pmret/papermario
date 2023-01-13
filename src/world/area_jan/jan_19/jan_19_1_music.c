#include "jan_19.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
