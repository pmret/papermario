#include "kpa_63.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 120, 60, 90, 0, MAKE_ENTITY_END)
    Return
    End
};
