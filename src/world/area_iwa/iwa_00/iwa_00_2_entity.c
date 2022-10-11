#include "iwa_00.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    EVT_SET(GF_IWA01_Hammer1Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_IWA01_Hammer1Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block_WideZ), 900, -30, 220, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock)))
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_COIN, 405, 25, 25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA00_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 465, 53, 25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA00_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, 515, 92, 25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA00_Item_CoinC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 1260, 30, 140, 0, ITEM_SLEEPY_SHEEP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_IWA00_ItemBlock_SleepySheep)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 58, -5, -73, -30, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 926, 70, -45, 22, 90, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
