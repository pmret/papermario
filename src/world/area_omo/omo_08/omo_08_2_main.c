#include "omo_08.h"

EvtScript N(EVS_ExitWalk_omo_09_0) = EVT_EXIT_WALK(60, omo_08_ENTRY_0, "omo_09", omo_09_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
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
    EVT_IF_EQ(LVar0, omo_08_ENTRY_0)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_ELSE
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_WAIT(3)
    EVT_END_IF
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
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupTrain))
    EVT_EXEC_WAIT(N(EVS_SetupBoxes))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
