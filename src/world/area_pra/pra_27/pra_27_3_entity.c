#include "pra_27.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PalaceKey) = EVT_OPEN_CHEST_KEY(ITEM_CRYSTAL_PALACE_KEY, GF_PRA27_Chest_PalaceKey);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 200, 20, 94, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_PRA27_Chest_PalaceKey)
    Call(AssignScript, Ref(N(EVS_OpenChest_PalaceKey)))
    Return
    End
};
