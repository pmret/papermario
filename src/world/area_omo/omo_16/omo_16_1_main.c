#include "omo_16.h"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
    EVT_EXEC_WAIT(N(EVS_802429C4))
    EVT_WAIT(3)
    EVT_RETURN
    EVT_END
};
