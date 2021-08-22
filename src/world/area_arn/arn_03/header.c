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

EvtSource N(80241780) = SCRIPT({
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
