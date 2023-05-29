#include "kmr_30.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MARIOS_HOUSE)
    EVT_CALL(SetSpriteShading, SHADING_KMR_30)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(EnableWorldStatusBar, FALSE)
    EVT_THREAD
        EVT_CALL(FadeOutMusic, 0, 0x00001388)
        EVT_WAIT(390)
        EVT_CALL(SetMusicTrack, 0, SONG_THE_END, 0, 8)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_Scene_TheEnd))
    EVT_RETURN
    EVT_END
};
