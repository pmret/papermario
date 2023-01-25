#include "omo_12.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
        EVT_CALL(SetMusicTrack, 0, SONG_CREEPY_TOYBOX, 0, 8)
        EVT_THREAD
            EVT_LOOP(0)
                EVT_WAIT(1)
                EVT_IF_GE(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
        EVT_END_THREAD
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushPartnerSong) = {
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
