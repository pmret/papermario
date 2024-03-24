#include "jan_09.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SpinningFlower), 30, 0, -250, 0, -33, 90, -347, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_Munchlesia), 271, 0, 336, 0, MAKE_ENTITY_END)
    Return
    End
};
