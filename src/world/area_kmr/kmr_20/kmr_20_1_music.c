#include "kmr_20.h"

API_CALLABLE(N(func_80240000_8EBE20)){
    snd_ambient_slow_fade_out(0, 500);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_80242C40) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_INTRO)
            EVT_CALL(FadeOutMusic, 0, 500)
        EVT_END_CASE_GROUP
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_CALL(FadeOutMusic, 0, 500)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_MARIO_BROS_HOUSE, 0, 8)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(kmr_20_ENTRY_0)
                EVT_WAIT(300)
                EVT_CALL(PlayAmbientSounds, AMBIENT_BIRDS)
            EVT_CASE_DEFAULT
                EVT_CALL(PlayAmbientSounds, AMBIENT_BIRDS)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRestingSong) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80242D78) = {
    EVT_CALL(N(func_80240000_8EBE20))
    EVT_RETURN
    EVT_END
};
