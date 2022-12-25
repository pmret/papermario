#include "obk_05.h"
#include "entity.h"

EvtScript N(EVS_OnSmashFloor) = {
    EVT_SET(GF_OBK05_BoardedFloor, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_OBK05_BoardedFloor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 0, 0, 0, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashFloor)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 200, 0, -100, 0, ITEM_APPLE, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 200, 30, -100, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 165, 0, -100, 0, ITEM_APPLE, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -105, 0, -55, 0, -1, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
