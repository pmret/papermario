#include "mac_05.h"
#include "entity.h"

EvtScript N(EVS_OnInspect_StreetSign) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0174, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnInspect_Menu) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_016C, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -150, 60, -375, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -50, 0, -300, 0, MODEL_o106, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_MAC05_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), -490, 130, 160, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_MAC05_MultiCoinBrick)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInspect_Menu)), TRIGGER_WALL_PRESS_A, COLLIDER_o154, 1, 0)
    EVT_RETURN
    EVT_END
};
