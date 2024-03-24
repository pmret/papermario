#include "omo_12.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
        Call(SetMusicTrack, 0, SONG_CREEPY_TOYBOX, 0, 8)
        Thread
            Loop(0)
                Wait(1)
                IfGe(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
        EndThread
    Else
        Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EndIf
    Return
    End
};

EvtScript N(EVS_PushPartnerSong) = {
    Call(PushSong, SONG_NEW_PARTNER, 0)
    Return
    End
};

EvtScript N(EVS_PopSong) = {
    Call(FadeOutMusic, 0, 500)
    Wait(15)
    Call(PopSong)
    Return
    End
};
