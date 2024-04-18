#include "flo_18.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SetMusicTrack, 0, SONG_PUFF_PUFF_MACHINE, 0, 8)
            Call(PlaySoundAtCollider, COLLIDER_o126, SOUND_LOOP_PUFF_PUFF_MACHINE, SOUND_SPACE_DEFAULT)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EndSwitch
    Return
    End
};
