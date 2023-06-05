#include "tik_08.h"

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -519,  -19 },
            .maxPos = {  259,   46 },
            .startY = 200,
            .endY   = -10,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {  133, -100 },
            .maxPos = {   45,  235 },
            .startY = 200,
            .endY   = -10,
            .duration = 60,
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
