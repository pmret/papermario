#include "jan_04.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_RANGE(jan_04_ENTRY_1, jan_04_ENTRY_2)
            EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
        EVT_CASE_EQ(jan_04_ENTRY_3)
            EVT_CALL(FadeInMusic, 0, SONG_JADE_JUNGLE, 0, 3000, 0, 127)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_JADE_JUNGLE, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushNewPartnerSong) = {
    EVT_CALL(PushSong, SONG_NEW_PARTNER, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PopSong) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(15)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
