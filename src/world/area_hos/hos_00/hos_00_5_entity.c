#include "hos_00.h"
#include "entity.h"

EvtScript N(EVS_ReadSign_ToSummit) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_016E, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReadSign_ToMerluvlee) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_016D, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), 450, 10, -185, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign_ToSummit)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), 855, -10, -40, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign_ToMerluvlee)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 380, -10, 25, 0, MODEL_o239, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_HOS00_HiddenPanel)
    EVT_RETURN
    EVT_END
};
