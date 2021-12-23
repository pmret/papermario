#include "arn_11.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -165.0f, 0.0f, 0.0f, 90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_arn_11_tattle },
};

EvtSource N(80240050) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-23)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
