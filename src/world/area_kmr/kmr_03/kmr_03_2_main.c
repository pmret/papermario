#include "kmr_03.h"

EvtScript N(EVS_ExitWalk_kmr_04_0) = EVT_EXIT_WALK(60, kmr_03_ENTRY_0, "kmr_04", kmr_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_kmr_05_0) = EVT_EXIT_WALK(60, kmr_03_ENTRY_1, "kmr_05", kmr_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(AF_KMR_08, FALSE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kmr_03_ENTRY_2)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        Exec(N(EVS_BindExitTriggers))
        Exec(N(EVS_Scene_FallingDown))
    EndIf
    Wait(1)
    Return
    End
};
