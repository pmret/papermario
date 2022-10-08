#include "trd_09.h"
#include "entity.h"

EvtScript N(EVS_BombRock) = {
    EVT_SET(GF_TRD09_BombedRock, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TRD09_BombedRock, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock2), -470, -75, 139, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BombRock)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 1400, -15, 135, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 1490, -15, 135, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -540, -15, 135, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TRD09_ItemBlock_MapleSyrup)
    EVT_RETURN
    EVT_END
};
