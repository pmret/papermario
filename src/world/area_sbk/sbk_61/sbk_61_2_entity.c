#include "sbk_61.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenRedBlock), 0, 90, 0, 180, ITEM_ATTACK_FX_C, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK61_HiddenBadge_AttackFXC)
    Return
    End
};
