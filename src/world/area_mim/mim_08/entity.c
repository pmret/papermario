#include "mim_08.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_RedBlock), 0, 93, 0, 45, ITEM_HP_PLUS_A, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_MIM08_BadgeBlock_HPPlusA)
    Return
    End
};
