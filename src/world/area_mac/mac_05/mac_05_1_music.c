#include "mac_05.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_WHALE_MOUTH_OPEN, STORY_CH5_ENTERED_WHALE)
            EVT_CALL(SetMusicTrack, 0, SONG_WHALE_THEME, 0, 8)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_END_SWITCH
    EVT_CALL(PlaySound, SOUND_LOOP_MAC_HARBOR_WATER)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244298) = {
    EVT_CALL(SetMusicTrack, 0, SONG_JR_TROOPA_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802442C4) = {
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802442E8) = {
    EVT_CALL(SetMusicTrack, 0, SONG_CLUB64, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244314) = {
    EVT_CALL(SetMusicTrack, 0, SONG_WHALE_THEME, 0, 8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244340) = {
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_RETURN
    EVT_END
};
