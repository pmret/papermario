#include "dgb_12.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_Chest_Interact) = EVT_OPEN_CHEST_KEY(ITEM_TUBBA_CASTLE_KEY, GF_DGB12_Chest_CastleKey1);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), -225, 0, -245, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_DGB12_Chest_CastleKey1)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_Chest_Interact)))
    EVT_RETURN
    EVT_END
};
