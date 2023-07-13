#include "tik_03.h"

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = {  107,  -95 },
            .maxPos = {  208,  155 },
            .startY = 200,
            .endY   = -10,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = { -216,  -90 },
            .maxPos = {   82,  155 },
            .startY = 270,
            .endY   = 60,
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
