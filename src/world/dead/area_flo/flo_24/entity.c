#include "flo_24.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -325, 60, -140, 0, ITEM_DIZZY_DIAL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_FLO24_ItemBlock_DizzyDial)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 325, 60, -140, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_FLO24_HiddenItem_MapleSyrup)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 335, 0, -160, 0, MODEL_o136, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_FLO24_HiddenPanel)
    Return
    End
};
