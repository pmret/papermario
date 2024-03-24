#include "isk_16.h"
#include "effects.h"

EvtScript N(EVS_SetupFlames) = {
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -713, 291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 291, -713, 415, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 415, -843, 291, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 291, -843, 415, Float(0.3), LVar0)
    Return
    End
};
