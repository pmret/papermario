#include "dgb_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -65, 60, -240, 0, MAKE_ENTITY_END)
    Return
    End
};
