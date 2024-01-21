#include "kmr_04.h"

EvtScript N(EVS_ExitWalk_kmr_03_0) = EVT_EXIT_WALK(60, kmr_04_ENTRY_0, "kmr_03", kmr_03_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, 1)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kmr_04_ENTRY_A)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        Exec(EnterPostPipe)
        Exec(N(EVS_BindExitTriggers))
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(AF_KMR_09, FALSE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupFoliage))
    Exec(N(EVS_SetNormalMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit1, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
