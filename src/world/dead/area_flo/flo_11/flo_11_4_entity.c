#include "flo_11.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -220, 60, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO11_MultiCoinBrick)
    EVT_RETURN
    EVT_END
};
