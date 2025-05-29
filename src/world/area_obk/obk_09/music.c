#include "obk_09.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        Call(SetMusic, 0, SONG_BOOS_MANSION, 0, VOL_LEVEL_FULL)
    Else
        Call(SetMusic, 0, SONG_CHEERFUL_BOOS_MANSION, 0, VOL_LEVEL_FULL)
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayNewPartnerSong) = {
    Call(SetMusic, 0, SONG_NEW_PARTNER, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_ResetMusic) = {
    Call(FadeOutMusic, 0, 500)
    Wait(15)
    Call(SetMusic, 0, SONG_BOOS_MANSION, 0, VOL_LEVEL_FULL)
    Return
    End
};
