#include "kpa_114.h"
#include "sprite.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "kpa_112_shape");
    sprintf(wMapHitName, "kpa_112_hit");
    return FALSE;
}

EvtScript N(EVS_ExitWalk_kpa_113_2) = EVT_EXIT_WALK(60, kpa_114_ENTRY_0, "kpa_113", kpa_113_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_115_0) = EVT_EXIT_WALK(40, kpa_114_ENTRY_1, "kpa_115", kpa_115_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_113_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_115_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar0)
    IfEq(LVar0, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalkShort)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
