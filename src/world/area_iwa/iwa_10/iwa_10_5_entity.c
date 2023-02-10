#include "iwa_10.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_IWA10_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_OnSmashBlock) = {
    EVT_SET(GF_IWA10_Hammer1Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_IWA10_Hammer1Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block_WideZ), -1040, 160, -425, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock)))
    EVT_END_IF
    EVT_MAKE_SUPER_BLOCK(-1350, 220, -210, 0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), -780, 0, -227, -15, 270, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), -1157, 70, -282, 40, 120, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), -901, 185, -555, 0, 120, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -525, 80, 115, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), -730, 275, -510, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
