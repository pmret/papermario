#include "kkj_20.h"

EvtScript N(EVS_PlayBowserSong) = {
    Call(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 1, VOL_LEVEL_8)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, VOL_LEVEL_8)
    Return
    End
};
