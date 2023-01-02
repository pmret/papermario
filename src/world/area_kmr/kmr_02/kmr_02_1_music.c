#include "kmr_02.h"

EvtScript N(EVS_FadeOutMusic) = {
    EVT_CALL(FadeInMusic, 0, SONG_GOOMBA_VILLAGE, 0, 3000, 0, 127)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_MET_INNKEEPER)
        EVT_CALL(SetMusicTrack, 0, SONG_GOOMBA_VILLAGE, 0, 8)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(kmr_02_ENTRY_1)
        EVT_CASE_OR_EQ(kmr_02_ENTRY_5)
            EVT_CALL(ClearAmbientSounds, 250)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushNewPartnerSong) = {
    EVT_CALL(PushSong, SONG_NEW_PARTNER, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PopSong) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(15)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestingSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};
