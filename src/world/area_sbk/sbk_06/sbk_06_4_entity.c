#include "sbk_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 135, 60, -205, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK06_MultiCoinBrick)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -20, 60, -250, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 220, 60, 65, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 90, 60, 220, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -70, 60, 100, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -370, 60, 150, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
