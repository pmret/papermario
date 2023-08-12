#include "hos_04.h"

EvtScript N(EVS_PlayIntroSong) = {
    EVT_WAIT(80)
    EVT_CALL(SetMusicTrack, 0, SONG_INTRO_STORY, 2, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_04_ENTRY_2)
            EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
        EVT_CASE_EQ(hos_04_ENTRY_3)
        EVT_CASE_EQ(hos_04_ENTRY_4)
            EVT_EXEC(N(EVS_PlayIntroSong))
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_HOS04_Visited, FALSE)
                EVT_CALL(SetMusicTrack, 0, SONG_STAR_SANCTUARY, 1, 8)
            EVT_ELSE
                EVT_CALL(SetMusicTrack, 0, SONG_STAR_HAVEN, 0, 8)
            EVT_END_IF
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_SANCTUARY_NEAR)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
