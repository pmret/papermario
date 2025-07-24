#include "obk_05.h"
#include "entity.h"

EvtScript N(EVS_OnSmashFloor) = {
    Set(GF_OBK05_BoardedFloor, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_OBK05_BoardedFloor, false)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 0, 0, 0, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashFloor)))
    EndIf
    Call(MakeEntity, Ref(Entity_WoodenCrate), 200, 0, -100, 0, ITEM_APPLE, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 200, 30, -100, 0, -1, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 165, 0, -100, 0, ITEM_APPLE, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), -105, 0, -55, 0, -1, MAKE_ENTITY_END)
    Return
    End
};
