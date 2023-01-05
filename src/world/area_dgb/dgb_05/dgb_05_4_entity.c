#include "dgb_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_DGB05_BoardedFloor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 510, -210, 100, 0, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
