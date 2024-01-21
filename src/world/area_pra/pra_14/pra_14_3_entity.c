#include "pra_14.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 445, 60, 80, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_PRA14_MultiCoinBrickA)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 445, 60, -80, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_PRA14_MultiCoinBrickB)
    Return
    End
};
