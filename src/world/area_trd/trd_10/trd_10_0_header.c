#include "trd_10.h"

extern EvtScript N(EVS_Main);

EntryList N(Entrances) = {
    [trd_10_ENTRY_0]    { -310.0,    0.0,    0.0,   90.0 },
    [trd_10_ENTRY_1]    { -225.0,    0.0,    0.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_trd_10 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_KOOPA_BROS)
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_BROS_THEME, 1, 8)
        EVT_CASE_EQ(STORY_CH1_DEFEATED_KOOPA_BROS)
            EVT_CALL(FadeOutMusic, 0, 500)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_FORTRESS, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_RETURN
    EVT_END
};
