#include "dgb_12.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_Chest_Interact) = EVT_OPEN_CHEST_KEY(ITEM_TUBBA_CASTLE_KEY, GF_DGB12_Chest_CastleKey1);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), -225, 0, -245, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_DGB12_Chest_CastleKey1)
    Call(AssignScript, Ref(N(EVS_Chest_Interact)))
    Return
    End
};
