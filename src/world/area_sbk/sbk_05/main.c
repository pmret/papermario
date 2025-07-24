#include "sbk_05.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [sbk_05_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_05_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_05_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_05_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
    [sbk_05_ENTRY_4]    {  157.0,  200.0, -338.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_05 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_sbk_04_1) = EVT_EXIT_WALK(60, sbk_05_ENTRY_0, "sbk_04", sbk_04_ENTRY_1);
EvtScript N(EVS_ExitWalk_sbk_06_0) = EVT_EXIT_WALK(60, sbk_05_ENTRY_1, "sbk_06", sbk_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_sbk_15_2) = EVT_EXIT_WALK(60, sbk_05_ENTRY_3, "sbk_15", sbk_15_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_15_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Return
    End
};

EvtScript N(D_80240268_930F58) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(sbk_05_ENTRY_4)
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
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
    Exec(N(D_80240268_930F58))
    Wait(1)
    Return
    End
};
