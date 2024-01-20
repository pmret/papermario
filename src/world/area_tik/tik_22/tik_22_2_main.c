#include "tik_22.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(ResetTrackVolumes)) {
    bgm_clear_track_volumes(0, TRACK_VOLS_2);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_tik_21_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(N(ResetTrackVolumes))
    Set(LVar0, tik_22_ENTRY_0)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o46)
    Set(LVar3, MODEL_o47)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("tik_21"), tik_21_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_tik_17_0) = {
    Call(GotoMap, Ref("tik_17"), tik_17_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_17_0) = EVT_EXIT_PIPE_VERTICAL(tik_22_ENTRY_1, COLLIDER_o61, N(EVS_GotoMap_tik_17_0));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_tik_21_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_tik_17_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_o61, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(tik_22_ENTRY_0)
            Set(LVar2, MODEL_o46)
            Set(LVar3, MODEL_o47)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(tik_22_ENTRY_1)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EndSwitch
    Wait(1)
    Return
    End
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
    Set(LVar0, Ref(N(DripVolumes)))
    Exec(N(EVS_CreateDripVolumes))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_22)
    SetUP_CAMERA_NO_LEAD()
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Exec(N(EVS_SetupDrips))
    Call(SetTexPanner, MODEL_mizu, 0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    0,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Wait(1)
    Exec(N(EVS_EnterMap))
    Return
    End
};
