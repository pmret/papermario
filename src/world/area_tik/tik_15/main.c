#include "tik_15.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_14_1) = EVT_EXIT_WALK(60, tik_15_ENTRY_0, "tik_14", tik_14_ENTRY_1);

EvtScript N(EVS_GotoMap_mac_02_5) = {
    Call(GotoMap, Ref("mac_02"), mac_02_ENTRY_5)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_mac_02_5) = EVT_EXIT_PIPE_HORIZONTAL(tik_15_ENTRY_1, COLLIDER_o59, N(EVS_GotoMap_mac_02_5));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_mac_02_5)), TRIGGER_WALL_PUSH, COLLIDER_o59, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_15)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupDrips))
    Call(EnableTexPanning, MODEL_mizu, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    ExecWait(N(EVS_MakeEntities))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, tik_15_ENTRY_1)
        EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_o59, N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    Wait(1)
    Return
    End
};
