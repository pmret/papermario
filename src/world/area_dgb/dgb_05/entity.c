#include "dgb_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_DGB05_BoardedFloor, false)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 510, -210, 100, 0, MAKE_ENTITY_END)
    EndIf
    Return
    End
};
