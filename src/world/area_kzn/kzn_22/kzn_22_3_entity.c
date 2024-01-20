#include "kzn_22.h"
#include "entity.h"

EvtScript N(EVS_OpenChest) = {
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 480, 235, 175, 0, 0, MAKE_ENTITY_END)
    Return
    End
};
