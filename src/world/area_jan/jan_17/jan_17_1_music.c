#include "jan_17.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_CALL(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
        EVT_SET(AF_JAN_03, FALSE)
    EVT_END_IF
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};
