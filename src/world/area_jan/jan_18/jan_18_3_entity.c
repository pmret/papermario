#include "jan_18.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_HAPPY_HEART_B, -230, 460, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN18_Item_HappyHeartB)
    Return
    End
};
