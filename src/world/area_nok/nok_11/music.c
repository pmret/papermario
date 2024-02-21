#include "nok_11.h"

EvtScript N(EVS_SetupMusic) = {
    Call(SetMusicTrack, 0, SONG_PLEASANT_PATH, 0, 8)
    Return
    End
};

EvtScript N(EVS_PlayJrTroopaSong) = {
    Call(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    Return
    End
};
