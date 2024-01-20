#include "pra_12.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PDownDUp) = EVT_OPEN_CHEST_BADGE(ITEM_P_DOWN_D_UP, GF_PRA12_Chest_PDownDUp);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 200, 20, 94, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_PRA12_Chest_PDownDUp)
    Call(AssignScript, Ref(N(EVS_OpenChest_PDownDUp)))
    Return
    End
};
