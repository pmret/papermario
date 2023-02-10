#include "jan_09.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SpinningFlower), 30, 0, -250, 0, -33, 90, -347, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Munchlesia), 271, 0, 336, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
