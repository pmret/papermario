#include "pra_06.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_SHOOTING_STAR, 200, 20, 94, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_PRA06_Item_ShootingStar)
    Return
    End
};
