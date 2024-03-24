#include "omo_06.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseRange(omo_06_ENTRY_2, omo_06_ENTRY_3)
                Call(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
            CaseDefault
                Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
        EndSwitch
    EndIf
    Return
    End
};
