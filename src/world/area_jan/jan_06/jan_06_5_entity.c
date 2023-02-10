#include "jan_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), 84, 0, -320, 5, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 285, -60, 220, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN06_Item_Coin)
    EVT_RETURN
    EVT_END
};
