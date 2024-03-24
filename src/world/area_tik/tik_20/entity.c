#include "tik_20.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 475, 70, -100, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK20_ItemBlock_ShootingStar)
    Return
    End
};
