#include "omo_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -75, 120, 135, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO17_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), -50, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO17_ItemBlock_CoinB)
    Call(MakeEntity, Ref(Entity_YellowBlock), 0, 70, -150, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO17_ItemBlock_CoinC)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), -25, 70, -150, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO17_MultiCoinBrick)
    Return
    End
};
