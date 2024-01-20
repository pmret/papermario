
#include "kpa_53.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_COMBINED_EPILOGUE;
    sprintf(wMapShapeName, "kpa_50_shape");
    sprintf(wMapHitName, "kpa_50_hit");
    return FALSE;
}

EvtScript N(EVS_ExitDoors_kpa_102_1) = EVT_EXIT_DOUBLE_DOOR(kpa_53_ENTRY_0, "kpa_102", kpa_102_ENTRY_1, COLLIDER_ttw, MODEL_o321, MODEL_o323);
EvtScript N(EVS_ExitDoors_kpa_83_0) = EVT_EXIT_DOUBLE_DOOR(kpa_53_ENTRY_1, "kpa_83", kpa_83_ENTRY_0, COLLIDER_tte, MODEL_o324, MODEL_o322);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_102_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    IfEq(GF_KPA53_Defeated_PeachImposter, TRUE)
        BindTrigger(Ref(N(EVS_ExitDoors_kpa_83_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_53_ENTRY_0)
            Set(LVar0, kpa_53_ENTRY_0)
            Set(LVar2, MODEL_o321)
            Set(LVar3, MODEL_o323)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_53_ENTRY_1)
            Set(LVar0, kpa_53_ENTRY_1)
            Set(LVar2, MODEL_o324)
            Set(LVar3, MODEL_o322)
            Exec(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
