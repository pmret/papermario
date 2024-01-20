#include "sbk_23.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_23_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_23_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_23_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_23_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_23 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_22_1) = EVT_EXIT_WALK(60, sbk_23_ENTRY_0, "sbk_22", sbk_22_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_24_0) = EVT_EXIT_WALK(60, sbk_23_ENTRY_1, "sbk_24", sbk_24_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_13_3) = EVT_EXIT_WALK(60, sbk_23_ENTRY_2, "sbk_13", sbk_13_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_33_2) = EVT_EXIT_WALK(60, sbk_23_ENTRY_3, "sbk_33", sbk_33_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_22_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_24_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_13_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_33_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
