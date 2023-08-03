#include "kkj_16.h"

#include "../common/RestoreFromPeachState.inc.c"
#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_EndPeachChapter2) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("sbk_02"), sbk_02_ENTRY_5, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoor_kkj_11_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kkj_16_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o43)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_16_ENTRY_0)
            EVT_SET(LVar2, MODEL_o43)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
    EVT_END_SWITCH
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_EXEC(N(EVS_ManageSneakingScenes))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_OR_EQ(STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_CASE_OR_EQ(STORY_CH5_BEGAN_PEACH_MISSION)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EarlyNPCs)))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(STORY_CH6_BEGAN_PEACH_MISSION)
            EVT_CALL(N(SetAvailableDisguise), PEACH_DISGUISE_HAMMER_BROS)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(LaterNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACH_SNEAKING, 0, 8)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_11_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
