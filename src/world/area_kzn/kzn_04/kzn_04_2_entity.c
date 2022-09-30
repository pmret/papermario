#include "kzn_04.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_KZN04_SuperBlock
#include "world/common/atomic/SuperBlock.inc.c"
#include "world/common/atomic/SuperBlock.data.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), 530, 560, 25, 0, MAKE_ENTITY_END)
    EVT_SETUP_SUPER_BLOCK(SUPER_BLOCK_MAPVAR, SUPER_BLOCK_GAMEFLAG)
    EVT_RETURN
    EVT_END
};
