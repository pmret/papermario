#include "common.h"
#include "../sam.h"
#include "effects.h"

EvtScript N(EVS_ManageSnowfall) = {
    Set(AF_SAM_Snowing, TRUE)
    Set(AF_SAM_LastSnowing, FALSE)
    Label(10)
        IfNe(AF_SAM_Snowing, AF_SAM_LastSnowing)
            IfEq(AF_SAM_Snowing, FALSE)
                Call(RemoveEffect, LVarF)
            Else
                PlayEffect(EFFECT_SNOWFALL, 0, 10)
            EndIf
            Set(AF_SAM_LastSnowing, AF_SAM_Snowing)
        EndIf
        Wait(1)
        Goto(10)
    Return
    End
};
