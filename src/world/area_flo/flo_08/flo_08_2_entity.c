#include "flo_08.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_FLO08_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(-780, 120, -110, 0)
    Call(MakeItemEntity, ITEM_STAR_PIECE, 510, 0, -90, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO08_Item_StarPiece)
    Return
    End
};
