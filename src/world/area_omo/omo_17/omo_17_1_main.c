#include "omo_17.h"

EvtScript N(EVS_ExitWalk_omo_05_0) = EVT_EXIT_WALK(60, omo_17_ENTRY_0, "omo_05", omo_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_05_1) = EVT_EXIT_WALK(60, omo_17_ENTRY_1, "omo_05", omo_05_ENTRY_1);
EvtScript N(EVS_ExitWalk_omo_06_0) = EVT_EXIT_WALK(60, omo_17_ENTRY_2, "omo_06", omo_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_06_1) = EVT_EXIT_WALK(60, omo_17_ENTRY_3, "omo_06", omo_06_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_06_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili6, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(omo_17_ENTRY_4, omo_17_ENTRY_5)
            EVT_EXEC_WAIT(N(EVS_EnterTrain))
            EVT_WAIT(3)
        EVT_CASE_DEFAULT
            EVT_CALL(SetGroupVisibility, MODEL_popo, MODEL_GROUP_HIDDEN)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
