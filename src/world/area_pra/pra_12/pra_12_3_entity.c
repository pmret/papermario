#include "pra_12.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PDownDUp) = EVT_OPEN_CHEST_BADGE(ITEM_P_DOWN_D_UP, GF_PRA12_Chest_PDownDUp);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 200, 20, 94, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_PRA12_Chest_PDownDUp)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_PDownDUp)))
    EVT_RETURN
    EVT_END
};
