#include "arn_07.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {    0.0f, 20.0f, -147.0f, 180.0f },
    {  485.0f,  0.0f,    0.0f, 270.0f },
    { -488.0f,  0.0f,    0.0f,  90.0f },
    {  194.0f,  0.0f,    0.0f,   0.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_arn_07_tattle },
};

Script N(80241F10) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
            PlayAmbientSounds(AMBIENT_WIND);
        }
        < STORY_CH3_HEART_ESCAPED_WINDY_MILL {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
            PlayAmbientSounds(AMBIENT_WIND);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_BLUBBA_THEME, 0, 8);
            PlayAmbientSounds(AMBIENT_WIND);
        }
        == STORY_CH3_BEGAN_PEACH_MISSION {
            SetMusicTrack(0, SONG_STAR_SPIRIT_THEME, 1, 8);
        }
        else {
            SetMusicTrack(0, SONG_GUSTY_GULCH, 0, 8);
            PlayAmbientSounds(AMBIENT_WIND);
        }
    }
});
