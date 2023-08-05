#include "kkj_26.h"

#include "../common/RestoreFromPeachState.inc.c"

EvtScript N(EVS_GotoMap_hos_00_1) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("hos_00"), hos_00_ENTRY_1, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
};

EvtScript N(EVS_ExitDoors_kkj_14_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kkj_26_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_ttw)
    EVT_SET(LVar2, MODEL_o85)
    EVT_SET(LVar3, MODEL_o83)
    EVT_SET(LVar4, MODEL_o86)
    EVT_SET(LVar5, MODEL_o84)
    EVT_EXEC(ExitSplitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_14"), kkj_14_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_14_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_26_ENTRY_0)
            EVT_SET(LVar2, MODEL_o85)
            EVT_SET(LVar3, MODEL_o83)
            EVT_SET(LVar4, MODEL_o86)
            EVT_SET(LVar5, MODEL_o84)
            EVT_EXEC_WAIT(EnterSplitDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kkj_26_ENTRY_1)
            EVT_EXEC(N(EVS_Scene_AfterAllSpiritsRescued))
        EVT_CASE_EQ(kkj_26_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_WhereIsMario))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_26)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_26_ENTRY_1)
        EVT_SET(GB_StoryProgress, STORY_CH7_BEGAN_PEACH_MISSION)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_DOOR)
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_PlayDemoScene))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
