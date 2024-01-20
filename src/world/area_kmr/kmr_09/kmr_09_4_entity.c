#include "kmr_09.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 400, 60, -15, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR09_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_BrickBlock), 450, 60, -15, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_YellowBlock), 500, 60, -15, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR09_ItemBlock_CoinB)
    Return
    End
};
