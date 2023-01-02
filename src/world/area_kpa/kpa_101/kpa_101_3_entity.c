#include "kpa_101.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_ULTRA_SHROOM, -100, 20, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA101_Item_UltraShroom)
    EVT_RETURN
    EVT_END
};
