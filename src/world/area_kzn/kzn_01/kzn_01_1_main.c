#include "kzn_01.h"
#include "world/entrances.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNpcs);

EntryList N(Entrances) = {
    { -445.0,    0.0,    0.0,   90.0 },  /* kzn_01_ENTRY_0 */
    {  425.0, -255.0,    0.0,  270.0 },  /* kzn_01_ENTRY_1 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_01 },
};

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(EVS_StartTexPanner3) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(-200, 0, 600, -400)
        TEX_PAN_PARAMS_FREQ(   1, 0,   1,    1)
        TEX_PAN_PARAMS_INIT(   0, 0,   0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanner4) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_4)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(500, 0, 0, -400)
        TEX_PAN_PARAMS_FREQ(  1, 0, 0,    1)
        TEX_PAN_PARAMS_INIT(  0, 0, 0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_jan_22) = EXIT_WALK_SCRIPT(60,  kzn_01_ENTRY_0, "jan_22",  jan_22_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_02) = EXIT_WALK_SCRIPT(60,  kzn_01_ENTRY_1, "kzn_02",  kzn_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_jan_22), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_02), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_01)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_SET(GF_MAP_MtLavalava, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_ENTERED_MT_LAVA_LAVA)
        EVT_SET(GB_StoryProgress, STORY_CH5_ENTERED_MT_LAVA_LAVA)
    EVT_END_IF
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNpcs)))
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner3))
    EVT_RETURN
    EVT_END
};
