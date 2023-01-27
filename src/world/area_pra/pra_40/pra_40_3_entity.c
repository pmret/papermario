#include "pra_40.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 165, 60, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 85, 60, -50, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
