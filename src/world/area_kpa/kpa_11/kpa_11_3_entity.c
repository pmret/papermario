#include "kpa_11.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 1400, 90, -875, 0, MAKE_ENTITY_END)
    EVT_IF_EQ(GF_KPA11_Defeated_Guard, TRUE)
        EVT_CALL(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, 550, 30, -145, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA11_Item_CastleKey2)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 1400, 90, -375, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA10_ItemBlock_LifeShroom)
    EVT_RETURN
    EVT_END
};
