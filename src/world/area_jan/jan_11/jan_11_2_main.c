#include "jan_11.h"

#include "world/common/atomic/CreateDarkness.inc.c"

#include "world/common/entity/Pipe.inc.c"

#define DROPLET_MODEL MODEL_o140
#include "world/area_tik/common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -154,  100 },
            .maxPos = {   92,   36 },
            .startY = 200,
            .endY   = 0,
            .duration = 60,
            .density  = 2,
        },
         {
            .minPos = {  212,   10 },
            .maxPos = {   53,  122 },
            .startY = 200,
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

EvtScript N(EVS_GotoMap_jan_09_3) = {
    EVT_CALL(GotoMap, EVT_PTR("jan_09"), jan_09_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_jan_09_3) = EVT_EXIT_PIPE_HORIZONTAL(jan_11_ENTRY_0, COLLIDER_o10, N(EVS_GotoMap_jan_09_3));

EvtScript N(D_80241F38_B72798) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_jan_09_3)), TRIGGER_WALL_PUSH, COLLIDER_o10, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_CreateDarkness))
    EVT_SET(LVar0, EVT_PTR(N(D_80241F38_B72798)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupDrips))
    EVT_RETURN
    EVT_END
};
