#include "pra_32.h"

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_DEFEATED_CRYSTAL_KING)
        EVT_CALL(FadeOutMusic, 0, 500)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_CRYSTAL_PALACE, 0, 8)
    EVT_END_IF
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_RETURN
    EVT_END
};
