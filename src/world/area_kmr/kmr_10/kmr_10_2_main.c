#include "kmr_10.h"

EvtScript N(EVS_ExitWalk_kmr_11_1) = EVT_EXIT_WALK(60, kmr_10_ENTRY_0, "kmr_11", kmr_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_mac_00_0) = EVT_EXIT_WALK(60, kmr_10_ENTRY_1, "mac_00", mac_00_ENTRY_0);
EvtScript N(EVS_ExitWalk_mac_00_2) = EVT_EXIT_WALK(60, kmr_10_ENTRY_2, "mac_00", mac_00_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_mac_00_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240828_8D8CF8) = {
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_IF_EQ(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        EVT_IF_EQ(AF_KMR_0D, FALSE)
            EVT_WAIT(50)
            EVT_SET(AF_KMR_0D, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC(N(D_80240828_8D8CF8))
    EVT_WAIT(1)
    EVT_SET(GF_MAC01_RowfBadgesChosen, FALSE)
    EVT_RETURN
    EVT_END
};
