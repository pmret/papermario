#include "kkj_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_01_ENTRY_1)
        EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 7)
        EVT_WAIT(3)
    EVT_END_IF
    EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
    EVT_RETURN
    EVT_END
};
