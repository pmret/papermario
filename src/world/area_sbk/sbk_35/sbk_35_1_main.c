#include "sbk_35.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [sbk_35_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_35_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_35_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_35_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_35 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_34_1) = EVT_EXIT_WALK(60, sbk_35_ENTRY_0, "sbk_34", sbk_34_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_36_0) = EVT_EXIT_WALK(60, sbk_35_ENTRY_1, "sbk_36", sbk_36_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_25_3) = EVT_EXIT_WALK(60, sbk_35_ENTRY_2, "sbk_25", sbk_25_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_45_2) = EVT_EXIT_WALK(60, sbk_35_ENTRY_3, "sbk_45", sbk_45_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_34_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_36_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_25_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_45_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(N(SpawnSunEffect))
    Call(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Exec(N(EVS_SetupFoliage))
    Return
    End
};
