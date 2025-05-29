#include "omo_10.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseRange(omo_10_ENTRY_0, omo_10_ENTRY_1)
                Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
            CaseDefault
                Call(SetMusic, 0, SONG_TOYBOX_TRAIN, 0, VOL_LEVEL_FULL)
        EndSwitch
    EndIf
    Return
    End
};
