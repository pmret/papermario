#include "sam_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -250, 120, 140, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_SNOWMAN_SCARF, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_ScarfItemID, LVar0)
    EVT_RETURN
    EVT_END
};
