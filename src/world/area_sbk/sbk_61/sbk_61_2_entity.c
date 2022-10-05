#include "sbk_61.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenRedBlock), 0, 90, 0, 180, ITEM_ATTACK_FX_C, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK61_HiddenBadge_AttackFXC)
    EVT_RETURN
    EVT_END
};
