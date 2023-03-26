#include "omo_03.h"

EvtScript N(EVS_ExitWalk_omo_13_1) = EVT_EXIT_WALK(60, omo_03_ENTRY_0, "omo_13", omo_13_ENTRY_1);
EvtScript N(EVS_ExitWalk_omo_04_0) = EVT_EXIT_WALK(60, omo_03_ENTRY_1, "omo_04", omo_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(AF_OMO_04, FALSE)
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(omo_03_ENTRY_0, omo_03_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(omo_03_ENTRY_4)
            EVT_SET(AF_OMO_04, TRUE)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_EXEC(N(EVS_Scene_EnterSpring))
        EVT_CASE_EQ(omo_03_ENTRY_5)
            EVT_EXEC(N(EVS_Scene_Epilogue))
        EVT_CASE_EQ(omo_03_ENTRY_6)
            EVT_EXEC(N(EVS_Scene_TrainDropped))
        EVT_CASE_DEFAULT
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_WAIT(3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_ENTERED_THE_TOY_BOX)
        EVT_SET(GB_StoryProgress, STORY_CH4_ENTERED_THE_TOY_BOX)
    EVT_END_IF
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
    EVT_SET(AF_OMO_05, FALSE)
    EVT_SET(GF_MAP_ShyGuysToybox, TRUE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, omo_03_ENTRY_5)
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(EpilogueNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_8024746C))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
