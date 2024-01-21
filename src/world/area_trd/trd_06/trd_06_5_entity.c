#include "trd_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HeartBlock), -150, 60, 100, 0, 6, MAKE_ENTITY_END)
    Return
    End
};
