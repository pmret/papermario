#include "mim_09.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 0, 92, 0, 45, ITEM_FP_PLUS_A, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_MIM09_BadgeBlock_FPPlusA)
    EVT_RETURN
    EVT_END
};
