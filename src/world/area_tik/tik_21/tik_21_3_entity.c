#include "tik_21.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -157, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK21_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -82, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK21_HiddenItem_CoinA)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -7, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK21_HiddenItem_CoinB)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 68, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK21_HiddenItem_CoinC)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 142, -45, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK21_HiddenItem_CoinD)
    Return
    End
};
