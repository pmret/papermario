#include "jan_19.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_PinkFlower), -154, 0, -20, 150, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_PinkFlower), 145, 450, 50, 120, MAKE_ENTITY_END)
    Return
    End
};
