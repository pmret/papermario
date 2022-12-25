#include "obk_04.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayUpgradeSong) = {
    EVT_CALL(PushSong, SONG_ITEM_UPGRADE, 1)
    EVT_WAIT(130)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};
