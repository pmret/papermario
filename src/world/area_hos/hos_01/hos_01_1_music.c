#include "hos_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_01_ENTRY_0)
        EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
