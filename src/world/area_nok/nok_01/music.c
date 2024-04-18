#include "nok_01.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
    EndIf
    Return
    End
};

EvtScript N(EVS_80242C38) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 7)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 6)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 5)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 4)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 3)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 7)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 6)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 5)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 4)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 3)
    EndIf
    Return
    End
};

EvtScript N(EVS_80242DE0) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 4)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 5)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 6)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 7)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 4)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 5)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 6)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 7)
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    Return
    End
};
