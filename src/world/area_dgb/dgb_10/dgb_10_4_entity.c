#include "dgb_10.h"
#include "entity.h"

EvtScript N(EVS_BreakFloor1) = {
    EVT_SET(GF_DGB10_BoardedFloor1, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakFloor2) = {
    EVT_SET(GF_DGB10_BoardedFloor2, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakFloor3) = {
    EVT_SET(GF_DGB10_BoardedFloor3, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_DGB10_BoardedFloor1, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 500, 0, -100, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakFloor1)))
    EVT_END_IF
    EVT_IF_EQ(GF_DGB10_BoardedFloor2, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 500, 0, -250, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakFloor2)))
    EVT_END_IF
    EVT_IF_EQ(GF_DGB10_BoardedFloor3, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 375, 0, -250, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakFloor3)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
