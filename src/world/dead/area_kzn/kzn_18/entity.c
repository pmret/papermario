#include "kzn_18.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 250, 250, -225, 0, MODEL_o380, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_KZN18_HiddenPanel)
    Call(MakeEntity, Ref(Entity_SavePoint), -420, 85, -80, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), 350, 310, -250, 0, MAKE_ENTITY_END)
    Return
    End
};
