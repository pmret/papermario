#include "kzn_19.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_EQ(LVar0, kzn_19_ENTRY_1)
                EVT_CALL(FadeOutMusic, 0, 500)
                EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
                EVT_RETURN
            EVT_END_IF
            EVT_END_IF //@bug extra endif
        EVT_CASE_GE(STORY_CH5_MT_LAVA_LAVA_ERUPTING)
            EVT_CALL(PlaySound, SOUND_LOOP_RUMBLE)
    EVT_END_SWITCH
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_RETURN
    EVT_END
};
