#include "kkj_20.h"

EvtScript N(EVS_PlayBowserSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 1, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestingSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};
