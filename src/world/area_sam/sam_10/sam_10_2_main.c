#include "sam_10.h"

EvtScript N(EVS_ExitWalk_sam_09_1) = EVT_EXIT_WALK(60, sam_10_ENTRY_0, "sam_09", sam_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_pra_01_0) = EVT_EXIT_WALK(60, sam_10_ENTRY_1, "pra_01", pra_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_sam_12_0) = EVT_EXIT_WALK(60, sam_10_ENTRY_2, "sam_12", sam_12_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_09_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sam_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilia, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfLt(LVar0, sam_10_ENTRY_3)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_MOUNTAIN)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupStairs))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
