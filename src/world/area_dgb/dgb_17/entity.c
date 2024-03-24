#include "dgb_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -300, 60, 75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), -450, 60, 75, 0, MAKE_ENTITY_END)
    Return
    End
};
