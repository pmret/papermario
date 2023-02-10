#include "kzn_09.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_KZN09_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(130, 480, -75, 0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 350, 350, 55, 0, MODEL_o149, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KZN09_HiddenPanel)
    EVT_RETURN
    EVT_END
};
