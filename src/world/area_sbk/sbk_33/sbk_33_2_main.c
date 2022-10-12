#include "sbk_33.h"

extern EvtScript N(EVS_MakeEntities);

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_32_1) = EVT_EXIT_WALK(60, sbk_33_ENTRY_0, "sbk_32", sbk_32_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_34_0) = EVT_EXIT_WALK(60, sbk_33_ENTRY_1, "sbk_34", sbk_34_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_23_3) = EVT_EXIT_WALK(60, sbk_33_ENTRY_2, "sbk_23", sbk_23_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_43_2) = EVT_EXIT_WALK(60, sbk_33_ENTRY_3, "sbk_43", sbk_43_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_32_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_34_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_23_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_43_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(N(SpawnSunEffect))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};
