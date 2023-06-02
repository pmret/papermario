#include "tik_07.h"

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 3,
    .volumes = {
        {
            .minPos = { -264,  -61 },
            .maxPos = {  150,  188 },
            .startY = 230,
            .endY   = -10,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {   31,  -20 },
            .maxPos = {  297,  156 },
            .startY = 230,
            .endY   = -10,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {  108, -117 },
            .maxPos = {   56,   43 },
            .startY = 230,
            .endY   = 90,
            .duration = 40,
            .density  = 1,
        },
    }
};

EvtScript N(EVS_SetupDrips) = {
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_RETURN
    EVT_END
};
