#include "sam_02.h"
#include "entity.h"

EvtScript N(EVS_MakeToadHouseGifts) = {
    IfEq(GF_SAM02_MushroomPresents, TRUE)
        Call(MakeItemEntity, ITEM_ULTRA_SHROOM, 350, 0, -120, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_UltraShroom)
        Call(MakeItemEntity, ITEM_MUSHROOM, 330, 0, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomA)
        Call(MakeItemEntity, ITEM_MUSHROOM, 330, 0, -140, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomB)
        Call(MakeItemEntity, ITEM_MUSHROOM, 370, 0, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomC)
        Call(MakeItemEntity, ITEM_MUSHROOM, 370, 0, -140, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM02_Item_MushroomD)
    EndIf
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 160, 60, 200, 0, MAKE_ENTITY_END)
    Exec(N(EVS_MakeToadHouseGifts))
    Return
    End
};
