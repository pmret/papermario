#include "jan_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 0, 60, 0, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_PinkFlower), -61, 0, -7, 0, MAKE_ENTITY_END)
    Return
    End
};
