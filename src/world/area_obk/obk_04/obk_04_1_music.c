#include "obk_04.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        Call(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayUpgradeSong) = {
    Call(PushSong, SONG_ITEM_UPGRADE, 1)
    Wait(130)
    Call(PopSong)
    Return
    End
};
