#include "hos_02.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_02_ENTRY_1)
        EVT_CALL(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 3, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
