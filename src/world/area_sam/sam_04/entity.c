#include "sam_04.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 40, 0, 400, 0, MODEL_ground, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_SAM04_HiddenPanel)
    Call(MakeItemEntity, ITEM_LETTER_TO_MAYOR_PENGUIN, -290, 70, 110, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM04_Item_Letter05)
    Set(MV_LetterItemID, LVar0)
    Call(MakeItemEntity, ITEM_REPEL_GEL, 426, 0, -172, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM04_Item_RepelGel)
    Return
    End
};
