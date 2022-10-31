#include "flo_23.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 100, 60, 5, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 100, 145, 0, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO23_HiddenItem_ShootingStar)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 25, 60, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO23_HiddenItem_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), -50, 0, 0, 90, 60, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
