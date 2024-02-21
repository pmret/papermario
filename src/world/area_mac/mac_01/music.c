#include "mac_01.h"

EvtScript N(EVS_SetupMusic) = {
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, 8)
        CaseEq(STORY_EPILOGUE)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 0, 8)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        CaseDefault
            Exec(N(EVS_SetupMusicMix))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlaySpellcastSong) = {
    Call(SetMusicTrack, 0, SONG_MERLEE_SPELL, 1, 8)
    Return
    End
};

EvtScript N(EVS_ResetMusicAfterFortune) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_TOAD_TOWN, 0, 8)
            Wait(20)
            Call(EnableMusicProximityMix, 0)
            Call(AdjustMusicProximityMix, 0, 2, 2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PlayFlowerGateSong) = {
    Call(SetMusicTrack, 0, SONG_FLOWER_GATE_APPEARS, 0, 8)
    Return
    End
};

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    Return
    End
};
