#include "mac_03.h"
#include "entity.h"

EvtScript N(EVS_OnBlast_RailRock) = {
    Set(GF_MAC03_BombedRock, true)
    Return
    End
};

EvtScript N(EVS_ReadSign_LilOInks) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_0175, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_OnInspect_StreetSign) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_0172, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(GetDemoState, LVar0)
    IfEq(LVar0, DEMO_STATE_NONE)
        IfEq(GF_MAC03_BombedRock, false)
            Call(MakeEntity, Ref(Entity_BombableRock), -200, 0, 0, 0, MAKE_ENTITY_END)
            Call(AssignScript, Ref(N(EVS_OnBlast_RailRock)))
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenPanel), 525, 0, 175, 0, MODEL_o11, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_MAC03_HiddenPanel)
    Call(MakeEntity, Ref(Entity_Signpost), 185, 20, -350, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_LilOInks)))
    BindTrigger(Ref(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    Return
    End
};
