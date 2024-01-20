#include "jan_17.h"

EvtScript N(EVS_SetupMusic) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Call(SetMusicTrack, 0, SONG_RAPHAEL_RAVEN, 0, 8)
        Set(AF_JAN_03, FALSE)
    EndIf
    Call(ClearAmbientSounds, 250)
    Return
    End
};
