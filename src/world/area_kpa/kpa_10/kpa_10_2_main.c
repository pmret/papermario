#include "kpa_10.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_62_1) = EVT_EXIT_WALK(60, kpa_10_ENTRY_0, "kpa_62", kpa_62_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_12_0) = EVT_EXIT_WALK(60, kpa_10_ENTRY_1, "kpa_12", kpa_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_17_1) = EVT_EXIT_WALK(60, kpa_10_ENTRY_2, "kpa_17", kpa_17_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_62_2) = EVT_EXIT_WALK(60, kpa_10_ENTRY_3, "kpa_62", kpa_62_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_12_2) = EVT_EXIT_WALK(60, kpa_10_ENTRY_4, "kpa_12", kpa_12_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_62_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_62_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_12_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
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
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
