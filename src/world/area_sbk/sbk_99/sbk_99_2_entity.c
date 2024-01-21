#include "sbk_99.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 145, 60, -375, 45, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), 88, 60, -324, 40, MAKE_ENTITY_END)
    Return
    End
};
