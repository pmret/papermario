#include "kmr_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 800, 60, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 220, 60, 10, 0, ITEM_CLOSE_CALL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR06_BadgeBlock_CloseCall)
    EVT_RETURN
    EVT_END
};
