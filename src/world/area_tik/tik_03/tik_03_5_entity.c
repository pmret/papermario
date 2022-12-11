#include "tik_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 200, 50, -75, 0, ITEM_SNOWMAN_DOLL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK03_ItemBlock_SnowmanDoll)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 140, 50, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK03_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 260, 50, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK03_ItemBlock_CoinB)
    EVT_RETURN
    EVT_END
};
