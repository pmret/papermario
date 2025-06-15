#include "mac_01.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, BGM_VARIATION_1, VOL_LEVEL_FULL)
        CaseEq(STORY_EPILOGUE)
            Call(SetMusic, 0, SONG_PEACHS_CASTLE_PARTY, 0, VOL_LEVEL_FULL)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusic, 0, SONG_SHY_GUY_INVASION, 0, VOL_LEVEL_FULL)
        CaseDefault
            Exec(N(EVS_SetupMusicMix))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlaySpellcastSong) = {
    Call(SetMusic, 0, SONG_MERLEE_SPELL, BGM_VARIATION_1, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_ResetMusicAfterFortune) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusic, 0, SONG_SHY_GUY_INVASION, 0, VOL_LEVEL_FULL)
        CaseDefault
            Call(SetMusic, 0, SONG_TOAD_TOWN, 0, VOL_LEVEL_FULL)
            Wait(20)
            Call(EnableMusicProximityMix, 0)
            Call(AdjustMusicProximityMix, 0, 2, MUSIC_PROXIMITY_FULL)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlayFlowerGateSong) = {
    Call(SetMusic, 0, SONG_FLOWER_GATE_APPEARS, 0, VOL_LEVEL_FULL)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Return
    End
};
