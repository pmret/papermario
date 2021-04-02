#include "arn_13.h"
#include "message_ids.h"

Vec4f N(entryList)[] = {
    { -231.0f, 0.0f, 5.0f,  90.0f },
    {  231.0f, 0.0f, 5.0f, 270.0f },
};

MapConfig N(header) = {
    .main = N(script_Main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = MSG_arn_13_tattle,
};

Script N(script_80240060) = SCRIPT({
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
