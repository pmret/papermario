#include "kmr_00.h"

EvtScript N(EVS_ExitWalk_kmr_02_1) = EVT_EXIT_WALK(60, kmr_00_ENTRY_0, "kmr_02", kmr_02_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_GoombaVillage, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_MET_INNKEEPER)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CALL(ClearDefeatedEnemies)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_Scene_MarioRevived))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(EnableModel, MODEL_ji_3, FALSE)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_GE(STORY_CH0_WAKE_UP)
            EVT_CALL(EnableModel, MODEL_ji_1, FALSE)
            EVT_CALL(EnableModel, MODEL_ji_2, FALSE)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
