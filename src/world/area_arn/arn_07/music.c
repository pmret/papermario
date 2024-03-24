#include "arn_07.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_TUBBA_WOKE_UP)
            Call(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
            Call(PlayAmbientSounds, AMBIENT_WIND)
        CaseLt(STORY_CH3_HEART_ESCAPED_WINDY_MILL)
            Call(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
            Call(PlayAmbientSounds, AMBIENT_WIND)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
            Call(PlayAmbientSounds, AMBIENT_WIND)
        CaseEq(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(SetMusicTrack, 0, SONG_STAR_SPIRIT_THEME, 1, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_GUSTY_GULCH, 0, 8)
            Call(PlayAmbientSounds, AMBIENT_WIND)
    EndSwitch
    Return
    End
};
