#include "sbk_25.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK25_MultiCoinBrickA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 120, 60, 185, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK25_MultiCoinBrickB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -300, 60, -80, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -240, 60, 230, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -75, 60, 295, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -75, 60, -360, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 270, 60, -150, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
