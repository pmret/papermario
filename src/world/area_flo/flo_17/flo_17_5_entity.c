#include "flo_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 660, 60, -115, 0, ITEM_THUNDER_RAGE, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_FLO17_HiddenItem_ThunderRage)
    EVT_CALL(MakeItemEntity, ITEM_LETTER_TO_MINH_T, -245, 0, 105, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO17_Item_Letter09)
    EVT_RETURN
    EVT_END
};
