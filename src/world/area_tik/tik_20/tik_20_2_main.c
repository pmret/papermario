#include "tik_20.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_08_1) = EVT_EXIT_WALK(60, tik_20_ENTRY_0, "tik_08", tik_08_ENTRY_1);
EvtScript N(EVS_ExitWalk_tik_21_0) = EVT_EXIT_WALK(60, tik_20_ENTRY_1, "tik_21", tik_21_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_23_1) = {
    Call(GotoMap, Ref("tik_23"), tik_23_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_23_1) = EVT_EXIT_PIPE_VERTICAL(tik_20_ENTRY_2, COLLIDER_o109, N(EVS_GotoMap_tik_23_1));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_08_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tik_21_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_tik_23_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_o109, 1, 0)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_yuka, .pos = { -190.0,   30.0,  -85.0 }},
    { .colliderID = COLLIDER_yuka2, .pos = {  200.0,   30.0,  -70.0 }},
    { .colliderID = -1 }
};

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -312,  -19 },
            .maxPos = {   52,   46 },
            .startY = 200,
            .endY   = -20,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {  460,  -50 },
            .maxPos = {   40,  185 },
            .startY = 200,
            .endY   = -20,
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

MAP_RODATA_PAD(1,unk);

#include "../common/Flotsam.inc.c"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_20)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_toge, SURFACE_TYPE_SPIKES)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_TIK20_WATER)
    Exec(N(EVS_SetupDrips))
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   70,  100,  100,  130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_nagare, 0)
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
    Wait(1)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(tik_20_ENTRY_0)
        CaseOrEq(tik_20_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        EndCaseGroup
        CaseEq(tik_20_ENTRY_2)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EndCaseGroup
    EndSwitch
    Wait(1)
    Return
    End
};
