#include "sbk_02.h"
#include "effects.h"

EvtScript N(EVS_ExitWalk_sbk_01_1) = EVT_EXIT_WALK(60, sbk_02_ENTRY_0, "sbk_01", sbk_01_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_03_0) = EVT_EXIT_WALK(60, sbk_02_ENTRY_1, "sbk_03", sbk_03_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_12_2) = EVT_EXIT_WALK(60, sbk_02_ENTRY_3, "sbk_12", sbk_12_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_01_0) = EVT_EXIT_WALK(60, sbk_02_ENTRY_4, "isk_01", isk_01_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_12_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sbk_02_ENTRY_5)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_OR_EQ(sbk_02_ENTRY_6)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_7)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        EVT_CALL(DisablePulseStone, FALSE)
    EVT_END_IF
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
        EVT_PLAY_EFFECT(EFFECT_SUN, 0, 0, 0, 0, 0, 0, 0)
        EVT_SET(MV_Unk_00, LVarF)
    EVT_END_IF
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
    EVT_ELSE
        EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_6)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_7)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_SetupRuins))
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sbk_02_ENTRY_5)
            EVT_WAIT(65)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_6)
        EVT_CASE_OR_EQ(sbk_02_ENTRY_7)
            EVT_EXEC(N(EVS_Ruins_Arise_Continued))
            EVT_WAIT(3)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
