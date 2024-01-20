#include "common.h"
#include "effects.h"

EvtScript N(EVS_RandomFlowers_Background) = {
    Label(0)
        // posX range: 125 to 375
        Call(RandInt, 250, LVar0)
        Sub(LVar0, 125)
        // posY: 0
        Set(LVar1, 0)
        // posZ range: -100 to -60
        Call(RandInt, 40, LVar2)
        Sub(LVar2, 100)
        Call(RandInt, 30, LVar3)
        Add(LVar3, 90)
        PlayEffect(EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0)
        Call(RandInt, 20, LVar0)
        Add(LVar0, 20)
        Wait(LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_RandomFlowers_Foreground) = {
    Label(0)
        // posX range: 125 to 375
        Call(RandInt, 250, LVar0)
        Sub(LVar0, 125)
        // posY: 0
        Set(LVar1, 0)
        // posZ range: 71 to 121
        Call(RandInt, 50, LVar2)
        Add(LVar2, 71)
        Call(RandInt, 30, LVar3)
        Add(LVar3, 90)
        PlayEffect(EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 20)
        Wait(LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_RandomFlowers_FarBack) = {
    Label(0)
        // posX range: 125 to 375
        Call(RandInt, 250, LVar0)
        Sub(LVar0, 125)
        // posY: 50
        Set(LVar1, 50)
        // posZ range: -124 to -84
        Call(RandInt, 40, LVar2)
        Add(LVar2, -124)
        Call(RandInt, 30, LVar3)
        Add(LVar3, 90)
        PlayEffect(EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 20)
        Wait(LVar0)
        Goto(0)
    Return
    End
};
