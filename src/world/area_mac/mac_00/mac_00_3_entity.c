#include "mac_00.h"
#include "entity.h"

EvtScript N(EVS_Inspect_StreetSign) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_016F, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 545, 20, 205, 0, MODEL_o262, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_MAC00_HiddenPanel)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -420, 20, 410, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC00_Item_StarPiece)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    EVT_RETURN
    EVT_END
};
