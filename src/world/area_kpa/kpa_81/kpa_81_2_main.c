#include "kpa_81.h"

s32 N(map_init)(void) {
    sprintf(wMapShapeName, "kpa_80_shape");
    sprintf(wMapHitName, "kpa_80_hit");
    return FALSE;
}

s32 N(RightDoorModels)[] = {
    MODEL_o140,
    MODEL_o142,
    MODEL_o121,
    MODEL_g35,
    MODEL_o116,
    MODEL_o170,
    -1
};

s32 N(LeftDoorModels)[] = {
    MODEL_o161,
    MODEL_o162,
    MODEL_o119,
    MODEL_g33,
    MODEL_o126,
    MODEL_o171,
    -1
};

EvtScript N(EVS_ExitDoors_kpa_50_1) = EVT_EXIT_DOUBLE_DOOR(kpa_81_ENTRY_0, "kpa_50", kpa_50_ENTRY_1, COLLIDER_deilittw, MODEL_o174, MODEL_o173);

EvtScript N(EVS_ExitDoors_kpa_32_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kpa_81_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_o166)
    EVT_SET(LVar2, EVT_PTR(N(RightDoorModels)))
    EVT_SET(LVar3, EVT_PTR(N(LeftDoorModels)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kpa_32"), kpa_32_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_04_1) = EVT_EXIT_WALK(60, kpa_81_ENTRY_3, "kpa_04", kpa_04_ENTRY_1);

// required to match -- needs to be forward-declared here
const char N(KPA_17)[] = "kpa_17";

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_50_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_IF_NE(GB_KPA81_BowserDoorState, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_32_0)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_81_ENTRY_0)
            EVT_SET(LVar0, kpa_81_ENTRY_0)
            EVT_SET(LVar2, MODEL_o174)
            EVT_SET(LVar3, MODEL_o173)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_81_ENTRY_2)
            EVT_SET(LVar0, kpa_81_ENTRY_2)
            EVT_SET(LVar2, EVT_PTR(N(LeftDoorModels)))
            EVT_SET(LVar3, EVT_PTR(N(RightDoorModels)))
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_81_ENTRY_3)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnusedMoveStatue) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ParentColliderToModel, COLLIDER_o146, MODEL_o145)
    EVT_CALL(MakeLerp, 0, -40, 40, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o145, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o146, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o146)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_IF_NE(GB_KPA81_BowserDoorState, 0)
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(kpa_81_ENTRY_0)
                EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UnusedMoveStatue)), TRIGGER_WALL_PRESS_A, COLLIDER_o146, 1, 0)
            EVT_CASE_EQ(kpa_81_ENTRY_2)
                EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UnusedMoveStatue)), TRIGGER_WALL_PRESS_A, COLLIDER_o146, 1, 0)
            EVT_CASE_EQ(kpa_81_ENTRY_3)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ParentColliderToModel, COLLIDER_o146, MODEL_o145)
    EVT_SWITCH(GB_KPA04_StatuePosition)
        EVT_CASE_EQ(1)
            EVT_CALL(TranslateModel, MODEL_o145, -50, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o146, -50, 0, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(TranslateModel, MODEL_o145, 50, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o146, 50, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(UpdateColliderTransform, COLLIDER_o146)
    EVT_CALL(EnableModel, MODEL_o166, FALSE)
    EVT_CALL(EnableModel, MODEL_m_, FALSE)
    EVT_CALL(EnableModel, MODEL_m_kai, FALSE)
    EVT_CALL(EnableModel, MODEL_m1, FALSE)
    EVT_CALL(EnableModel, MODEL_m2, FALSE)
    EVT_CALL(EnableModel, MODEL_m3, FALSE)
    EVT_CALL(EnableModel, MODEL_m4, FALSE)
    EVT_CALL(EnableModel, MODEL_m5, FALSE)
    EVT_CALL(EnableModel, MODEL_m6, FALSE)
    EVT_CALL(EnableModel, MODEL_m7, FALSE)
    EVT_CALL(EnableModel, MODEL_b_, FALSE)
    EVT_CALL(EnableModel, MODEL_b_kai, FALSE)
    EVT_CALL(EnableModel, MODEL_b1, FALSE)
    EVT_CALL(EnableModel, MODEL_b2, FALSE)
    EVT_CALL(EnableModel, MODEL_b3, FALSE)
    EVT_CALL(EnableModel, MODEL_b4, FALSE)
    EVT_CALL(EnableModel, MODEL_b5, FALSE)
    EVT_CALL(EnableModel, MODEL_b6, FALSE)
    EVT_CALL(EnableModel, MODEL_b7, FALSE)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
