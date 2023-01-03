
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
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_102_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_IF_EQ(GF_KPA53_Defeated_PeachImposter, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_83_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_53_ENTRY_0)
            EVT_SET(LVar0, kpa_53_ENTRY_0)
            EVT_SET(LVar2, MODEL_o321)
            EVT_SET(LVar3, MODEL_o323)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_53_ENTRY_1)
            EVT_SET(LVar0, kpa_53_ENTRY_1)
            EVT_SET(LVar2, MODEL_o324)
            EVT_SET(LVar3, MODEL_o322)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
