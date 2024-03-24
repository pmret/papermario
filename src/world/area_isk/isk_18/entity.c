#include "isk_18.h"
#include "effects.h"

EvtScript N(EVS_SetupFlames) = {
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 305, -738, 435, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 138, -738, 514, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -46, -738, 530, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -225, -738, 482, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -376, -738, 376, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -482, -738, 225, Float(0.3), LVar0)
    Return
    End
};
