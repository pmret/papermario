#include "sbk_25.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_25_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_25_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_25_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_25_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_25 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_24_1) = EVT_EXIT_WALK(60, sbk_25_ENTRY_0, "sbk_24", sbk_24_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_26_0) = EVT_EXIT_WALK(60, sbk_25_ENTRY_1, "sbk_26", sbk_26_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_15_3) = EVT_EXIT_WALK(60, sbk_25_ENTRY_2, "sbk_15", sbk_15_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_35_2) = EVT_EXIT_WALK(60, sbk_25_ENTRY_3, "sbk_35", sbk_35_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_24_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_26_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_15_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_35_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    ExecWait(N(EVS_MakeEntities))
    Call(N(SpawnSunEffect))
    Call(SetMusic, 0, SONG_DRY_DRY_DESERT, 0, VOL_LEVEL_FULL)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Exec(N(EVS_SetupFoliage))
    Return
    End
};
