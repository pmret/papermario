#include "arn_07.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {    0.0f, 20.0f, -147.0f, 180.0f },
    {  485.0f,  0.0f,    0.0f, 270.0f },
    { -488.0f,  0.0f,    0.0f,  90.0f },
    {  194.0f,  0.0f,    0.0f,   0.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_arn_07_tattle },
};

EvtSource N(80241F10) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
        EVT_CASE_LT(-17)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
        EVT_CASE_EQ(-14)
            EVT_CALL(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
            EVT_CALL(PlayAmbientSounds, AMBIENT_WIND)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
