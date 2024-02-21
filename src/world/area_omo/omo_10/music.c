#include "omo_10.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseRange(omo_10_ENTRY_0, omo_10_ENTRY_1)
                Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
        EndSwitch
    EndIf
    Return
    End
};
