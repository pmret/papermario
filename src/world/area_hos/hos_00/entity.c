#include "hos_00.h"
#include "entity.h"

EvtScript N(EVS_ReadSign_ToSummit) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_016E, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_ReadSign_ToMerluvlee) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_016D, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), 450, 10, -185, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_ToSummit)))
    Call(MakeEntity, Ref(Entity_Signpost), 855, -10, -40, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_ToMerluvlee)))
    Call(MakeEntity, Ref(Entity_HiddenPanel), 380, -10, 25, 0, MODEL_o239, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_HOS00_HiddenPanel)
    Return
    End
};
