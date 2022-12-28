#include "mac_01.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
        EVT_CASE_EQ(STORY_EPILOGUE)
            EVT_CALL(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        EVT_CASE_DEFAULT
            EVT_EXEC(N(EVS_SetupMusicMix))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlaySpellcastSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_MERLEE_SPELL, 1, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ResetMusicAfterFortune) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
            EVT_WAIT(20)
            EVT_CALL(EnableMusicProximityMix, 0)
            EVT_CALL(AdjustMusicProximityMix, 0, 2, 2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayFlowerGateSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_GATE_APPEARS, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestingSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};
