#include "hos_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -210, 30, 285, 0, MODEL_o210, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_HOS01_HiddenPanel)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -350, 0, -275, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_HOS01_Item_StarPiece)
    EVT_RETURN
    EVT_END
};
