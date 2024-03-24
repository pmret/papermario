#include "sbk_24.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenRedBlock), 340, 60, -170, 0, ITEM_RUNAWAY_PAY, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK24_HiddenBadge_RunawayPay)
    Return
    End
};
