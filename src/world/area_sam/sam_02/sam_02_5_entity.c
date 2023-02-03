#include "sam_02.h"
#include "entity.h"

EvtScript N(EVS_MakeToadHouseGifts) = {
    EVT_IF_EQ(GF_SAM02_MushroomPresents, TRUE)
        EVT_CALL(MakeItemEntity, ITEM_ULTRA_SHROOM, 350, 0, -120, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_UltraShroom)
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 330, 0, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomA)
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 330, 0, -140, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomB)
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 370, 0, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomC)
        EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 370, 0, -140, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomD)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 160, 60, 200, 0, MAKE_ENTITY_END)
    EVT_EXEC(N(EVS_MakeToadHouseGifts))
    EVT_RETURN
    EVT_END
};
