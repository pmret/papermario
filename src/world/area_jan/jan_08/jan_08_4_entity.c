#include "jan_08.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_JAN08_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(250, 60, 300, 0)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 75, -60, 90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN08_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 100, -60, 90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN08_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 125, -60, 90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN08_Item_CoinC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BellbellPlant), 54, 0, -380, 35, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 24, 60, -410, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_JAN08_HiddenItem_ThunderRage)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_TrumpetPlant), -450, 0, 166, 170, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
