#include "tik_04.h"

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -230,  -40 },
            .maxPos = {  150,   80 },
            .startY = 200,
            .endY   = -10,
            .duration = 50,
            .density  = 1,
        },
        {
            .minPos = {  -50,  100 },
            .maxPos = {  355,   37 },
            .startY = 200,
            .endY   = -135,
            .duration = 80,
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
