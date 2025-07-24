#include "mac_05.h"
#include "entity.h"

EvtScript N(EVS_OnInspect_StreetSign) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_0174, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_OnInspect_Menu) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_016C, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), -150, 60, -375, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), -50, 0, -300, 0, MODEL_o106, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_MAC05_HiddenPanel)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), -490, 130, 160, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_MAC05_MultiCoinBrick)
    BindTrigger(Ref(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    BindTrigger(Ref(N(EVS_OnInspect_Menu)), TRIGGER_WALL_PRESS_A, COLLIDER_o154, 1, 0)
    Return
    End
};
