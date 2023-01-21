#include "nok_15.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -50, 60, -825, 35, 6, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
