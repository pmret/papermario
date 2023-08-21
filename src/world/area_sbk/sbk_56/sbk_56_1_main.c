
#include "sbk_56.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);

EntryList N(Entrances) = {
    [sbk_56_ENTRY_0]    { -475.0,    0.0,    0.0,   90.0 },
    [sbk_56_ENTRY_1]    {  475.0,    0.0,    0.0,  270.0 },
    [sbk_56_ENTRY_2]    {    0.0,    0.0, -475.0,  180.0 },
    [sbk_56_ENTRY_3]    {    0.0,    0.0,  475.0,    0.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_sbk_56 },
};

#include "world/common/todo/SpawnSunEffect.inc.c"

ApiStatus N(StartOasisSongVariation)(void) {
    bgm_set_variation(0, 1);
    return ApiStatus_DONE2;
}

ApiStatus N(StopOasisSongVariation)(void) {
    bgm_set_variation(0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_sbk_55_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, sbk_56_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(N(StopOasisSongVariation))
    EVT_CALL(GotoMap, EVT_PTR("sbk_55"), sbk_55_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_sbk_46_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, sbk_56_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_CALL(N(StopOasisSongVariation))
    EVT_CALL(GotoMap, EVT_PTR("sbk_46"), sbk_46_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_sbk_66_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, sbk_56_ENTRY_3)
    EVT_EXEC(ExitWalk)
    EVT_CALL(N(StopOasisSongVariation))
    EVT_CALL(GotoMap, EVT_PTR("sbk_66"), sbk_66_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_55_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_46_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_66_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_CALL(EnableTexPanning, MODEL_o49, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_SET(LVar1, 0)
        EVT_SUB(LVar1, LVar0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, LVar0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, LVar1)
        EVT_ADD(LVar0, 80)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_DESERT)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_GOT_PULSE_STONE)
        EVT_CALL(DisablePulseStone, FALSE)
    EVT_END_IF
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(N(SpawnSunEffect))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_CALL(MakeTransformGroup, MODEL_sui)
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_DESERT, 0, 8)
    EVT_CALL(N(StartOasisSongVariation))
    EVT_CALL(PlaySound, SOUND_LOOP_SBK_OASIS_WATER)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_RETURN
    EVT_END
};
