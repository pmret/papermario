#include "sbk_22.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [sbk_22_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_22_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_22_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_22_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_22 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_21_1) = EVT_EXIT_WALK(60, sbk_22_ENTRY_0, "sbk_21", sbk_21_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_23_0) = EVT_EXIT_WALK(60, sbk_22_ENTRY_1, "sbk_23", sbk_23_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_12_3) = EVT_EXIT_WALK(60, sbk_22_ENTRY_2, "sbk_12", sbk_12_ENTRY_3);
EvtScript N(EVS_ExitWalk_sbk_32_2) = EVT_EXIT_WALK(60, sbk_22_ENTRY_3, "sbk_32", sbk_32_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_21_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_23_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_12_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_32_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
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
    ExecWait(N(EVS_MakeEntities))
    Call(N(SpawnSunEffect))
    Call(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
