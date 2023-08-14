#include "nok_03.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SetMusicTrack, 0, SONG_FUZZY_ATTACK, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_LOOP_NOK_WATER, SOUND_SPACE_DEFAULT, 887, 0, -41)
    EVT_RETURN
    EVT_END
};
