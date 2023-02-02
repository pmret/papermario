#include "sam_04.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 40, 0, 400, 0, MODEL_ground, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_SAM04_HiddenPanel)
    EVT_CALL(MakeItemEntity, ITEM_LETTER_TO_MAYOR_PENGUIN, -290, 70, 110, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM04_Item_Letter05)
    EVT_SET(MV_LetterItemID, LVar0)
    EVT_CALL(MakeItemEntity, ITEM_REPEL_GEL, 426, 0, -172, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM04_Item_RepelGel)
    EVT_RETURN
    EVT_END
};
