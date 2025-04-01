#include "nok_01.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_8)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_8)
    EndIf
    Return
    End
};

EvtScript N(EVS_FadeOutMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_7)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_6)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_5)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_4)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_3)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_7)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_6)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_5)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_4)
        Wait(4)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_3)
    EndIf
    Return
    End
};

EvtScript N(EVS_FadeInMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_4)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_5)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_6)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, QUIET_LEVEL_7)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_4)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_5)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_6)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, QUIET_LEVEL_7)
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    Return
    End
};
