#include "arn_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 17, 238, 80, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
