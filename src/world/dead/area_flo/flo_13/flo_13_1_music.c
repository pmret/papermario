#include "flo_13.h"

EvtScript N(EVS_PlaySongForPlayerPos) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -500)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LABEL(0)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, -500)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LABEL(10)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
                EVT_CALL(SetMusicTrack, 0, SONG_SUN_TOWER_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_SUN_TOWER_SUNNY, 0, 8)
        EVT_END_SWITCH
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, -500)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_EXEC(N(EVS_PlaySongForPlayerPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushPartnerSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_NEW_PARTNER, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PopSong) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(15)
    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
    EVT_RETURN
    EVT_END
};
