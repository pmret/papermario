#include "arn_04.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -585.0,  60.0, 150.0,  90.0 },
    {  820.0, 285.0, 150.0, 270.0 },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = MSG_arn_04_tattle,
};

Script N(802433D0) = SCRIPT({
    match STORY_PROGRESS {
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
