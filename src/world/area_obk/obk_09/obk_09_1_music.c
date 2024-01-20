#include "obk_09.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        Call(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayNewPartnerSong) = {
    Call(SetMusicTrack, 0, SONG_NEW_PARTNER, 0, 8)
    Return
    End
};

EvtScript N(EVS_ResetMusic) = {
    Call(FadeOutMusic, 0, 500)
    Wait(15)
    Call(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    Return
    End
};
