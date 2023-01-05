#include "dgb_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -300, 60, 75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -450, 60, 75, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
