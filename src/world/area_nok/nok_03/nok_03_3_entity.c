#include "nok_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_HP_PLUS_B, 218, 64, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK03_Item_HPPlusB)
    EVT_RETURN
    EVT_END
};
