#include "trd_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -150, 60, 100, 0, 6, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
