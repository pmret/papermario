#include "flo_19.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_S_JUMP_CHG, -200, 160, -213, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO19_Item_SJumpChg)
    EVT_RETURN
    EVT_END
};
