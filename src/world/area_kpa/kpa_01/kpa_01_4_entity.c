#include "kpa_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 220, 208, -125, 0, ITEM_POW_BLOCK, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA01_ItemBlock_POWBlock)
    EVT_RETURN
    EVT_END
};
