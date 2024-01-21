#include "iwa_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -650, 123, 375, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), -503, 63, 225, 0, 90, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_ArrowSign), 825, 170, 115, 0, 90, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_QUAKE_HAMMER, 160, 125, 125, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA01_Item_QuakeHammer)
    Call(MakeItemEntity, ITEM_LETTER_TO_MERLON, 410, 140, 135, ITEM_SPAWN_MODE_KEY, GF_IWA01_Item_Letter01)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 45, 10, 60, 0, MODEL_cam2b, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_IWA01_HiddenPanel)
    Return
    End
};
