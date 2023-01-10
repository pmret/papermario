#include "jan_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 0, 60, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), -61, 0, -7, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
