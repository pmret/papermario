#include "kpa_33.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 0, 10, 0, 0, MAKE_ENTITY_END)
    Return
    End
};
