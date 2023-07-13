#include "mim_10.h"

EvtScript N(EVS_ExitWalk_mac_02_1) = EVT_EXIT_WALK(60, mim_10_ENTRY_0, "mac_02", mac_02_ENTRY_1);

EvtScript N(EVS_ExitWalk_mim_01_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, mim_10_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
        EVT_IF_EQ(GF_StartedChapter3, FALSE)
            EVT_SET(GF_StartedChapter3, TRUE)
            EVT_CALL(FadeOutMusic, 0, 1500)
            EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_3, TRANSITION_BEGIN_OR_END_CHAPTER)
            EVT_WAIT(100)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("mim_01"), mim_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mim_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
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
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupBootlerTrigger))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_RETURN
    EVT_END
};
