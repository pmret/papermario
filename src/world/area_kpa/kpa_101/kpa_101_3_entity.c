#include "kpa_101.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_ULTRA_SHROOM, -100, 20, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA101_Item_UltraShroom)
    Return
    End
};
