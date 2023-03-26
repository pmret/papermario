#include "omo_06.h"

EvtScript N(EVS_ExitWalk_omo_17_2) = EVT_EXIT_WALK(60, omo_06_ENTRY_0, "omo_17", omo_17_ENTRY_2);
EvtScript N(EVS_ExitWalk_omo_17_3) = EVT_EXIT_WALK(60, omo_06_ENTRY_1, "omo_17", omo_17_ENTRY_3);
EvtScript N(EVS_ExitWalk_omo_07_0) = EVT_EXIT_WALK(60, omo_06_ENTRY_4, "omo_07", omo_07_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_17_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_17_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilit5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(omo_06_ENTRY_2, omo_06_ENTRY_3)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_WAIT(3)
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_SWITCH(LVar0)
        EVT_IF_GE(LVar0, LANGUAGE_FR) // or LANGUAGE_ES
            EVT_SUB(LVar0, 2)
        EVT_END_IF
        EVT_CALL(SetModelTexVariant, MODEL_s, LVar0)
        EVT_CALL(SetModelTexVariant, MODEL_a, LVar0)
        EVT_CALL(SetModelTexVariant, MODEL_t, LVar0)
        EVT_CALL(SetModelTexVariant, MODEL_i, LVar0)
        EVT_CALL(SetModelTexVariant, MODEL_o, LVar0)
        EVT_CALL(SetModelTexVariant, MODEL_n, LVar0)
#endif
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_80244F40))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
