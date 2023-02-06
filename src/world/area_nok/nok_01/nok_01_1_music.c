#include "nok_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80242C38) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 7)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 6)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 5)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 4)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 3)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 7)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 6)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 5)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 4)
        EVT_WAIT(4)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80242DE0) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 4)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 5)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 6)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 7)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 4)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 5)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 6)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 7)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestingSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};
