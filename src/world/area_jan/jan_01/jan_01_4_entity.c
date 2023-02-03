#include "jan_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_LETTER_TO_IGOR, -110, 90, -230, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN01_Item_Letter11)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BellbellPlant), -375, -3, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -335, 57, -55, 0, ITEM_REPEL_GEL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_JAN01_HiddenItem_RepelGel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BellbellPlant), 180, -3, -115, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 140, 57, -85, 0, ITEM_MYSTERY, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_JAN01_HiddenItem_Mystery)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 340, 100, -90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN01_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 340, 125, -90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN01_Item_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SpinningFlower), 340, 0, -90, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
