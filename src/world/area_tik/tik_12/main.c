#include "tik_12.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_GotoMap_tik_04_3) = {
    Call(GotoMap, Ref("tik_04"), tik_04_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_04_3) = EVT_EXIT_PIPE_HORIZONTAL(tik_12_ENTRY_0, COLLIDER_o48, N(EVS_GotoMap_tik_04_3));

EvtScript N(EVS_BindExitTriggers) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o48, COLLIDER_FLAGS_UPPER_MASK)
    BindTrigger(Ref(N(EVS_ExitPipe_tik_04_3)), TRIGGER_WALL_PUSH, COLLIDER_o48, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_12)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupDrips))
    Call(EnableTexPanning, MODEL_mizu, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o48, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_o48, N(EVS_BindExitTriggers))
    Wait(1)
    Return
    End
};
