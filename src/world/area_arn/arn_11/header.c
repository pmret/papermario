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

EvtSource N(80240050) = SCRIPT({
    match EVT_STORY_PROGRESS {
        < STORY_CH3_WENT_DOWN_THE_WELL {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
        } else {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
    }
});
