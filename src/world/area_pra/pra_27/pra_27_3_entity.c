#include "pra_27.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PalaceKey) = EVT_OPEN_CHEST_KEY(ITEM_CRYSTAL_PALACE_KEY, GF_PRA27_Chest_PalaceKey);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 200, 20, 94, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_PRA27_Chest_PalaceKey)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_PalaceKey)))
    EVT_RETURN
    EVT_END
};
