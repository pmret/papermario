
#include "sbk_46.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 0, 0, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK46_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 0, 85, 0, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK46_HiddenItem_LifeShroom)
    EVT_RETURN
    EVT_END
};
