#include "mim_10.h"

EvtScript N(EVS_SetToadTownMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH3_SAW_BOO_ENTER_FOREST)
        EVT_EXEC(N(EVS_SetToadTownMusic))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(N(EVS_SetToadTownMusic))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LT(LVar1, 0)
        EVT_EXEC(N(EVS_SetToadTownMusic))
        EVT_WAIT(30)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
        EVT_WAIT(15)
        EVT_CALL(ClearAmbientSounds, 250)
        EVT_WAIT(15)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_GE(LVar1, 100)
        EVT_CALL(FadeOutMusic, 0, 1000)
        EVT_WAIT(15)
        EVT_WAIT(15)
        EVT_CALL(SetMusicTrack, 0, SONG_FOREVER_FOREST, 0, 8)
        EVT_WAIT(30)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_GOTO(10)
    EVT_LABEL(20)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LT(LVar1, 0)
        EVT_CALL(FadeOutMusic, 0, 1000)
        EVT_WAIT(30)
        EVT_EXEC(N(EVS_SetToadTownMusic))
        EVT_WAIT(30)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};
