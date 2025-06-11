#include "kkj_20.h"

EvtScript N(EVS_PlayBowserSong) = {
    Call(SetMusic, 0, SONG_BOWSER_ATTACKS, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
