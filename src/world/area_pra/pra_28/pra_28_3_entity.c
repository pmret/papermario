#include "pra_28.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PUpDDown) = EVT_OPEN_CHEST_BADGE(ITEM_P_UP_D_DOWN, GF_PRA28_Chest_PUpDDown);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 200, 20, 94, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_PRA28_Chest_PUpDDown)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_PUpDDown)))
    EVT_RETURN
    EVT_END
};
