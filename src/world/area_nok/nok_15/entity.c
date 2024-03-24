#include "nok_15.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HeartBlock), -50, 60, -825, 35, 6, MAKE_ENTITY_END)
    Return
    End
};
