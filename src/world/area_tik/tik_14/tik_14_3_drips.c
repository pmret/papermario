#include "tik_14.h"

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 1,
    .volumes = {
        {
            .minPos = { -215,   35 },
            .maxPos = {  228,  102 },
            .startY = 210,
            .endY   = 0,
            .duration = 60,
            .density  = 2,
        }
    }
};

EvtScript N(EVS_SetupDrips) = {
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_RETURN
    EVT_END
};
