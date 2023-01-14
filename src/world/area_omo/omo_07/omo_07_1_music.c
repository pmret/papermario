#include "omo_07.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GF_OMO07_SpawnedPeachChoice2, FALSE)
        EVT_CALL(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
