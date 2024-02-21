#include "sbk_22.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -225, 0, -225, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK22_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), -225, 0, 225, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK22_ItemBlock_CoinB)
    Call(MakeEntity, Ref(Entity_YellowBlock), 225, 0, -225, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK22_ItemBlock_CoinC)
    Call(MakeEntity, Ref(Entity_YellowBlock), 225, 0, 225, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK22_ItemBlock_CoinD)
    Call(MakeEntity, Ref(Entity_YellowBlock), 0, 0, 0, 0, ITEM_FIRE_FLOWER, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK22_ItemBlock_FireFlower)
    Return
    End
};
