#include "sbk_52.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK52_MultiCoinBrick)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 80, 60, 270, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -210, 60, 165, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
