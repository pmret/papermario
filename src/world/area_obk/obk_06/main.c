#include "obk_06.h"

EvtScript N(EVS_ExitWalk_obk_02_2) = EVT_EXIT_WALK(60, obk_06_ENTRY_1, "obk_02", obk_02_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_obk_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER__deili, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(obk_06_ENTRY_0)
            BindTrigger(Ref(N(EVS_ExitWalk_obk_02_2)), TRIGGER_FLOOR_TOUCH, COLLIDER__deili, 1, 0)
        CaseEq(obk_06_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOOS_MANSION)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupBombables))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Return
    End
};
