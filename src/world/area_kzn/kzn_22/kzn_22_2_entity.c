#include "kzn_22.h"
#include "entity.h"

EvtScript N(EVS_OpenChest) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 480, 235, 175, 0, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
