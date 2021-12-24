#include "arn_02.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -585.0f,  60.0f, 150.0f,  90.0f },
    {  880.0f, 320.0f, 150.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_arn_02_tattle },
};

EvtSource N(80241040) = {
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
