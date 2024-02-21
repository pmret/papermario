#include "mac_04.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    IfNe(LVar0, mac_04_ENTRY_4)
        Switch(GB_StoryProgress)
            CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
                Call(SetMusicTrack, 0, SONG_SHY_GUY_INVASION, 0, 8)
            CaseDefault
                Exec(N(EVS_SetupMusicTriggers))
        EndSwitch
        Thread
            Wait(60)
            Call(StopSound, SOUND_LOOP_JAN_BEACH_WAVES)
        EndThread
    EndIf
    Return
    End
};
