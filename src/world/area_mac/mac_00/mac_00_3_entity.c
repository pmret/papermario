#include "mac_00.h"
#include "entity.h"

EvtScript N(EVS_Inspect_StreetSign) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_016F, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 545, 20, 205, 0, MODEL_o262, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_MAC00_HiddenPanel)
    Call(MakeItemEntity, ITEM_STAR_PIECE, -420, 20, 410, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC00_Item_StarPiece)
    BindTrigger(Ref(N(EVS_Inspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    Return
    End
};
