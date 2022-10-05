#include "sbk_99.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 145, 60, -375, 45, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 88, 60, -324, 40, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
