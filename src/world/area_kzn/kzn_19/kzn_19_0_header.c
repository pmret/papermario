#include "kzn_19.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [kzn_19_ENTRY_0]    { -435.0,  250.0, -350.0,   90.0 },
    [kzn_19_ENTRY_1]    { -490.0,   25.0,  -30.0,   90.0 },
    [kzn_19_ENTRY_2]    {  440.0,   25.0,  -50.0,  270.0 },
    [kzn_19_ENTRY_3]    {  440.0,   25.0,  -50.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_19 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_EQ(LVar0, kzn_19_ENTRY_1)
                EVT_CALL(FadeOutMusic, 0, 500)
                EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
                EVT_RETURN
            EVT_END_IF
            EVT_END_IF //@bug extra endif
        EVT_CASE_GE(STORY_CH5_MT_LAVA_LAVA_ERUPTING)
            EVT_CALL(PlaySound, SOUND_8000006B)
    EVT_END_SWITCH
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_RETURN
    EVT_END
};
