#include "sbk_33.h"

extern EvtScript N(EVS_MakeEntities);

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_32_1) = EVT_EXIT_WALK(60, sbk_33_ENTRY_0, "sbk_32", sbk_32_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_34_0) = EVT_EXIT_WALK(60, sbk_33_ENTRY_1, "sbk_34", sbk_34_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_23_3) = EVT_EXIT_WALK(60, sbk_33_ENTRY_2, "sbk_23", sbk_23_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_43_2) = EVT_EXIT_WALK(60, sbk_33_ENTRY_3, "sbk_43", sbk_43_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_32_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_34_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_23_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_43_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    Call(SetSpriteShading, SHADING_NONE)
    IfEq(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        Call(DisablePulseStone, FALSE)
    EndIf
    SetUP_CAMERA_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Call(N(SpawnSunEffect))
    Call(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
