#include "arn_09.h"
#include "message_ids.h"

Vec4f N(entryList)[] = {
    { 125.0f,   0.0f, 0.0f, 270.0f },
    {   0.0f, 200.0f, 0.0f,  90.0f },
};

MapConfig N(header) = {
    .main = N(script_Main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = MSG_arn_09_tattle,
};

Script N(script_802400A0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_HEART_FLED_FIRST_TUNNEL {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
    }
});
