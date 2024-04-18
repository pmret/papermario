#include "sbk_10.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 315, 93, 60, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK10_HiddenItem_ThunderRage)
    Return
    End
};
