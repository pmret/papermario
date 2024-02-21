#include "arn_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 300, 237, 60, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_ARN03_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_SavePoint), 250, 237, 125, 0, MAKE_ENTITY_END)
    Return
    End
};
