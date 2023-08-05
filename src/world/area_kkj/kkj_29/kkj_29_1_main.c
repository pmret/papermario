#include "kkj_29.h"

#include "../common/RestoreFromPeachState.inc.c"

EvtScript N(EVS_EndPeachChapter5) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("jan_22"), jan_22_ENTRY_3, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoor_kkj_10_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kkj_29_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o57)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_10"), kkj_10_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        EVT_EXEC(N(EVS_ManageQuizGame))
    EVT_ELSE
        EVT_SET(LVar0, kkj_29_ENTRY_0)
        EVT_SET(LVar2, MODEL_o57)
        EVT_SET(LVar3, DOOR_SWING_IN)
        EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_IF
    EVT_EXEC(N(EVS_ManageStageEffects))
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_10_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
