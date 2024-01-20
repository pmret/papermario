#include "pra_05.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_BlueKey) = EVT_OPEN_CHEST_KEY(ITEM_BLUE_KEY, GF_PRA05_Chest_BlueKey);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 200, 20, 94, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_PRA05_Chest_BlueKey)
    Call(AssignScript, Ref(N(EVS_OpenChest_BlueKey)))
    Return
    End
};
