#include "omo_10.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -350, 60, 60, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO10_HiddenItem_SuperShroom)
    Call(MakeEntity, Ref(Entity_HeartBlock), 250, 60, 55, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), 150, 60, 55, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 0, 0, 200, 0, MODEL_soto, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OMO10_HiddenPanel)
    Return
    End
};
