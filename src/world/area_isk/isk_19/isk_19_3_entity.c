#include "isk_19.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, 486, -845, 130, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, 499, -845, 42, EVT_FLOAT(0.3), LVar0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 560, -850, 100, -10, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
