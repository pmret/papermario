#include "iwa_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -650, 123, 375, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), -503, 63, 225, 0, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ArrowSign), 825, 170, 115, 0, 90, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_QUAKE_HAMMER, 160, 125, 125, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA01_Item_QuakeHammer)
    EVT_CALL(MakeItemEntity, ITEM_LETTER_TO_MERLON, 410, 140, 135, ITEM_SPAWN_MODE_KEY, GF_IWA01_Item_Letter01)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 45, 10, 60, 0, MODEL_cam2b, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_IWA01_HiddenPanel)
    EVT_RETURN
    EVT_END
};
