#include "sbk_42.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [sbk_42_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_42_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_42_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_42_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_42 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_41_1) = EVT_EXIT_WALK(60, sbk_42_ENTRY_0, "sbk_41", sbk_41_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_43_0) = EVT_EXIT_WALK(60, sbk_42_ENTRY_1, "sbk_43", sbk_43_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_32_3) = EVT_EXIT_WALK(60, sbk_42_ENTRY_2, "sbk_32", sbk_32_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_52_2) = EVT_EXIT_WALK(60, sbk_42_ENTRY_3, "sbk_52", sbk_52_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_41_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_43_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_32_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_52_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    Call(SetSpriteShading, SHADING_NONE)
    IfEq(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        Call(DisablePulseStone, false)
    EndIf
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Call(N(SpawnSunEffect))
    Call(SetMusic, 0, SONG_DRY_DRY_DESERT, 0, VOL_LEVEL_FULL)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
