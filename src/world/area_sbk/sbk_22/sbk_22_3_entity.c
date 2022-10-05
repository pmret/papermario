#include "sbk_22.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -225, 0, -225, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK22_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -225, 0, 225, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK22_ItemBlock_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 225, 0, -225, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK22_ItemBlock_CoinC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 225, 0, 225, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK22_ItemBlock_CoinD)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 0, 0, 0, 0, ITEM_FIRE_FLOWER, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK22_ItemBlock_FireFlower)
    EVT_RETURN
    EVT_END
};
