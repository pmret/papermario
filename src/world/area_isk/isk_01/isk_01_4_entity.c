#include "isk_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -530, 60, 43, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
