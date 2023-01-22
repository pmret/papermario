#include "hos_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 200, 60, 275, 0, MAKE_ENTITY_END)
    EVT_CALL(SetEntityCullMode, 3)
    EVT_RETURN
    EVT_END
};
