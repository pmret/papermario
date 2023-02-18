#include "hos_00.h"

#include "../common/FallingStars.inc.c"

EvtScript N(EVS_ExitWalk_osr) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, hos_00_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH0_WAKE_UP, STORY_CH8_REACHED_PEACHS_CASTLE)
            EVT_CALL(GotoMap, EVT_PTR("osr_01"), osr_01_ENTRY_1)
        EVT_CASE_DEFAULT
            EVT_CALL(GotoMap, EVT_PTR("osr_00"), osr_00_ENTRY_1)
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_hos_01_0) = EVT_EXIT_WALK(60, hos_00_ENTRY_1, "hos_01", hos_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_hos_06_0) = EVT_EXIT_WALK(60, hos_00_ENTRY_2, "hos_06", hos_06_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_osr)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Unknown) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
        EVT_ADD(LVar0, 0x4000)
        EVT_WAIT(15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(N(EVS_SetupBackgroundShade))
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_00_ENTRY_3)
        EVT_CALL(SetGroupVisibility, MODEL_g107, MODEL_GROUP_HIDDEN)
        EVT_EXEC(N(EVS_Scene_Wishing))
        EVT_RETURN
    EVT_ELSE
        EVT_EXEC(N(EVS_SetupBackgroundShade))
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHOOTING_STAR_SUMMIT)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_ShootingStarSummit, TRUE)
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_00_ENTRY_3)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(WishingNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, hos_00_ENTRY_3)
        EVT_EXEC(N(EVS_Starfall_Directed))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH0_BEGAN_PEACH_MISSION)
        EVT_IF_EQ(AF_HOS_B4, FALSE)
            EVT_WAIT(50)
            EVT_SET(AF_HOS_B4, TRUE)
        EVT_END_IF
        EVT_EXEC(N(EVS_Scene_MeetingTwink))
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_TexPan_Unknown))
    EVT_RETURN
    EVT_END
};
