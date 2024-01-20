
#include "kmr_09.h"

EvtScript N(EVS_ExitWalk_kmr_02_0) = EVT_EXIT_WALK(60, kmr_09_ENTRY_0, "kmr_02", kmr_02_ENTRY_0);
EvtScript N(EVS_ExitWalk_kmr_06_0) = EVT_EXIT_WALK(60, kmr_09_ENTRY_1, "kmr_06", kmr_06_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Set(GF_MAP_GoombaRoad, TRUE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    BindTrigger(Ref(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_kan, 1, 0)
    Return
    End
};
