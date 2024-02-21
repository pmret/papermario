#include "sbk_53.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [sbk_53_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_53_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_53_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_53_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_53 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_52_1) = EVT_EXIT_WALK(60, sbk_53_ENTRY_0, "sbk_52", sbk_52_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_54_0) = EVT_EXIT_WALK(60, sbk_53_ENTRY_1, "sbk_54", sbk_54_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_43_3) = EVT_EXIT_WALK(60, sbk_53_ENTRY_2, "sbk_43", sbk_43_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_63_2) = EVT_EXIT_WALK(60, sbk_53_ENTRY_3, "sbk_63", sbk_63_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_52_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_54_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_43_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_63_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    Return
    End
};
