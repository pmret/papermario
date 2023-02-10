#include "kpa_15.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_CastleKey) = EVT_OPEN_CHEST_KEY(ITEM_BOWSER_CASTLE_KEY, GF_KPA15_Chest_CastleKey2);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 220, 30, -100, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_KPA15_Chest_CastleKey2)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_CastleKey)))
    EVT_RETURN
    EVT_END
};

