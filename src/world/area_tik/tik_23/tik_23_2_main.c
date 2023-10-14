#include "tik_23.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_24_1) = EVT_EXIT_WALK(60, tik_23_ENTRY_0, "tik_24", tik_24_ENTRY_1);

EvtScript N(EVS_GotoMap_tik_20_2) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_20"), tik_20_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_20_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_23_ENTRY_1, COLLIDER_ttd, N(EVS_GotoMap_tik_20_2));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_24_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_20_2)), TRIGGER_WALL_PUSH, COLLIDER_ttd, 1, 0)
    EVT_RETURN
    EVT_END
};

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -180,  100 },
            .maxPos = {  160,   36 },
            .startY = 200,
            .endY   = -20,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {  265, -120 },
            .maxPos = {   25,  250 },
            .startY = 200,
            .endY   = -20,
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

#include "../common/Flotsam.inc.c"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_23)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, tik_23_ENTRY_1)
        EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_ttd, N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_TIK23_WATER)
    EVT_EXEC_WAIT(N(EVS_SetupDrips))
    EVT_CALL(SetTexPanner, MODEL_nagare1, 0)
    EVT_CALL(SetTexPanner, MODEL_o97, 0)
    EVT_CALL(SetTexPanner, MODEL_o98, 0)
    EVT_CALL(SetTexPanner, MODEL_o99, 0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   70, -100,  100, -130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, MODEL_bin)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
        EVT_WAIT(5)
        EVT_SET(LVar2, MODEL_kan1)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
        EVT_WAIT(5)
        EVT_SET(LVar2, MODEL_kan2)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
