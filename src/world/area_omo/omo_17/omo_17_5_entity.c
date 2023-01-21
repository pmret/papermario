#include "omo_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -75, 120, 135, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO17_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -50, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO17_ItemBlock_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 0, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO17_ItemBlock_CoinC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -25, 70, -150, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO17_MultiCoinBrick)
    EVT_RETURN
    EVT_END
};
