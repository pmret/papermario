#include "nok_01.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_FULL)
    Else
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_FULL)
    EndIf
    Return
    End
};

EvtScript N(EVS_FadeOutMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_7)
        Wait(4)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_6)
        Wait(4)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_5)
        Wait(4)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_4)
        Wait(4)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_3)
    Else
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_7)
        Wait(4)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_6)
        Wait(4)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_5)
        Wait(4)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_4)
        Wait(4)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_3)
    EndIf
    Return
    End
};

EvtScript N(EVS_FadeInMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_4)
        Wait(2)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_5)
        Wait(2)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_6)
        Wait(2)
        Call(SetMusic, 0, SONG_FUZZY_ATTACK, 0, VOL_LEVEL_7)
    Else
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_4)
        Wait(2)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_5)
        Wait(2)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_6)
        Wait(2)
        Call(SetMusic, 0, SONG_KOOPA_VILLAGE, 0, VOL_LEVEL_7)
    EndIf
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
