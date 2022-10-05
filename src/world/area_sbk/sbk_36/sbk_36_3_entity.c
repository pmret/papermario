#include "sbk_36.h"
#include "entity.h"

EvtScript N(ReadSign) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017A, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), 410, 0, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(ReadSign)))
    EVT_RETURN
    EVT_END
};
