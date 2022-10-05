#include "sbk_24.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenRedBlock), 340, 60, -170, 0, ITEM_RUNAWAY_PAY, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK24_HiddenBadge_RunawayPay)
    EVT_RETURN
    EVT_END
};
