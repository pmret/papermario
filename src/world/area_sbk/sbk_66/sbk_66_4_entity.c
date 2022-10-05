#include "sbk_66.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -80, 60, -200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK66_MultiCoinBrickA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 80, 60, -200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK66_MultiCoinBrickB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 160, 60, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK66_MultiCoinBrickC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -160, 60, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK66_MultiCoinBrickD)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -60, 60, 200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK66_MultiCoinBrickE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 60, 60, 200, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK66_MultiCoinBrickF)
    EVT_RETURN
    EVT_END
};
