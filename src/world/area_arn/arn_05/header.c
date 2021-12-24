#include "arn_05.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -77.0f, 135.0f, 150.0f,  90.0f },
    { 577.0f, 200.0f, 150.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_arn_05_tattle },
};

EvtSource N(80241360) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-33)
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
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
