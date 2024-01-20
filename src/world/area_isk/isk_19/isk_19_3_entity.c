#include "isk_19.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 486, -845, 130, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, 499, -845, 42, Float(0.3), LVar0)
    Call(MakeEntity, Ref(Entity_SavePoint), 560, -850, 100, -10, MAKE_ENTITY_END)
    Return
    End
};
