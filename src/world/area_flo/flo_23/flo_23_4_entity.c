#include "flo_23.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_BrickBlock), 100, 60, 5, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 100, 145, 0, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_FLO23_HiddenItem_ShootingStar)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 25, 60, 0, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_FLO23_HiddenItem_Coin)
    Call(MakeEntity, Ref(Entity_SimpleSpring), -50, 0, 0, 90, 60, MAKE_ENTITY_END)
    Return
    End
};
