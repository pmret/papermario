#include "tik_06.h"

#include "world/common/atomic/tik_DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -512,  -14 },
            .maxPos = {  173,   84 },
            .unk_10 = 200,
            .unk_14 = -10,
            .unk_18 = 60,
            .density = 2,
        },
        {
            .minPos = {   63, -105 },
            .maxPos = {  103,  182 },
            .unk_10 = 200,
            .unk_14 = -10,
            .unk_18 = 60,
            .density = 1,
        },
    }
};

EvtScript N(EVS_SetupDrips) = {
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_RETURN
    EVT_END
};
