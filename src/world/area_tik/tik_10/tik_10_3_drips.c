#include "tik_10.h"

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -220,   20 },
            .maxPos = {  110,   50 },
            .startY = 250,
            .endY   = 20,
            .duration = 60,
            .density  = 3,
        },
        {
            .minPos = {  160,   10 },
            .maxPos = {  160,   60 },
            .startY = 250,
            .endY   = 20,
            .duration = 60,
            .density  = 1,
        }
    }
};

EvtScript N(EVS_SetupDrips) = {
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_RETURN
    EVT_END
};
