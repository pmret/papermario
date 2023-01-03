
#include "kpa_53.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -415, 60, -75, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
