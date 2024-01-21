#include "arn_12.h"
#include "entity.h"

EvtScript N(EVS_ReadSign) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_0183, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), 200, 0, -40, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign)))
    Return
    End
};
