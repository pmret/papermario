#include "kmr_05.h"

EvtScript N(EVS_ExitWalk_kmr_03_1) = EVT_EXIT_WALK(60, kmr_05_ENTRY_0, "kmr_03", kmr_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_kmr_02_2) = EVT_EXIT_WALK(60, kmr_05_ENTRY_1, "kmr_02", kmr_02_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GF_KMR02_ReturnedWithGoompa, FALSE)
        Call(MakeNpcs, FALSE, Ref(N(NpcsBefore)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(NpcsAfter)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupFoliage))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_05_ENTRY_0)
        IfEq(GF_KMR05_EnemyWarning, FALSE)
            Exec(N(EVS_GoompaRemark))
            Set(GF_KMR05_EnemyWarning, TRUE)
        EndIf
    EndIf
    Return
    End
};
