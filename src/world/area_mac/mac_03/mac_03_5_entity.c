#include "mac_03.h"
#include "entity.h"

EvtScript N(EVS_OnBlast_RailRock) = {
    EVT_SET(GF_MAC03_BombedRock, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReadSign_LilOInks) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0175, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnInspect_StreetSign) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0172, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_EQ(LVar0, DEMO_STATE_NONE)
        EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock), -200, 0, 0, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBlast_RailRock)))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 525, 0, 175, 0, MODEL_o11, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_MAC03_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), 185, 20, -350, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign_LilOInks)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    EVT_RETURN
    EVT_END
};
