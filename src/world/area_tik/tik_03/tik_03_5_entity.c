#include "tik_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 200, 50, -75, 0, ITEM_SNOWMAN_DOLL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK03_ItemBlock_SnowmanDoll)
    Call(MakeEntity, Ref(Entity_YellowBlock), 140, 50, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK03_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), 260, 50, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK03_ItemBlock_CoinB)
    Return
    End
};
