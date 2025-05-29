#include "omo_03.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseRange(omo_03_ENTRY_2, omo_03_ENTRY_3)
                Call(SetMusic, 0, SONG_TOYBOX_TRAIN, 0, VOL_LEVEL_FULL)
            CaseEq(omo_03_ENTRY_5)
                Call(FadeInMusic, 0, SONG_SHY_GUY_TOYBOX, 0, 3000, 0, 127)
            CaseDefault
                Call(SetMusic, 0, SONG_SHY_GUY_TOYBOX, 0, VOL_LEVEL_FULL)
        EndSwitch
    EndIf
    Return
    End
};
