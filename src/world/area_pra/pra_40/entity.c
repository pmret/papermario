#include "pra_40.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 165, 60, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), 85, 60, -50, 0, MAKE_ENTITY_END)
    Return
    End
};
