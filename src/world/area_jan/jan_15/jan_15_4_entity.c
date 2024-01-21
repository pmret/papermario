#include "jan_15.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_PinkFlower), 385, 0, -75, 10, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 0, 0, 0, 0, MODEL_o87, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_JAN15_HiddenPanel)
    Return
    End
};
