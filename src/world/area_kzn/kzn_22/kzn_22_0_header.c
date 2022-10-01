#include "kzn_22.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [kzn_22_ENTRY_0]    { -390.0,    0.0,  210.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_22 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        EVT_CALL(PlaySound, SOUND_8000006B)
    EVT_END_IF
    EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA4)
    EVT_RETURN
    EVT_END
};
