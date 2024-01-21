#include "pra_35.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_TripleDip) = EVT_OPEN_CHEST_BADGE(ITEM_TRIPLE_DIP, GF_PRA35_Chest_TripleDip);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 435, 0, -70, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_PRA35_Chest_TripleDip)
    Call(AssignScript, Ref(N(EVS_OpenChest_TripleDip)))
    Return
    End
};
