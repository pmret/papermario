#include "tik_25.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_24_0) = EVT_EXIT_WALK(60, tik_25_ENTRY_0, "tik_24", tik_24_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_24_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -140, -110 },
            .maxPos = {  120,  240 },
            .startY = 200,
            .endY   = -135,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {    0, -100 },
            .maxPos = {   90,  235 },
            .startY = 200,
            .endY   = -10,
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

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_25)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(SetTexPanner, MODEL_mizu, 0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
