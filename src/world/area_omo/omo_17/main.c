#include "omo_17.h"

EvtScript N(EVS_ExitWalk_omo_05_0) = EVT_EXIT_WALK(60, omo_17_ENTRY_0, "omo_05", omo_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_05_1) = EVT_EXIT_WALK(60, omo_17_ENTRY_1, "omo_05", omo_05_ENTRY_1);
EvtScript N(EVS_ExitWalk_omo_06_0) = EVT_EXIT_WALK(60, omo_17_ENTRY_2, "omo_06", omo_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_06_1) = EVT_EXIT_WALK(60, omo_17_ENTRY_3, "omo_06", omo_06_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili5, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_06_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili6, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(omo_17_ENTRY_4, omo_17_ENTRY_5)
            ExecWait(N(EVS_EnterTrain))
            Wait(3)
        CaseDefault
            Call(SetGroupVisibility, MODEL_popo, MODEL_GROUP_HIDDEN)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};
