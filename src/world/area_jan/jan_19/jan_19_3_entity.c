#include "jan_19.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), -154, 0, -20, 150, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), 145, 450, 50, 120, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
