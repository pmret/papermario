#include "omo_12.h"

EvtScript N(EVS_SetupMusic) = {
    IfLt(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
        Call(SetMusic, 0, SONG_CREEPY_TOYBOX, 0, VOL_LEVEL_FULL)
        Thread
            Loop(0)
                Wait(1)
                IfGe(GB_StoryProgress, STORY_CH4_DEFEATED_LANTERN_GHOST)
                    BreakLoop
                EndIf
            EndLoop
            Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
        EndThread
    Else
        Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
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
