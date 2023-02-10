#include "jan_16.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), -112, 0, 210, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), -453, 0, 188, 170, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
