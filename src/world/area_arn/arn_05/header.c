#include "arn_05.h"
#include "message_ids.h"

Vec4f N(entryList)[] = {
    { -77.0f, 135.0f, 150.0f,  90.0f },
    { 577.0f, 200.0f, 150.0f, 270.0f },
};

MapConfig N(header) = {
    .main = N(script_Main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = MSG_arn_05_tattle,
};

Script N(script_80241360) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_SAW_TUBBA_EAT_BOO {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
    }
    PlayAmbientSounds(AMBIENT_WIND);
});
