#include "tik_22.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(ResetTrackVolumes)) {
    bgm_clear_track_volumes(0, TRACK_VOLS_2);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_tik_21_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(ResetTrackVolumes))
    EVT_SET(LVar0, tik_22_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o46)
    EVT_SET(LVar3, MODEL_o47)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("tik_21"), tik_21_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tik_17_0) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_17"), tik_17_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_17_0) = EVT_EXIT_PIPE_VERTICAL(tik_22_ENTRY_1, COLLIDER_o61, N(EVS_GotoMap_tik_17_0));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_tik_21_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_17_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_o61, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(tik_22_ENTRY_0)
            EVT_SET(LVar2, MODEL_o46)
            EVT_SET(LVar3, MODEL_o47)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(tik_22_ENTRY_1)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -220,  -19 },
            .maxPos = {   60,   46 },
            .startY = 200,
            .endY   = 0,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {   63, -100 },
            .maxPos = {   47,  235 },
            .startY = 200,
            .endY   = 0,
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
    EVT_CALL(SetSpriteShading, SHADING_TIK_22)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_CALL(SetTexPanner, MODEL_mizu, 0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
