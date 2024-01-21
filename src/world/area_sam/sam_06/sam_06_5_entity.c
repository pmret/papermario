#include "sam_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -250, 120, 140, 0, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_SNOWMAN_SCARF, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_ScarfItemID, LVar0)
    Return
    End
};
