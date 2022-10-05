#include "sbk_40.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK40_MultiCoinBrick)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 165, 60, -300, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 110, 60, 130, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -110, 60, 200, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
