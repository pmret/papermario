#include "tik_14.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_15_0) = EVT_EXIT_WALK(60, tik_14_ENTRY_1, "tik_15", tik_15_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_21_2) = {
    Call(GotoMap, Ref("tik_21"), tik_21_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_21_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_14_ENTRY_0, COLLIDER_o47, N(EVS_GotoMap_tik_21_2));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitPipe_tik_21_2)), TRIGGER_WALL_PUSH, COLLIDER_o47, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tik_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o47, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(tik_14_ENTRY_0)
            EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_o47, N(EVS_BindExitTriggers))
        CaseEq(tik_14_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_14)
    SetUP_CAMERA_NO_LEAD()
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupDrips))
    ExecWait(N(EVS_MakeEntities))
    Call(EnableTexPanning, MODEL_mizu, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0, -200, -100, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o47, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
