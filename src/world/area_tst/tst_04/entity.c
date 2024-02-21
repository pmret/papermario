#include "tst_04.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_RedSwitch), 0, 0, 300, 0, MAKE_ENTITY_END)
    Return
    End
};
