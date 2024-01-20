#include "kpa_114.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HeartBlock), -250, 60, 100, 0, MAKE_ENTITY_END)
    Return
    End
};
