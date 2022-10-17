#include "arn_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 300, 237, 60, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_ARN03_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 250, 237, 125, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
