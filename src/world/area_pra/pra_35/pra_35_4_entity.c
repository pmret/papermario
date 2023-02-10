#include "pra_35.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_TripleDip) = EVT_OPEN_CHEST_BADGE(ITEM_TRIPLE_DIP, GF_PRA35_Chest_TripleDip);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 435, 0, -70, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_PRA35_Chest_TripleDip)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_TripleDip)))
    EVT_RETURN
    EVT_END
};
