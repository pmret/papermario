#include "kzn_09.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MapVar(0)
#define SUPER_BLOCK_GAMEFLAG GF_KZN09_SuperBlock
#include "world/common/atomic/SuperBlock.inc.c"
#include "world/common/atomic/SuperBlock.data.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), 130, 480, -75, 0, MAKE_ENTITY_END)
    EVT_SETUP_SUPER_BLOCK(SUPER_BLOCK_MAPVAR, SUPER_BLOCK_GAMEFLAG)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 350, 350, 55, 0, MODEL_o149, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KZN09_HiddenPanel)
    EVT_RETURN
    EVT_END
};
