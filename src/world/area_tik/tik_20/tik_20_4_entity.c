#include "tik_20.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 475, 70, -100, 0, ITEM_SHOOTING_STAR, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK20_ItemBlock_ShootingStar)
    EVT_RETURN
    EVT_END
};
