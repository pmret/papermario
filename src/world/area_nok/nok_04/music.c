#include "nok_04.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
    EndIf
    Return
    End
};

EvtScript N(EVS_PushPartnerSong) = {
    Call(PushSong, SONG_NEW_PARTNER, 0)
    Return
    End
};

EvtScript N(EVS_PopSong) = {
    Call(FadeOutMusic, 0, 500)
    Wait(15)
    Call(PopSong)
    Return
    End
};
