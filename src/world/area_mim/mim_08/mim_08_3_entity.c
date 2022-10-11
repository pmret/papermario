#include "mim_08.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 0, 93, 0, 45, ITEM_HP_PLUS_A, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_MIM08_BadgeBlock_HPPlusA)
    EVT_RETURN
    EVT_END
};
