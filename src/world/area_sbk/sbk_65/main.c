#include "sbk_65.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [sbk_65_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_65_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_65_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_65_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_65 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_64_1) = EVT_EXIT_WALK(60, sbk_65_ENTRY_0, "sbk_64", sbk_64_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_66_0) = EVT_EXIT_WALK(60, sbk_65_ENTRY_1, "sbk_66", sbk_66_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_55_3) = EVT_EXIT_WALK(60, sbk_65_ENTRY_2, "sbk_55", sbk_55_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_64_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_66_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_55_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
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
    Call(N(SpawnSunEffect))
    Call(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
