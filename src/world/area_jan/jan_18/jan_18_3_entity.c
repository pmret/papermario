#include "jan_18.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_HAPPY_HEART_B, -230, 460, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN18_Item_HappyHeartB)
    EVT_RETURN
    EVT_END
};
