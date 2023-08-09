#include "hos_05.h"

EvtScript N(EVS_PlayIntroStoryMusic) = {
    EVT_WAIT(40)
    EVT_CALL(SetMusicTrack, 0, SONG_INTRO_STORY, 0, 8)
    EVT_WAIT(2030)
    EVT_CALL(SetMusicTrack, 0, SONG_INTRO_STORY, 1, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_05_ENTRY_1)
            EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 1, 8)
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_SANCTUARY_INSIDE)
        EVT_CASE_EQ(hos_05_ENTRY_3)
            EVT_EXEC(N(EVS_PlayIntroStoryMusic))
        EVT_CASE_EQ(hos_05_ENTRY_4)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(AF_HOS_B5, FALSE)
                EVT_CALL(SetMusicTrack, 0, SONG_STAR_SANCTUARY, 0, 8)
            EVT_END_IF
            EVT_CALL(PlaySound, SOUND_LOOP_STAR_SANCTUARY_INSIDE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
