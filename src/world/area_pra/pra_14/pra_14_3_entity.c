#include "pra_14.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 445, 60, 80, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_PRA14_MultiCoinBrickA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 445, 60, -80, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_PRA14_MultiCoinBrickB)
    EVT_RETURN
    EVT_END
};
