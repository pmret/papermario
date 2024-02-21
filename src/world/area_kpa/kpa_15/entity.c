#include "kpa_15.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_CastleKey) = EVT_OPEN_CHEST_KEY(ITEM_BOWSER_CASTLE_KEY, GF_KPA15_Chest_CastleKey2);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 220, 30, -100, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_KPA15_Chest_CastleKey2)
    Call(AssignScript, Ref(N(EVS_OpenChest_CastleKey)))
    Return
    End
};

