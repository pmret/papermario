#include "tik_07.h"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_04_1) = EVT_EXIT_WALK(60, tik_07_ENTRY_0, "tik_04", tik_04_ENTRY_1);

EvtScript N(EVS_GotoMap_tik_07_2) = {
    Call(GotoMap, Ref("tik_07"), tik_07_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_tik_07_1) = {
    Call(GotoMap, Ref("tik_07"), tik_07_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_tik_07_2) = EVT_EXIT_PIPE_VERTICAL(tik_07_ENTRY_1, COLLIDER_dokan_e1, N(EVS_GotoMap_tik_07_2));
EvtScript N(EVS_ExitWalk_tik_07_1) = EVT_EXIT_PIPE_VERTICAL(tik_07_ENTRY_2, COLLIDER_dokan_e2, N(EVS_GotoMap_tik_07_1));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tik_07_2)), TRIGGER_FLOOR_TOUCH, COLLIDER_dokan_e1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tik_07_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_dokan_e2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_07)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_SetupDrips))
    Exec(N(EVS_SetupPlatforms))
    Wait(1)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, tik_07_ENTRY_0)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EndIf
    Wait(1)
    Return
    End
};
