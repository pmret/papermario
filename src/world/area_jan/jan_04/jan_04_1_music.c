#include "jan_04.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseRange(jan_04_ENTRY_1, jan_04_ENTRY_2)
            Call(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
        CaseEq(jan_04_ENTRY_3)
            Call(FadeInMusic, 0, SONG_JADE_JUNGLE, 0, 3000, 0, 127)
        CaseDefault
            Call(SetMusicTrack, 0, SONG_JADE_JUNGLE, 0, 8)
    EndSwitch
    Call(ClearAmbientSounds, 250)
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
