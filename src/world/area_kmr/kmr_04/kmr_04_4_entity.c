#include "kmr_04.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    EVT_SET(GF_KMR04_Hammer1Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KMR04_Hammer1Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block), -80, 0, 400, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -230, 60, -140, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -440, 60, 20, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 60, 0, 370, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 85, 0, 395, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 100, 0, -70, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR04_MultiCoinBrick)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 0, 60, 0, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
