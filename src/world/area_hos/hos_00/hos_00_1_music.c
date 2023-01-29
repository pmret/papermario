#include "hos_00.h"

EvtScript N(EVS_PlayToadTownSong) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 6)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 6)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayMusicByPosition) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_00_ENTRY_0)
            EVT_EXEC(N(EVS_PlayToadTownSong))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(hos_00_ENTRY_1)
        EVT_CASE_OR_EQ(hos_00_ENTRY_2)
            EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_GT(LVar1, 210)
            EVT_CALL(FadeOutMusic, 0, 833)
            EVT_WAIT(25)
            EVT_CALL(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
            EVT_WAIT(30)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_GOTO(10)
    EVT_LABEL(20)
        EVT_WAIT(1)
        EVT_IF_EQ(GB_StoryProgress, STORY_CH0_BEGAN_PEACH_MISSION)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_LT(LVar1, -55)
            EVT_CALL(FadeOutMusic, 0, 833)
            EVT_WAIT(25)
            EVT_EXEC(N(EVS_PlayToadTownSong))
            EVT_WAIT(30)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_00_ENTRY_3)
        EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
    EVT_ELSE
        EVT_EXEC(N(EVS_PlayMusicByPosition))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayKammyKoopaSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};
