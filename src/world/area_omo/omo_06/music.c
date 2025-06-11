#include "omo_06.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseRange(omo_06_ENTRY_2, omo_06_ENTRY_3)
                Call(SetMusic, 0, SONG_TOYBOX_TRAIN, 0, VOL_LEVEL_FULL)
            CaseDefault
                Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
        EndSwitch
    EndIf
    Return
    End
};
