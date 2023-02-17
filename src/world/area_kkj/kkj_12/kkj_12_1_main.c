#include "kkj_12.h"

API_CALLABLE(N(DisableSpotlightSources)) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gSpriteShadingProfile->sources[i].flags = LIGHT_SOURCE_DISABLED;
    }

    return ApiStatus_DONE2;
}

#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_ExitDoors_kkj_11_1) = EVT_EXIT_DOUBLE_DOOR(kkj_12_ENTRY_0, "kkj_11", kkj_11_ENTRY_1,
    COLLIDER_deilit1, MODEL_door1, MODEL_door2);
EvtScript N(EVS_ExitDoors_kkj_13_0) = EVT_EXIT_DOUBLE_DOOR(kkj_12_ENTRY_1, "kkj_13", kkj_13_ENTRY_0,
    COLLIDER_deilit2, MODEL_door4, MODEL_door3);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_11_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit1, 1, 0)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_IF_EQ(GF_KKJ12_TrickedGuard, FALSE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_12_ENTRY_0)
            EVT_SET(LVar2, MODEL_door1)
            EVT_SET(LVar3, MODEL_door2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(kkj_12_ENTRY_1)
            EVT_SET(LVar2, MODEL_door4)
            EVT_SET(LVar3, MODEL_door3)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_12)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_CALL(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_o694, FALSE)
        EVT_CALL(EnableModel, MODEL_o695, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        EVT_CALL(N(DisableSpotlightSources))
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
