#include "kmr_02.h"

EvtScript N(EVS_FadeOutMusic) = {
    Call(FadeInMusic, 0, SONG_GOOMBA_VILLAGE, 0, 3000, 0, 127)
    Call(ClearAmbientSounds, 250)
    Return
    End
};

EvtScript N(EVS_SetupMusic) = {
    IfGe(GB_StoryProgress, STORY_CH0_MET_INNKEEPER)
        Call(SetMusicTrack, 0, SONG_GOOMBA_VILLAGE, 0, 8)
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(kmr_02_ENTRY_1)
        CaseOrEq(kmr_02_ENTRY_5)
            Call(ClearAmbientSounds, 250)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_PushNewPartnerSong) = {
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

EvtScript N(EVS_PlayRestingSong) = {
    Call(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    Return
    End
};
