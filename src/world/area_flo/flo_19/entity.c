#include "flo_19.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_S_JUMP_CHG, -200, 160, -213, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO19_Item_SJumpChg)
    Return
    End
};
