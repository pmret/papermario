#include "dro_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_LETTER_TO_NOMADIMOUSE, -135, 160, -245, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DRO02_Item_Letter08)
    Call(MakeEntity, Ref(Entity_HiddenPanel), 180, 173, -200, 0, MODEL_1_yane, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_DRO02_HiddenPanel)
    Return
    End
};
