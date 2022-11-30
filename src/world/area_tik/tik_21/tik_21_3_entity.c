#include "tik_21.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -157, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK21_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -82, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK21_HiddenItem_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -7, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK21_HiddenItem_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 68, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK21_HiddenItem_CoinC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 142, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK21_HiddenItem_CoinD)
    EVT_RETURN
    EVT_END
};
