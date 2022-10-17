#include "kmr_07.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 310, 0, 45, 0, 65, MAKE_ENTITY_END)
    EVT_SET(MV_SpringEntityIndex, LVar0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 510, 60, 110, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
