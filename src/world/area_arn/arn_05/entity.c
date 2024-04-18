#include "arn_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HeartBlock), 17, 238, 80, 0, MAKE_ENTITY_END)
    Return
    End
};
