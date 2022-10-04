#include "tst_04.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), 0, 0, 300, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
