#include "omo_08.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Else
        Call(GetEntryID, LVar0)
        IfEq(LVar0, omo_08_ENTRY_0)
            Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
        Else
            Call(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
        EndIf
    EndIf
    Return
    End
};
