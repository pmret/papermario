#include "arn_03.h"

EntryList N(entryList) = {
    { -76.0, 165.0, 150.0,  90.0 },
    { 576.0, 225.0, 150.0, 270.0 },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_arn_03_tattle },
};

EvtSource N(80241780) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
    EVT_RETURN
    EVT_END
};
