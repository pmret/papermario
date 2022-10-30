#include "flo_24.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -325, 60, -140, 0, ITEM_DIZZY_DIAL, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO24_ItemBlock_DizzyDial)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 325, 60, -140, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO24_HiddenItem_MapleSyrup)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 335, 0, -160, 0, MODEL_o136, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_FLO24_HiddenPanel)
    EVT_RETURN
    EVT_END
};
