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

Script N(80241040) = SCRIPT({
    match SI_STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        } else {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
        }
    }
    PlayAmbientSounds(AMBIENT_WIND);
});
