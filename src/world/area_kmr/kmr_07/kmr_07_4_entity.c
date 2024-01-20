#include "kmr_07.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SimpleSpring), 310, 0, 45, 0, 65, MAKE_ENTITY_END)
    Set(MV_SpringEntityIndex, LVar0)
    Call(MakeEntity, Ref(Entity_SavePoint), 510, 60, 110, 0, MAKE_ENTITY_END)
    Return
    End
};
