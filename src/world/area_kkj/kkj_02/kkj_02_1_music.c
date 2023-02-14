#include "kkj_02.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_02_ENTRY_0)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 7)
        EVT_CASE_EQ(kkj_02_ENTRY_1)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 5)
    EVT_END_SWITCH
    EVT_WAIT(3)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 6)
    EVT_RETURN
    EVT_END
};
