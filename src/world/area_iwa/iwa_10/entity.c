#include "iwa_10.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_IWA10_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_OnSmashBlock) = {
    Set(GF_IWA10_Hammer1Block, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_IWA10_Hammer1Block, false)
        Call(MakeEntity, Ref(Entity_Hammer2BlockWideZ), -1040, 160, -425, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock)))
    EndIf
    EVT_MAKE_SUPER_BLOCK(-1350, 220, -210, 0)
    Call(MakeEntity, Ref(Entity_ArrowSign), -780, 0, -227, -15, 270, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), -1157, 70, -282, 40, 120, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), -901, 185, -555, 0, 120, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), -525, 80, 115, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), -730, 275, -510, 0, MAKE_ENTITY_END)
    Return
    End
};
