#include "omo_08.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -350, 60, 50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 350, 60, 60, 0, ITEM_FIRE_FLOWER, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO08_HiddenItem_FireFlower)
    Call(MakeEntity, Ref(Entity_HiddenPanel), -200, 0, 200, 0, MODEL_soto, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OMO08_HiddenPanel)
    Return
    End
};
