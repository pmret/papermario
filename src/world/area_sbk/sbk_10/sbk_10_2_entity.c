#include "sbk_10.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 315, 93, 60, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK10_HiddenItem_ThunderRage)
    EVT_RETURN
    EVT_END
};
