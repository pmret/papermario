#include "kkj_23.h"

#include "../common/RestoreFromPeachState.inc.c"
#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_EndPeachChapter6) = {
    EVT_SET(LVar0, GB_KKJ_LastPartner)
    EVT_CALL(N(RestoreFromPeachState))
    EVT_CALL(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    EVT_CALL(GotoMapSpecial, EVT_PTR("flo_00"), flo_00_ENTRY_A, TRANSITION_END_PEACH_INTERLUDE)
    EVT_WAIT(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoors_kkj_22_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kkj_23_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o5)
    EVT_SET(LVar3, MODEL_o4)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kkj_22"), kkj_22_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kkj_24_0) = EVT_EXIT_DOUBLE_DOOR(kkj_23_ENTRY_1, "kkj_24", kkj_24_ENTRY_0, COLLIDER_ttw, MODEL_o9, MODEL_o10);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_23_ENTRY_0)
            EVT_SET(LVar2, MODEL_o5)
            EVT_SET(LVar3, MODEL_o4)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
                EVT_EXEC(N(EVS_Scene_KammyUnmasksPeach))
            EVT_ELSE
                EVT_EXEC(N(EVS_BowserTauntMario))
            EVT_END_IF
        EVT_CASE_EQ(kkj_23_ENTRY_1)
            EVT_SET(LVar2, MODEL_o9)
            EVT_SET(LVar3, MODEL_o10)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_23)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_CALL(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(PeachNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(FinaleNPCs)))
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_24_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_22_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
