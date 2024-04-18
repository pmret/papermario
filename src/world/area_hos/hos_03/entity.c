#include "hos_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 200, 60, 275, 0, MAKE_ENTITY_END)
    Call(SetEntityCullMode, 3)
    Return
    End
};
