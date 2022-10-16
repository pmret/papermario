#include "kmr_09.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 400, 60, -15, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR09_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 450, 60, -15, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 500, 60, -15, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR09_ItemBlock_CoinB)
    EVT_RETURN
    EVT_END
};
