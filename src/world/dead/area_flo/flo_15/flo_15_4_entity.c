#include "flo_15.h"
#include "entity.h"

EvtScript N(EVS_OnBlast_Rock) = {
    EVT_SET(GF_FLO15_BombedRock, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_FLO15_BombedRock, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock), -180, 0, -18, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBlast_Rock)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
