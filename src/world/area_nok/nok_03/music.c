#include "nok_03.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Call(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 8)
    Else
        Call(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
    EndIf
    Call(PlaySoundAt, SOUND_LOOP_NOK_WATER, SOUND_SPACE_DEFAULT, 887, 0, -41)
    Return
    End
};
