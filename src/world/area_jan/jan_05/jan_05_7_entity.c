#include "jan_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 0, 60, 0, 0, ITEM_POWER_QUAKE, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_JAN05_BadgeBlock_PowerQuake)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_CymbalPlant), 205, 0, 220, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_TrumpetPlant), -386, 0, -214, 160, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
