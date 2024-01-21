#include "jan_16.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_PinkFlower), -112, 0, 210, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_PinkFlower), -453, 0, 188, 170, MAKE_ENTITY_END)
    Return
    End
};
