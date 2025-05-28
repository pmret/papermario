#include "sam_06.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_STARBORN_VALLEY, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
