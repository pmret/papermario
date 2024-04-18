#include "jan_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_LETTER_TO_IGOR, -110, 90, -230, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN01_Item_Letter11)
    Call(MakeEntity, Ref(Entity_BellbellPlant), -375, -3, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -335, 57, -55, 0, ITEM_REPEL_GEL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_JAN01_HiddenItem_RepelGel)
    Call(MakeEntity, Ref(Entity_BellbellPlant), 180, -3, -115, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 140, 57, -85, 0, ITEM_MYSTERY, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_JAN01_HiddenItem_Mystery)
    Call(MakeItemEntity, ITEM_COIN, 340, 100, -90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN01_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, 340, 125, -90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN01_Item_CoinB)
    Call(MakeEntity, Ref(Entity_SpinningFlower), 340, 0, -90, 0, MAKE_ENTITY_END)
    Return
    End
};
