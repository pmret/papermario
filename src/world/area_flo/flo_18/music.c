#include "flo_18.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Call(SetMusic, 0, SONG_PUFF_PUFF_MACHINE, 0, VOL_LEVEL_FULL)
            Call(PlaySoundAtCollider, COLLIDER_o126, SOUND_LOOP_PUFF_PUFF_MACHINE, SOUND_SPACE_DEFAULT)
        CaseDefault
            Call(SetMusic, 0, SONG_FLOWER_FIELDS_SUNNY, 0, VOL_LEVEL_FULL)
    EndSwitch
    Return
    End
};
