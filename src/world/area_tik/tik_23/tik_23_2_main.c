#include "tik_23.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_24_1) = EVT_EXIT_WALK(60, tik_23_ENTRY_0, "tik_24", tik_24_ENTRY_1);

EvtScript N(EVS_GotoMap_tik_20_2) = {
    Call(GotoMap, Ref("tik_20"), tik_20_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_20_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_23_ENTRY_1, COLLIDER_ttd, N(EVS_GotoMap_tik_20_2));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_24_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_tik_20_2)), TRIGGER_WALL_PUSH, COLLIDER_ttd, 1, 0)
    Return
    End
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
    Set(LVar0, Ref(N(DripVolumes)))
    Exec(N(EVS_CreateDripVolumes))
    Return
    End
};

#include "../common/Flotsam.inc.c"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_23)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, tik_23_ENTRY_1)
        EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_ttd, N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_TIK23_WATER)
    ExecWait(N(EVS_SetupDrips))
    Call(SetTexPanner, MODEL_nagare1, 0)
    Call(SetTexPanner, MODEL_o97, 0)
    Call(SetTexPanner, MODEL_o98, 0)
    Call(SetTexPanner, MODEL_o99, 0)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   70, -100,  100, -130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        Set(LVar2, MODEL_bin)
        Exec(N(EVS_Flotsam_Bobbing))
        Wait(5)
        Set(LVar2, MODEL_kan1)
        Exec(N(EVS_Flotsam_Bobbing))
        Wait(5)
        Set(LVar2, MODEL_kan2)
        Exec(N(EVS_Flotsam_Bobbing))
    EndThread
    Return
    End
};
