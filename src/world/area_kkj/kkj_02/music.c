#include "kkj_02.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_02_ENTRY_0)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, VOL_LEVEL_7)
        CaseEq(kkj_02_ENTRY_1)
            Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, VOL_LEVEL_5)
    EndSwitch
    Wait(3)
    Call(SetMusicTrack, 0, SONG_PEACHS_CASTLE_PARTY, 1, VOL_LEVEL_6)
    Return
    End
};
