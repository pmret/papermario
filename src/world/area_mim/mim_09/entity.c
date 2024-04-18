#include "mim_09.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_RedBlock), 0, 92, 0, 45, ITEM_FP_PLUS_A, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_MIM09_BadgeBlock_FPPlusA)
    Return
    End
};
